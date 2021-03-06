#include "sage3basic.h"
#include <iostream>
using namespace std;

#include "CollectionOperators.h"
#include "PropertyState.h"
#include "NumberIntervalLattice.h"
#include "Labeler.h"
#include "VariableIdMapping.h"
#include "IntervalTransferFunctions.h"
#include "AnalysisAbstractionLayer.h"

SPRAY::IntervalTransferFunctions::IntervalTransferFunctions():
  _cppExprEvaluator(0),
  _domain(0)
{
}

SPRAY::IntervalTransferFunctions::~IntervalTransferFunctions() {
  if(_cppExprEvaluator)
    delete _cppExprEvaluator;
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferSwitchCase(Label lab,SgStatement* condStmt, SgCaseOptionStmt* caseStmt,Lattice& pstate) {
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(pstate);
  if(isSgExprStatement(condStmt)) {
    SgExpression* cond=isSgExpression(SgNodeHelper::getExprStmtChild(condStmt));
    ROSE_ASSERT(cond);
    NumberIntervalLattice knownValueIntervalOfSwitchVar;
    /* this varId is only used if the switch-cond is a variable and we can bound the interval of the case numbers to this variable. 
       this varId will only be removed at the end of the function (it only gives better precision if conditionals depend on this variable
       inside the switch-stmt (a rather rare case)
    */
    VariableId varId;
    if(SgVarRefExp* varRefExp=isSgVarRefExp(cond)) {
      // if the switch-cond is a variable set the interval to the case label (this function is called for each case label)
      varId=getVariableIdMapping()->variableId(varRefExp);
      ROSE_ASSERT(varId.isValid());
      knownValueIntervalOfSwitchVar=ips.getVariable(varId);
    } else {
      // the switch-cond is not a variable. We evaluate the expression but do not maintain its interval in a program variable
      knownValueIntervalOfSwitchVar=evalExpression(lab, cond, pstate);
    }
    // handle case NUM:
    SgExpression* caseExpr=caseStmt->get_key();
    ROSE_ASSERT(caseExpr);
    //cout<<"INFO: transferSwitchCase: VAR"<<varRefExp->unparseToString()<<"=="<<caseExpr->unparseToString()<<endl;
    NumberIntervalLattice num;
    SgExpression* caseExprOptionalRangeEnd=caseStmt->get_key_range_end();
    if(caseExprOptionalRangeEnd==0) {
      // case NUM:
      num=evalExpression(lab, caseExpr, pstate);
    } else {
      // case NUM1 ... NUM2:
      NumberIntervalLattice numStart=evalExpression(lab, caseExpr, pstate);;
      NumberIntervalLattice numEnd=evalExpression(lab, caseExprOptionalRangeEnd, pstate);;
      num=NumberIntervalLattice::join(numStart,numEnd);
      //cout<<"DEBUG: range: "<<num.toString()<<endl;
    }
#if 0
    if(SgIntVal* sgIntVal=isSgIntVal(caseExpr)) {
      int val=sgIntVal->get_value();
      num.setLow(val);
      num.setHigh(val);
    }
#endif
    if(!NumberIntervalLattice::haveOverlap(knownValueIntervalOfSwitchVar,num)) {
      //cout<<"INFO: state detected non-reachable."<<endl;
      ips.setBot();
      return;
    }
    if(varId.isValid()) {
      ips.setVariable(varId,num);
    }
  } else {
    cerr<<"Error: switch condition not a SgExprStmt. Unsupported program structure."<<endl;
    exit(1);
  }
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferCondition(Edge edge, Lattice& pstate) {
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(pstate);
  Label lab0=edge.source;
  //Label lab1=edge.target;
  SgNode* node=getLabeler()->getNode(lab0);
  if(isSgExprStatement(node)) {
    node=SgNodeHelper::getExprStmtChild(node);
  }
  if(SgExpression* expr=isSgExpression(node)) {
    NumberIntervalLattice res=evalExpression(lab0,expr,pstate);
    if((res.isTrue() && edge.isType(SPRAY::EDGE_TRUE))
       ||(res.isFalse() && edge.isType(SPRAY::EDGE_FALSE))
       ||(res.isTop())) {
      return;
    } else {
      //cout<<"INFO: detected non-reachable state."<<endl;
      //cout<<"DEBUG: EDGE: "<<edge.toString()<<endl;
      //cout<<"RESULT: "<<res.toString()<<endl;
      ROSE_ASSERT(!res.isBot());
      ROSE_ASSERT((res.isFalse()&&edge.isType(SPRAY::EDGE_TRUE))
                  ||(res.isTrue()&&edge.isType(SPRAY::EDGE_FALSE)));
      // non-reachable state
      ips.setBot();
      return;
    }
  } else {
    cerr<<"Error: interval analysis: unsupported condition type."<<endl;
    exit(1);
  }
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferExpression(Label lab, SgExpression* node, Lattice& pstate) {
  evalExpression(lab,node,pstate); // ignore return value
}

void SPRAY::IntervalTransferFunctions::transferReturnStmtExpr(Label lab, SgExpression* node, Lattice& pstate) {
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(pstate);
  NumberIntervalLattice res=evalExpression(lab,node,pstate);
  VariableId resVarId=getResultVariableId();
  ips.setVariable(resVarId,res);
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
SPRAY::NumberIntervalLattice SPRAY::IntervalTransferFunctions::evalExpression(Label lab, SgExpression* node, Lattice& pstate) {
  //ROSE_ASSERT(getVariableIdMapping()); TODO
  NumberIntervalLattice niLattice;
  //cout<<"TINFO: transferExpression "<<node->unparseToString()<<endl;
  _cppExprEvaluator->setPropertyState(&pstate);
  //cout<<"PSTATE:";pstate.toStream(cout,getVariableIdMapping());cout<<endl;
  niLattice=_cppExprEvaluator->evaluate(node);
  return niLattice;
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferDeclaration(Label lab, SgVariableDeclaration* declnode, Lattice& element) {
  ROSE_ASSERT(this!=0);
  SgInitializedName* node=SgNodeHelper::getInitializedNameOfVariableDeclaration(declnode);
  ROSE_ASSERT(getVariableIdMapping());
  VariableId varId=getVariableIdMapping()->variableId(node);
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(element);
  ips.addVariable(varId);
  SgExpression* initExp=SgNodeHelper::getInitializerExpressionOfVariableDeclaration(declnode);
  if(initExp) {
    //NumberIntervalLattice res=_cppExprEvaluator->evaluate(initExp,ips);
    NumberIntervalLattice res=evalExpression(lab,initExp,ips);
    ROSE_ASSERT(!res.isBot());
    ips.setVariable(varId,res);
  }
}


/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferFunctionCall(Label lab, SgFunctionCallExp* callExp, SgExpressionPtrList& arguments,Lattice& element) {
  int paramNr=0;
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(element);
  for(SgExpressionPtrList::iterator i=arguments.begin();i!=arguments.end();++i) {
    VariableId paramId=getParameterVariableId(paramNr);
    ips.addVariable(paramId);
    ips.setVariable(paramId,evalExpression(lab,*i,ips));
    paramNr++;
  }
}
/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferFunctionCallReturn(Label lab, SgVarRefExp* lhsVar, SgFunctionCallExp* callExp, Lattice& element) {
  IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(element);
  if(isSgCompoundAssignOp(callExp->get_parent())) {
    cerr<<"Error: transferFunctionCallReturn: compound assignment of function call results not supported. Normalization required."<<endl;
    exit(1);
  }
  // determine variable-id of dedivated variable for holding the return value
  VariableId resVarId=getResultVariableId();
  if(lhsVar!=0) {
    //cout<<"DEBUG: updated var=f(...)."<<endl;
    VariableId varId=getVariableIdMapping()->variableId(lhsVar);  
    // set lhs-var to the return-value
    ips.setVariable(varId,ips.getVariable(resVarId));
  }
  // remove the return-variable from the state (the return-variable is temporary)
  ips.removeVariable(resVarId);
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferFunctionEntry(Label lab, SgFunctionDefinition* funDef,SgInitializedNamePtrList& formalParameters, Lattice& element) {
  // generate Intervals for each parameter variable
  int paramNr=0;
  for(SgInitializedNamePtrList::iterator i=formalParameters.begin();
      i!=formalParameters.end();
      ++i) {
    SgInitializedName* formalParameterName=*i;
    VariableId formalParameterVarId=getVariableIdMapping()->variableId(formalParameterName);
    IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(element);
    // get value of actual parameter
    VariableId paramId=getParameterVariableId(paramNr);
    // remove parameter variable
    ips.addVariable(formalParameterVarId);
    ips.setVariable(formalParameterVarId,ips.getVariable(paramId));
    ips.removeVariable(paramId);
    paramNr++;
  }
}

/*! 
  * \author Markus Schordan
  * \date 2015.
 */
void SPRAY::IntervalTransferFunctions::transferFunctionExit(Label lab, SgFunctionDefinition* funDef, VariableIdSet& localVariablesInFunction, Lattice& element) {
  // remove all declared variables at function exit (including function parameter variables)
  for(VariableIdSet::iterator i=localVariablesInFunction.begin();i!=localVariablesInFunction.end();++i) {
    VariableId varId=*i;
    IntervalPropertyState& ips=dynamic_cast<IntervalPropertyState&>(element);
    ips.removeVariable(varId);
  }
}

SPRAY::CppExprEvaluator* SPRAY::IntervalTransferFunctions::getCppExprEvaluator() {
  return _cppExprEvaluator;
}

void SPRAY::IntervalTransferFunctions::setCppExprEvaluator(SPRAY::CppExprEvaluator* expEval) {
  _cppExprEvaluator=expEval;
}

// #include "rose.h"

#include "DependenceGraph.h"
#include <set>


class CreateSliceSet
{
        public:
                CreateSliceSet(SystemDependenceGraph *program,std::list<SgNode*> targets);
                std::set<SgNode*> computeSliceSet();
                std::set<SgNode*> computeSliceSet(SgNode * node);
                std::set<SgNode*> computeForwardSliceSet();
                std::set<SgNode*> computeForwardSliceSet(DependenceNode * depNode);
        protected:
                SystemDependenceGraph *sdg;
                std::list<SgNode*> sliceTargetNodes;
                std::set<DependenceNode*> getSliceDepNodes(std::set <DependenceNode*> searchSet,std::set<DependenceGraph::EdgeType> allowedEdges);
                std::set<DependenceNode*> getForwardSliceDepNodes(std::set <DependenceNode*> searchSet,std::set<DependenceGraph::EdgeType> allowedEdges);
};

include $(top_srcdir)/config/Makefile.for.ROSE.includes.and.libs

## Place generated object files (.o) into the same directory as their source
## files, in order to avoid collisions when non-recursive make is used.
AUTOMAKE_OPTIONS = subdir-objects

#include $(srcdir)/sage_support/Makefile_variables

ROSE_OPTIMIZATION_LEVEL =
# ROSE_VERBOSE = -rose:verbose 2


# Bison flags
AM_YFLAGS = -d -v
# Flex flags
AM_LFLAGS =

CXXFLAGS += $(ROSE_OPTIMIZATION_LEVEL) $(ROSE_VERBOSE) -I$(srcdir)/parser_support -I$(srcdir)

lib_LTLIBRARIES = libroseMatlabFrontend.la

AM_CPPFLAGS = $(ROSE_INCLUDES)
libroseMatlabFrontend_la_DEPENDENCIES =
libroseMatlabFrontend_la_SOURCES = \
	MatlabParser.cc \
	matlab_parse.yy \
	matlab_lex.ll \
	parser_support/comment-list.cc \
	parser_support/error.cc \
	parser_support/input.cc \
	parser_support/ourtoken.cc \
	parser_support/StatementList.cc \
	parser_support/SymbolFinder.cc \
	parser_support/MatlabFunctionBuilder.cc

pkginclude_HEADERS = MatlabParser.h

noinst_HEADERS = \
  parser_support/MatlabFunctionBuilder.h \
  parser_support/StatementList.h \
  parser_support/SymbolFinder.h \
  parser_support/base-list.h \
  parser_support/comment-list.h \
  parser_support/input.h \
  parser_support/lex.h \
  parser_support/octave.gperf.h \
  parser_support/ourtoken.h


clean-local:
	rm -f *.la matlab_*












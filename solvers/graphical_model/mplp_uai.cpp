#include "graphical_model.h"
#include "visitors/standard_visitor.hxx"
using FMC_INST = FMC_MPLP;
LP_MP_CONSTRUCT_SOLVER_WITH_INPUT_AND_VISITOR(FMC_INST, UAIInput::ParseProblem<FMC_INST>, StandardVisitor<ProblemDecomposition<FMC_INST>>);

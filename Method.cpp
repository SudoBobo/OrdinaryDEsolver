#include "Method.h"

Method::Method(Solver & solver, Limiter & limiter, Conditions & conditions)
	:m_solver(solver), m_limiter(limiter), m_conditions(conditions)
{

}


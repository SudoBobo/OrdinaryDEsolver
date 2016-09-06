#include "EulerSystemSolver.h"

EulerSystemSolver::RungeKuttaSystemSolver(Limiter * limiter,
											   Conditions * conditions,
											   SystemMaker * systemMaker)
	:SystemSolver(limiter, conditions, systemMaker)
{

}

double * EulerSystemSolver::uNew(const int k, const int j,
					  const double * uPrev, const double * u,
					  const double * uNext) const
{
	return nullptr;
}

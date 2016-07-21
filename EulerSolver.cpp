#include "EulerSolver.h"

EulerSolver::EulerSolver()
{

}

void EulerSolver::solve(const System & system, std::vector <double> & state,
				  double a, double b, double h, double yInitial)
{
	int nSteps = int((b - a) / h);

	state.reserve(nSteps);
	state.push_back(yInitial);

	for (int i = 1; i < nSteps; i++)
	{
	state[i] = state[i-1] + h * system.computeDerivative((a + (i - 1) * h),state[i-1]);
	}
}

#include "EulerSolver.h"

EulerSolver::EulerSolver(const System & system, State & state,
                         double a, double b, double h,
                         const vector <double> & yInitial) :
                        Solver(system, state, a, b, h, yInitial)
{

}

void EulerSolver::solve()
{

	state(0, 0, currentPosition + 1) = (state(0, 0, currentPosition) +
	             h * system.computeDerivative((a + double(currentPosition) * h),
	                                          state(0, 0, currentPosition)));
	  currentPosition++;
}



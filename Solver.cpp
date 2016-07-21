#include "Solver.h"


Solver::Solver(const System & system, State & state,
			   double a, double b, double h, double yInitial) :
			system(system)
{
	this->a = a;
	this->b = b;
	this->h = h;
	this->yInitial = yInitial;
	this->a = a;
	this->state = state;
}


EulerSolver::solve
{
	  state[i] = state[i-1] +
				 h * system.computeDerivative((a + (i - 1) * h),state[i-1]);
}

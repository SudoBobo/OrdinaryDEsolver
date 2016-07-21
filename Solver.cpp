#include <iostream>
#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, State & state,
			   double a, double b, double h, double yInitial) :
			system(system), state(state)
{
	this->a = a;
	this->b = b;
	this->h = h;
	this->yInitial = yInitial;
	this->a = a;
//	this->state = state;
	this->state(0, 0, 0) = yInitial;
	this->currentPosition = 0;
}

EulerSolver::EulerSolver(const System & system, State & state,
						 double a, double b, double h, double yInitial) :
						Solver(system, state, a, b, h, yInitial)
{

}

void EulerSolver::solve()
{
	  state(0, 0, currentPosition + 1) = (state(0, 0, currentPosition) +
				 h * system.computeDerivative((a + (currentPosition) * h),
											  state(0, 0, currentPosition)));
	  currentPosition++;
}

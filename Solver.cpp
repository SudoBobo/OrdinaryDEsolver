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
				 h * system.computeDerivative((a + double(currentPosition) * h),
											  state(0, 0, currentPosition)));
	  currentPosition++;
}


RungeKuttaSolver::RungeKuttaSolver(const System & system, State & state,
						 double a, double b, double h, double yInitial) :
						 Solver(system, state, a, b, h, yInitial)
{

}

void RungeKuttaSolver::solve()
{
	double arg1;
	double arg2;

	//1
	arg1 = a + double(currentPosition) * h;
	arg2 = state(0,0, currentPosition);

	double kNo1 = system.computeDerivative(arg1, arg2);

	//2
	arg1 = a + double(currentPosition) * h + h/2.0;
	arg2 = state(0, 0, currentPosition) + (h/2.0)*kNo1;

	double kNo2 = system.computeDerivative(arg1, arg2);
	//3

	arg1 = a + double(currentPosition) * h + h/2.0;
	arg2 = state(0, 0, currentPosition) + (h/2.0)*kNo2;

	double kNo3 = system.computeDerivative(arg1, arg2);

	//4
	arg1 = a + double(currentPosition) * h + h;
	arg2 = state(0, 0, currentPosition) + h * kNo3;

	double kNo4 = system.computeDerivative(arg1, arg2);

	state(0, 0, currentPosition + 1) = state(0, 0, currentPosition) +
									   (h/6.0)*(kNo1+ 2.0*kNo2 + 2.0*kNo3+kNo4);

	currentPosition++;


}




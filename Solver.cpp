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

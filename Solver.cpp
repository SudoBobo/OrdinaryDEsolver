#include <iostream>
#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, State & state,
			   double a, double b, double h,
			   const std::vector <double> & yInitial) :
			system(system), state(state), yInitial(yInitial)
{
	this->a = a;
	this->b = b;
	this->h = h;
	for (int j = 0; j < state.jSize(); j++)
		this->state(0, j, 0) = yInitial[j];
	this->currentPosition = 0;
}

#include <iostream>
#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, State & state,
               double a, double b, double h, const vector <double> & yInitial) :
            system(system), state(state)
{
	this->a = a;
	this->b = b;
	this->h = h;
	this->yInitial = yInitial;
	for (int j = 0; j <= state.jMax(); j++)
		this->state(0, j, 0) = yInitial[j];
	this->currentPosition = 0;
}

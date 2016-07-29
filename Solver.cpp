#include <iostream>
#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, std::vector <State> & state,
			   double a, double b, double h, double tau) :
			system(system), state(state)
{
	this->a = a;
	this->b = b;
	this->h = h;
	this->tau = tau;
	this->currentPosition = 0;
}

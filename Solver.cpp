#include <iostream>
#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, State & currentState, State & nextState,
			   double a, double b, double h, double tau) :
			system(system), currentState(currentState), nextState (nextState)
{
	this->a = a;
	this->b = b;
	this->h = h;
	this->tau = tau;
}

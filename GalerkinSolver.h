#ifndef GALERKINSOLVER_H
#define GALERKINSOLVER_H

#include "System.h"
#include "Solver.h"

class GalerkinSolver : public Solver
{
public:
	GalerkinSolver(const System & system, State & currentState, State & nextState,
				double a, double b, double h, double tau);
	void solve();

};

#endif // GALERKINSOLVER_H

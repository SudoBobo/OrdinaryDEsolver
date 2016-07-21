#include <iostream>


#include "Solver.h"


int main()
{
	// for
	double yInitial = 4.0;
	double a = 2.0;
	double b = 10.0;
	double h = 0.01;
	int    nSteps = int((b - a) / h);

	System system;
	State  state(1, 1, nSteps);
	EulerSolver(system, state, a, b, h, yInitial);

	for (int i = 0; i < nSteps; i++) {
	  eulerSolver.solve();
	}

	for (int i = 0; i < nSteps; i++) {
	  std::cout << state(1, 1, i) << std::endl;
	}
	return 0;
}


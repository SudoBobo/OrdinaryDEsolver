#include <iostream>


#include "Solver.h"


int main()
{
	double yInitial = 2.0;
	double a = 2.0;
	double b = 10.0;
	double h = 0.1;
	int    nSteps = int((b - a) / h);

	System system;
	State  state(1, 1, nSteps);
	EulerSolver eulerSolver(system, state, a, b, h, yInitial);

	for (int i = 0; i < nSteps; i++) {

	  eulerSolver.solve();
	  std::cout << "This is what is saved" << state(0,0,i) << std::endl;
	}

//	for (int i = 0; i < nSteps; i++) {
//	  std::cout << state(0, 0, i) << std::endl;
//	}
	return 0;
}


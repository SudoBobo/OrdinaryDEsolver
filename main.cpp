#include <iostream>

#include "Solver.h"
#include "EulerSolver.h"
#include "RungeKuttaSolver.h"

int main()
{
	double yInitial = 2.0;
	double a = 2.0;
	double b = 10.0;
	double h = 0.0001;
	int    nSteps = int((b - a) / h);

	System system;
	State  state(1, 1, nSteps);
	RungeKuttaSolver rungeKuttaSolver(system, state, a, b, h, yInitial);
	EulerSolver eulerSolver (system, state, a, b, h, yInitial);
	for (int i = 0; i < nSteps; i++) {
	//  eulerSolver.solve();
	  rungeKuttaSolver.solve();
	}

	for (int i = 0; i < nSteps; i++) {
	  std::cout << (a + i * h) << "  " << state(0, 0, i) << std::endl;
	}

	return 0;
}

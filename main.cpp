#include <iostream>

#include "Solver.h"
#include "EulerSolver.h"
#include "RungeKuttaSolver.h"

int main()
{
	std::vector <double> yInitial = {0.8, 2.0};

	double a = 0.0;
	double b = 1.0;

	double h = 0.0000001;

	int    nSteps = int((b - a) / h);

	System system;
	State  state(1, 2, nSteps);

	RungeKuttaSolver rungeKuttaSolver(system, state, a, b, h, yInitial);
	//EulerSolver eulerSolver(system, state, a, b, h, yInitial);
	for (int i = 0; i < nSteps; i++) {
	 rungeKuttaSolver.solve();
	  //eulerSolver.solve();
	}

	for (int i = 0; i < nSteps; i++) {
	  std::cout << (a + i * h) << "  y1 = " << state(0, 0, i)
				<< "  y2 = " << state(0, 1, i) << std::endl;
	}

	return 0;
}

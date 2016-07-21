#include <iostream>


#include "EulerSolver.h"


int main()
{
	System system;
	EulerSolver eulerSolver;

	double yInitial = 4.0;
	double a = 2.0;
	double b = 10.0;
	double h = 0.01;
	std::vector <double> state;

	eulerSolver.solve(system, state, a, b, h, yInitial);

	int nSteps = int((b -a ) / h);
	for (int i = 0; i < nSteps; i++)
	{
		std::cout << state[i] << std::endl;
	}
	return 0;
}


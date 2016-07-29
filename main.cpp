#include <iostream>

#include "Solver.h"
//#include "EulerSolver.h"
//#include "RungeKuttaSolver.h"

int main()
{
//	RungeKutta/Euler example
//	std::vector <double> yInitial = {0.8, 2.0};

//	double a = 0.0;
//	double b = 1.0;

//	double h = 0.000001;

//	int    nSteps = int((b - a) / h);

//	System system;
//	State  state(1, 2, nSteps);

//	RungeKuttaSolver rungeKuttaSolver(system, state, a, b, h, yInitial);
//	//EulerSolver eulerSolver(system, state, a, b, h, yInitial);
//	for (int i = 0; i < nSteps; i++) {
//	 rungeKuttaSolver.solve();
//	  //eulerSolver.solve();
//	}

//	for (int i = 0; i < nSteps; i++) {
//	  std::cout << (a + i * h) << "  y1 = " << state(0, 0, i)
//				<< "  y2 = " << state(0, 1, i) << std::endl;
//	}
// Godunov's example

	double a = 0.0;
	double b = 100.0;

	double h = 0.01;
	double tau = 0.01;

	int nSteps = int((b - a) / h);

	System system;
	for (int i = 0; i < nSteps; i++)
	{
			system.rho.push_back(1000);
			system.K.push_back(1000);
			system.c.push_back(sqrt(1000/1000));
	}

	State initialState (nSteps, 2, 1);
	for (int i = 0; i < initialState.iSize(); i++)
	{	if (i < 50)
		{
			initialState(i, 0, 0) = 100.0;
			initialState(i, 1, 0) = 100.0;
		}

		else
		{
			initialState(i, 0, 0) = 50.0;
			initialState(i, 1, 0) = 50.0;
		}
	}

	std::vector <State> state;
	state.push_back(initialState);

//	GodunovSolver godunovSolver (system, state, a, b, h, tau);
//		for (int i = 0; i < nSteps; i++)
//		{
//		 godunovSolver.solve();
//		}

	std::cout << "So far, so good." << std::endl;

	return 0;
}

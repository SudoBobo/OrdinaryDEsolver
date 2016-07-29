//#include "EulerSolver.h"

//EulerSolver::EulerSolver(const System & system, State & state,
//						 double a, double b, double h) :
//						Solver(system, state, a, b, h)
//{

//}

//void EulerSolver::solve()
//{
//	std::vector <double> y = {0.0, 0.0};


//	for (int i = 0; i < state.iSize(); i ++) {
//		for (int j = 0; j < state.jSize(); j++)
//		  y[j] = state(i, j, currentPosition);

//		for (int j = 0; j < state.jSize(); j++) {
//		  state(i, j, currentPosition + 1) = state (i, j, currentPosition) +
//									   h * system.functions[j] (a +
//									   double(currentPosition) * h, y);
//		}

//	}
//	  currentPosition++;
//}



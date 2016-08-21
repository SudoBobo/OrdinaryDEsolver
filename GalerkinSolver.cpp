#include "GalerkinSolver.h"


GalerkinSolver::GalerkinSolver(const System & system,
							 State & currentState,
							 State & nextState,
							 double a, double b, double h, double tau) :
						Solver(system, currentState, nextState, a, b,
							   h, tau)
{

}



void GalerkinSolver::solve()
{

	if (currentState.kSize() == 1)
	{
		// dumb euler
		nextState(0, 0, 0) = currentState(0, 0, 0) +
							 tau * system.duN0(currentState.iSize() - 1,
											   0, 1);

		nextState(currentState.iSize() - 1, 0, 0) =
				currentState(currentState.iSize() - 1, 0, 0) +
				tau *
				system.duN0(currentState.iSize() - 2,
								  currentState.iSize() - 1, 0);

		for (int j = 1; j < currentState.iSize() - 2; j++)
		{
		 nextState(j, 0, 0) = currentState(j, 0, 0) +
							  tau *
							  system.duN0(j - 1, j, j + 1);
		}

		for (int j = 0; j < currentState.iSize(); j++)
		{
		  // numerical value from basis coefs
		  nextState.value(j, 0) = nextState(j, 0, 0) * 1.0;
		}
	}


}


//void limiterMUSCL (State & state)
//{
//	for (int j = 0; j < state.iSize(); j++)
//	{

//	}
//}

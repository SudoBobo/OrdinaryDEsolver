//#include "GodunovSolver.h"


//GodunovSolver::GodunovSolver(const System & system, State & currentState,
//							 State & nextState,
//							 double a, double b, double h, double tau) :
//						Solver(system, currentState, nextState, a, b, h, tau)
//{
//	iSize = currentState.iSize();
//	tx = tau/h;


//}

//void GodunovSolver::solve()
//{


//// расчитаем "потоки" для всех клеток на данном временном слое

//	aMinusP.assign(iSize, 0.0);
//	aPlusP.assign(iSize, 0.0);
//	aMinusU.assign(iSize, 0.0);
//	aPlusU.assign(iSize, 0.0);

//	deltaQN1 = currentState(0, 0, 0) -
//			currentState(iSize - 1, 0, 0);

//	deltaQN2 = currentState(0, 1, 0) -
//			currentState(iSize - 1, 1, 0);

//	alphaN1 = (-1.0 * deltaQN1/system.rho[0] +
//			  system.c[0] * deltaQN2) /
//			  (system.c[iSize - 1]/system.rho[0] +
//			  system.c[0]/system.rho[iSize - 1]);

//	alphaN2 = (-1.0 * deltaQN1 / system.rho[iSize - 1] +
//			  system.c[iSize - 1] * deltaQN2) /
//			 (system.c[iSize - 1]/system.rho[0] +
//			  system.c[0]/system.rho[iSize - 1]);
//	//for P
//	wN1[0] = alphaN1 * system.c[iSize - 1] * (-1.0);
//	//for u
//	wN1[1] = alphaN1 / system.rho[iSize - 1];

//	wN2[0] = alphaN2 * system.c[0];
//	wN2[1] = alphaN2 / system.rho[0];

//	lambdaN1 = -1.0 * system.c[iSize - 1];
//	lambdaN2 = system.c[0];

//	aMinusP[0] = lambdaN1 * wN1[0];
//	aMinusU[0] = lambdaN1 * wN1[1];

//	aPlusP[0] = lambdaN2 * wN2[0];
//	aPlusU[0] = lambdaN2 * wN2[1];

//	for (int i = 1; i < iSize; i++)
//	{
//		deltaQN1 = currentState(i, 0, 0) -
//				currentState(i-1, 0, 0);

//		deltaQN2 = currentState(i, 1, 0) -
//				currentState(i-1, 1, 0);

//		alphaN1 = (-1.0 * deltaQN1/system.rho[i] +
//				  system.c[i] * deltaQN2) /
//				  (system.c[i-1]/system.rho[i] +
//				  system.c[i]/system.rho[i-1]);

//		alphaN2 = (-1.0 * deltaQN1 / system.rho[i-1] +
//				  system.c[i-1] * deltaQN2) /
//				 (system.c[i-1]/system.rho[i] +
//				  system.c[i]/system.rho[i-1]);
//		//for P
//		wN1[0] = alphaN1 * system.c[i-1] * (-1.0);
//		//for u
//		wN1[1] = alphaN1 / system.rho[i-1];

//		wN2[0] = alphaN2 * system.c[i];
//		wN2[1] = alphaN2 / system.rho[i];

//		lambdaN1 = -1.0 * system.c[i-1];
//		lambdaN2 = system.c[i];

//		aMinusP[i] = lambdaN1 * wN1[0];
//		aMinusU[i] = lambdaN1 * wN1[1];

//		aPlusP[i] = lambdaN2 * wN2[0];
//		aPlusU[i] = lambdaN2 * wN2[1];

//	}


//	nextState ((iSize - 1), 0, 0) = currentState(iSize - 1, 0, 0) -
//			tx * (aPlusP[iSize - 1] + aMinusP[0]);
//	nextState(iSize - 1, 1, 0) = currentState(iSize - 1, 1, 0) -
//			tx * (aPlusU[iSize - 1] + aMinusU[0]);


//	for (int i = 0; i < iSize - 1 ; i++)
//	{
//		nextState(i, 0, 0) = currentState(i, 0,		0) -
//				tx * (aPlusP[i] + aMinusP[i+1]);
//		nextState(i, 1, 0) = currentState(i, 1, 0) -
//				tx * (aPlusU[i] + aMinusU[i+1]);
//	}


////	nextState((iSize - 1), 0, 0) = currentState(0, 0, 0) + 1;

////		for (int i = 0; i < iSize - 1 ; i++)
////	{
////			nextState(i, 0, 0) = currentState(i, 0, 0) + 1;
////		}
//}




#include <iostream>
#include <cmath>

#include <Conditions.h>
#include "State.h"
#include "Problem.h"
#include "SystemMaker.h"
#include "GalerkinSystemMaker.h"
#include "Limiter.h"
#include "MUSCLLimiter.h"
#include "Stream.h"
#include "GodunovStream.h"
#include "SystemSolver.h"
#include "RungeKuttaSystemSolver.h"

int main ()
{
	const double a = 0.0;
	const double b = 520.0;
	const double spatialStep = 1;
	const int spatialSteps = static_cast <int>(std::floor((b - a) / spatialStep));

	const double T = 100.0;
	const double courantNumber = 0.1;
	//?
	const double velocityMagnitude = 1.0;
	const double timeStep  = (courantNumber * spatialStep) / velocityMagnitude;

	Conditions conditions(spatialStep, timeStep);
	Problem problem;

	const int k = 2;

	//Streams
	GodunovStream godunovStream(& problem);
	EOStream EOstream(& problem);
	LFStream LFstream(& problem);
	LLFstream LLFstream (&problem);
	RStream Rstream (& problem);

	GalerkinSystemMaker galerkinSystemMaker(&problem, &conditions,
											&godunovStream, k);

	//TVDM limiters
	MUSCLLimiter MUSCLLimiter(&conditions);
	LimiterN2 limiterN2 (& conditions);
	LimiterN3 limiterN3 (& conditions);

	//TVBM limiters

	MUSCLLimiterBM MUSCLlimiterBM(& conditions);
	LimiterN2BM limitrN2BM  (&conditions);
	LimiterN3BM limiterN3BM (&conditions);

	RungeKuttaSystemSolver rungeKuttaSystemSolver(&MUSCLLimiter, &conditions,
												  &galerkinSystemMaker);
	//Initial States
	//Cheeke
	//Breeke

//	Solver solver (&rungeKuttaSystemSolver, &conditions, a, b, T);

//	///inside the solver:
//	/// writer.setNumericalSolutionSource(...);
//	/// etc for error and analytical
//	///


//	for (int t = 0; t < timeSteps; t++)
//	{
//		solver.makeGNUplots;
//		solver.write();
//		// writes numerical solution, analytic solution and error
//		solver.solve();
//	}

	State s(2, 2, 2, &conditions);
	for (int i = 0; i < s.iSize(); i++)
	{
		for (int j = 0; j < s.jSize(); j++ )
		{
			for (int k = 0; k < s.kSize(); k++)
			{
				s(i, j, k) = 5;
			}
		}
	}
	State s1 = s;
	State s2 = s1 + s;

	for (int i = 0; i < s.iSize(); i++)
	{
		for (int j = 0; j < s.jSize(); j++ )
		{
			for (int k = 0; k < s.kSize(); k++)
			{
				std::cout << s2(i, j, k) << std::endl;
			}
		}
	}
	return 0;
}

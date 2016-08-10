#include <iostream>
#include <cmath>

#include "Writer.h"
#include "Solver.h"
#include "GodunovSolver.h"
#include "GalerkinSolver.h"
//#include "EulerSolver.h"
//#include "RungeKuttaSolver.h"


double triangle (double lN1, double lN2, double x, double t);
double rectangle (double lN1, double lN2, double x, double t);

void limiterMUSCL (State & state);
void computeError (State & error, State & currentState,
				   State & currentAnalyticState);

int main()
{
	// стоит ли так сделать с остальными аргуметнами?

	double a   = 0.0;
	double b   = 520.0;
	double h   = 0.1;

	int nSpatialSteps =  static_cast <int> ((b - a) / h);

	double T   = 1000.0;
	//!!!
	double courantNumber = 1.0;
	double tau = courantNumber;

	int nTimeSteps = static_cast <int> (T / tau);


	const int nVariables = 1;
	const int methodRang = 0;
	const int precision  = 2;
	std::vector <int> gridSize = {520, 0, 0};

	// make it with classes and/or lambda functions
	State  initialState(nSpatialSteps, nVariables, methodRang + 1);

	double lN1 = 0.0;
	double lN2 = 20.0;
	double t = 0;
	double x;
	for (int i = 0; i < nSpatialSteps; i++)
	{
		x = i * h;
		initialState(i, 0, 0) = triangle(lN1, lN2, x, t);
	}

	//?

	State  currentState(nSpatialSteps, nVariables, methodRang + 1);
	currentState = initialState;
	State  nextState(nSpatialSteps, nVariables, methodRang + 1);

	State  currentAnalyticState(nSpatialSteps, nVariables, 1);
	currentAnalyticState = initialState;

	State  error (nSpatialSteps, nVariables, 1);


	Writer dataWriter(currentState, "part0_", "file",
					  "/home/bobo/galerkin/galerkinData/",
				 precision, gridSize);

	Writer analyticWriter(currentAnalyticState, "part0_", "file",
						  "/home/bobo/galerkin/galerkinAnalytic/",
				 precision, gridSize);

	Writer errorWriter(error, "part0_", "file", "/home/bobo/galerkin/galerkinError/",
				 precision, gridSize);

	dataWriter.clean();
	errorWriter.clean();
	analyticWriter.clean();
	System system(currentState, h);
	GalerkinSolver galerkinSolver (system, currentState, nextState, a, b, h,
								   tau);

	for (int i = 0; i < nTimeSteps - 1; i++)
	{
	  computeError(error, currentState, currentAnalyticState);

	  errorWriter.write(t);
	  dataWriter.write(t);
	  analyticWriter.write(t);

	   galerkinSolver.solve();
	  for (int j = 0; j < nSpatialSteps; j++)
	  {
		nextState.value(j, 0) = nextState(j, 0, 0) * 1.0;
	  }
		//limiterMUSCL(nextState);
		currentState = nextState;

	  for (int j = 0; j < nSpatialSteps; j++)
	  {
		  x = j * h;
		  t = i * tau;
		  currentAnalyticState(j, 0, 0) = triangle(lN1, lN2, x, t);
	  }
	}
	return 0;
}

double triangle (double lN1, double lN2, double x, double t)
{
	//?

	if (( 0.0 <= t) && (t <= (0.5 * (lN2 - lN1))))
	{
		if ((lN1 <= x) && (x <= (0.5 * (lN1 + lN2) + t)))
			return (2 * (x - lN1)) / (lN2 - lN1 + 2.0 * t);

		if (((0.5 * (lN1 + lN2) + t) < x) && ( x <= lN2))
			return (2 * (lN2 - x)) / (lN2 - lN1 - 2.0 * t);

		if (!((lN1 <= x) && (x <= lN2)))
			return 0.0;
	}

	if (( 0.5 * (lN2 - lN1)) < t)
	{
		if ((lN1 <= x) && (x <= sqrt(0.5 * (lN2 - lN1) * (lN2 - lN1 + 2.0 * t))))
			return ((2.0 * (x - lN1))/(lN2 - lN1 + 2.0 * t));
		return 0.0;
	}

	return 0;
}

double rectangle (double lN1, double lN2, double x, double t)
{
	if (t == 0)
	{
		std::cout << "O" << std::endl;
		if ((lN1 <= x) && (x <= lN2))
			return 1.0;
		if (!((lN1 <= x) && (x <= lN2)))
			return 0.0;
	}

	if (( 0.0 < t) && (t <= (2.0 * (lN2 - lN1))))
	{

		if ((lN1 <= x) && (x <= (lN1 + t)))
			return (x - lN1) / t;

		if (((lN1 + t) <= x) && (x <= (lN2 + 0.5 * t)))
			return 1.0;

		if (!((lN1 <= x) && (x <= lN2 + 0.5 * t)))
			return 0.0;
	}

	if ((2.0 * (lN2 - lN1)) < t)
	{

		if ((x <= lN1) && (x <= (lN1 + sqrt(2.0 * (lN2 - lN1) * t))))
			return (x - lN1) / t;

		if (!((x <= lN1) && (x <= (lN1 + sqrt(2.0 * (lN2 - lN1) * t)))))
			return 0.0;
	}

}

void limiterMUSCL(State & state)
{

}

void computeError (State & error, State & currentState,
				   State & currentAnalyticState)
{
	for (int i = 0; i < error.iSize(); i++)
	{
		error.value(i, 0) = currentAnalyticState.value(i, 0) -
							currentState.value(i, 0);
	}
}



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

//	double a    = 0.0;
//	double b    = 100.0;
//	double time = 0.01;

//	std::vector <int> gridSize = {10, 1, 1};

//	double rho = 1.225;
//	double c   = 300.0;
//	double K   = c * c * rho;

//	double courantNumber = 1;

//	int nPeriods = 1;

//	double h   = 0.01;
//	double tau = (courantNumber * h) / c ;

//	int nSteps    = int((b - a) / h);
//	int timeSteps = int (time/tau);

//	System system;

//	for (int i = 0; i < nSteps; i++)
//	{
//	  system.rho.push_back(rho);
//	  system.K.  push_back(K);
//	  system.c.  push_back(c);
//	}


//	State initialState (nSteps, 2, 1);
//	for (int i = 0; i < initialState.iSize(); i++)
//	{
//	  initialState(i, 0, 0) =  sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) * system.c[i];
//	  initialState(i, 1, 0) =  sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) / system.rho[i];
//	}

//	State currentState = initialState;
//	State nextState (nSteps, 2, 1);

//	GodunovSolver godunovSolver (system, currentState, nextState, a, b, h, tau);
//	Writer writer (currentState, "part0_", "file", "/home/bobo/data/", 2, gridSize);
//	writer.clean();
//	for (int t = 0; t < timeSteps - 1; t++)
//	{
//	  writer.write(t);
//	  godunovSolver.solve();
//	  currentState = nextState;
//	}

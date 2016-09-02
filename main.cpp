#include <iostream>
#include <cmath>

#include "GodunovStream.h"
#include "Writer.h"
#include "Solver.h"
#include "GalerkinSolver.h"
#include "MUSCLLimiter.h"
#include "Conditions.h"
#include "RungeKuttaMethod.h"


double triangle (double lN1, double lN2, double x, double t);
double u0Triangle(double x, int l, double h, double lN1, double lN2);
double rectangle (double lN1, double lN2, double x, double t);

void limiterMUSCL (State & state);
void computeError (State & error, State & currentState,
				   State & currentAnalyticState);

int main()
{
	std::cout << "dick" << std::endl;
	// посмотри, где можно сделать корткие синомимиы typedef'ом
	// или auto
	// n-ый порядок апроксимации
	// можно и 1-ый
	// чем быстрее делаешь, тем лучше
	//  Эйлеры 3-его, на наследовании
	//  Большая модульность частей
	//
	//  gnu plot класс рисователь
	//  файл на 32 картинки для отладки
	//  стоит ли так сделать с остальными аргуметнами?
	//  не стоит расчитывать на масштабирование паравью
	//  нулевой порядок точности - 1 единица данных = 1 единица геометрии
	//  первый порядок точности - 1 единица данных = 2 едницы геометрии
	//  интеграл считается аналитически т.к. там везде полиномы (т.е. можно
	// взять первообразную
	//  автономное задание базиса
	//  начальные условия через интеграл 2.4
	// Чтобы можно было видеть градиент

	double a   = 0.0;
	double b   = 520.0;
	double h   = 1;
	int nSpatialSteps =  static_cast <int> ((b - a) / h);

	double T   = 100.0;
	double y = 1.0;
	double courantNumber = 0.1;
	double tau = (courantNumber * h) / y;
	int nTimeSteps = static_cast <int> (T / tau);

	Conditions conditions(h, tau);



	const int nVariables = 1;
	const int spatialOrder = 1;
	const int precision  = 10;

	int xGridSize = nSpatialSteps; // * (methodRang + 1);
	std::vector <int> gridSize = {xGridSize, 0, 0};

	// make it with classes and/or lambda functions
	State initialState(nSpatialSteps, nVariables, spatialOrder + 1, conditions);

	const double lN1 = 0.0;
	const double lN2 = 20.0;

	for (int i = 0; i < nSpatialSteps; i++)
	{
		static double x;
		x = i * h;
		for (int k = 0; k < spatialOrder + 1; k++)
		{
			initialState(i, 0, k) = u0Triangle(x, k, h, lN1, lN2);
		}
	}

	State currentState (initialState);
	State  nextState(nSpatialSteps, nVariables, spatialOrder + 1, conditions);

	State  currentAnalyticState(nSpatialSteps, nVariables, 1, conditions);
	State  error               (nSpatialSteps, nVariables, 1, conditions);


	Writer dataWriter(currentState, "part0_", "file",
					  "/home/bobo/galerkin/galerkinData/",
				 precision, gridSize, conditions);

	Writer analyticWriter(currentAnalyticState, "part0_", "file",
						  "/home/bobo/galerkin/galerkinAnalytic/",
				 precision, gridSize, conditions);

//	Writer errorWriter(error, "part0_", "file", "/home/bobo/galerkin/galerkinError/",
//				 precision, gridSize);

	dataWriter.clean();
//	errorWriter.clean();
	analyticWriter.clean();

	System system;
	GodunovStream godunovStream(system);

	GalerkinSolver galerkinSolver (system, currentState, nextState,
								   godunovStream, a, b, conditions);

	MUSCLLimiter MUSCLlimiter (galerkinSolver.tempState(), conditions);

	RungeKuttaMethod rungeKuttaMethod (galerkinSolver, MUSCLlimiter, conditions);


	galerkinSolver.changeMethod(& rungeKuttaMethod);

	for (int i = 0; i < nTimeSteps - 1; i++)
	{
	  dataWriter.GNUplot(i);
//	  computeError(error, currentState, currentAnalyticState);

//	  errorWriter.write(i);
	  dataWriter.write(i);
	  analyticWriter.write(i);

	   galerkinSolver.solve();
	   currentState = nextState;

	  for (int j = 0; j < nSpatialSteps; j++)
	  {
		  static double x;
		  static double t;
		  x = j * h;
		  t = i * tau;
		  currentAnalyticState(j, 0, 0) = triangle(lN1, lN2, x, t);
	  }
	}
//	std::cout << "Test" << std::endl;
//	Conditions conditions (1, 0.1);
//	State state1(2, 1, 2, conditions);
//	State state2(2, 1, 2, conditions);
//	State state3(2, 1, 2, conditions);
//	State tempState = state1;

////	state1(0, 0, 0) = 1 ;
////	state2(0 , 0, 0 ) = 3;


////	state1( 0,  0,  1) = 10;
////	state2( 0, 0 , 1 ) = 30;


////	state1(1 , 0 ,  0) = 2;
////	state2(1, 0 ,  0) = 4;


////	state1(1 , 0 ,  1) = 20 ;
////	state2( 1, 0 ,  1) = 40 ;

////	state3 = state1 + state2;
////	state3 = state3 * 1000;

////	std::cout << "State3" << " " << state3(0 , 0 , 0) << " " << state3(0, 0, 1) << " " <<
////				   state3(1, 0, 0) << " " << state3(1, 0, 1) << std::flush <<std::endl;
	return 0;
}

double triangle (double lN1, double lN2, double x, double t)
{
	if (t == 0)
	{

	}
	if (( 0.0 < t) && (t <= (0.5 * (lN2 - lN1))))
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
	//throw std::range_error("triangle error");
}

double u0Triangle(double x, int l, double h, double lN1, double lN2)
{
	static double intervalN1;
	static double intervalN2;

	intervalN1 = 0.0;
	intervalN2 = 0.0;

	static double middle = 0.5 * (lN2 +lN1);

	static double xPrev;
	static double xNext;

	xPrev = x - h;
	xNext = x + h;

	switch (l)
	{
	case 0:

		if ((lN1 <= xPrev) && (xNext <= middle))
		{
			intervalN1 = ((2.0) / (h * (lN2 - lN1))) *
						 (
						 xNext * (xNext / 2.0 - lN1) -
						 xPrev * (xPrev / 2.0 - lN1)
						 );
			intervalN2 = 0.0;
		break;
		}

		if ((xPrev <= middle) && (middle <= xNext))
		{
			intervalN1 = ((2.0) / (h * (lN2 - lN1))) *
						 (
						 lN1 * (lN1 / 2.0 - lN1) -
						 xPrev * (xPrev / 2.0 - lN1)
						 );
			intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
						 (
						 xNext * (lN2 - xNext / 2.0) -
						 lN1 * (lN2 - lN1 / 2.0)
						 );
			break;
		}

		if ((middle <= xPrev) && (xNext <= lN2))
		{
			intervalN1 = 0.0;
			intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
						 (
						 xNext * (lN2 - xNext / 2.0) -
						 xPrev * (lN2 - xPrev / 2.0)
						 );
			break;
		}

		if ((xPrev <= lN2) && (lN2 < xNext))
		{
			intervalN1 = 0.0;
			intervalN2 = ((2.0) / (h * (lN2 - lN1))) *
						 (
						 lN2 * (lN2 - lN2 / 2.0) -
						 xPrev * (lN2 - xPrev / 2.0)
						 );
			break;
		}

		if (lN2 < xPrev)
		{
			intervalN1 = 0.0;
			intervalN2 = 0.0;
			break;
		}

	case 1:
		if ((lN1 <= xPrev) && (xNext <= middle))
		{
			intervalN1 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
						 (
						 (xNext * xNext) * (xNext / 3.0 - lN1 / 2.0) -
						 (xPrev * xPrev) * (xPrev / 3.0 - lN1 / 2.0)
						 );
			intervalN2 = 0.0;
		break;
		}

		if ((xPrev <= middle) && (middle <= xNext))
		{
			intervalN1 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
						 (
						 (lN2 * lN2) * (lN2 / 3.0 - lN1 / 2.0) -
						 (xPrev * xPrev) * (xPrev / 3.0 - lN1 / 2.0)
						 );
			intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
						 (
						 (xNext * xNext) * (lN2 / 2.0 - xNext / 3.0) -
						 (lN1 * lN1) * (lN2 / 2.0 - lN1 / 3.0)
						 );
			break;
		}

		if ((middle <= xPrev) && (xNext <= lN2))
		{
			intervalN1 = 0.0;
			intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
						 (
						 (xNext * xNext) * (lN2 / 2.0 - xNext / 3.0) -
						 (xPrev * xPrev) * (lN2 / 2.0 - xPrev / 3.0)
						 );
			break;
		}

		if ((xPrev <= lN2) && (lN2 < xNext))
		{
			intervalN1 = 0.0;
			intervalN2 = (2.0 * (6.0) / (h * (lN2 - lN1))) *
						 (
						 (lN2 * lN2) * (lN2 / 2.0 - lN2 / 3.0) -
						 (xPrev * xPrev) * (lN2 / 2.0 - xPrev / 3.0)
						 );
			break;
		}

		if (lN2 < xPrev)
		{
			intervalN1 = 0.0;
			intervalN2 = 0.0;
			break;
		}
	}

	return intervalN1 + intervalN2;
}

double rectangle (double lN1, double lN2, double x, double t)
{
	if (t == 0.0)
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



//void computeError (State & error, State & currentState,
//				   State & currentAnalyticState)
//{
//	for (int i = 0; i < error.iSize(); i++)
//	{
//		error.value(i, 0) = currentAnalyticState.value(i, 0) -
//							currentState.value(i, 0);
//	}
//}



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

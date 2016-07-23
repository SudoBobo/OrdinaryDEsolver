#include "RungeKuttaSolver.h"

RungeKuttaSolver::RungeKuttaSolver(const System & system, State & state,
						 double a, double b, double h,
								   const std:: vector <double> & yInitial) :
						 Solver(system, state, a, b, h, yInitial)
{

}

void RungeKuttaSolver::solve()
{
	double arg1;
	double arg2;

	for (int i = 0; i < state.iSize(); i ++) {
		for (int j = 0; j < state.jSize(); j++)
		  y[j] = state(i, j, currentPosition);
		for (int j = 0; j < state.jSize(); j++){


		//1
		arg1 = a + double(currentPosition) * h;
		arg2 = state(i, j, currentPosition);

		double kNo1 = system.computeDerivative(arg1, arg2);

		//2
		arg1 = a + double(currentPosition) * h + h/2.0;
		arg2 = state(i, j, currentPosition) + (h/2.0)*kNo1;

		double kNo2 = system.computeDerivative(arg1, arg2);
		//3

		arg1 = a + double(currentPosition) * h + h/2.0;
		arg2 = state(i, j, currentPosition) + (h/2.0)*kNo2;

		double kNo3 = system.computeDerivative(arg1, arg2);

		//4
		arg1 = a + double(currentPosition) * h + h;
		arg2 = state(i, j, currentPosition) + h * kNo3;

		double kNo4 = system.computeDerivative(arg1, arg2);

		state(i, j, currentPosition + 1) = state(i, j, currentPosition) +
										   (h/6.0)*(kNo1+ 2.0*kNo2 + 2.0*kNo3+kNo4);
		}
	currentPosition++;
}

//#include "RungeKuttaSolver.h"

//RungeKuttaSolver::RungeKuttaSolver(const System & system, State & state,
//						 double a, double b, double h) :
//						 Solver(system, state, a, b, h)
//{

//}

//void RungeKuttaSolver::solve()
//{
//	double arg1;
//	std::vector <double> arg2;
//	std::vector <double> y = {0.0, 0.0};

//	for (int i = 0; i < state.iSize(); i ++) {
//		for (int j = 0; j < state.jSize(); j++)
//		  y[j] = state(i, j, currentPosition);
//		for (int j = 0; j < state.jSize(); j++){


//		//1
//		arg1 = a + double(currentPosition) * h;
//		arg2 = y;

//		double kNo1 = system.functions[j](arg1, arg2);

//		//2
//		arg1 = a + double(currentPosition) * h + h/2.0;
//		for (int i = 0; i < arg2.size() ; i++)
//			arg2[i]+= (h/2.0)*kNo1;

//		//arg2 = state(i, j, currentPosition) + (h/2.0)*kNo1;

//		double kNo2 = system.functions[j](arg1, arg2);
//		//3

//		arg1 = a + double(currentPosition) * h + h/2.0;
//		for (int i = 0; i < arg2.size() ; i++)
//			arg2[i]+=(h/2.0)*kNo2;

//		//arg2 = state(i, j, currentPosition) + (h/2.0)*kNo2;

//		double kNo3 = system.functions[j](arg1, arg2);

//		//4
//		arg1 = a + double(currentPosition) * h + h;
//		for (int i = 0; i < arg2.size() ; i++)
//			arg2[i]+= h * kNo3;

//		//arg2 = state(i, j, currentPosition) + h * kNo3;

//		double kNo4 = system.functions[j](arg1, arg2);

//		state(i, j, currentPosition + 1) = state(i, j, currentPosition) +
//										   (h/6.0)*(kNo1+ 2.0*kNo2 + 2.0*kNo3+kNo4);
//		}
//	}
//	currentPosition++;
//}

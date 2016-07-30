#ifndef GODUNOVSOLVER_H
#define GODUNOVSOLVER_H


#include "Solver.h"

class GodunovSolver : public Solver
{
public:
	void solve();
	GodunovSolver(const System & system, std::vector<State> & state,
							 double a, double b, double h, double tau);
protected:
	int    iSize;
	double alphaN1;
	double alphaN2;
	double wN1 [2];
	double wN2 [2];
	double lambdaN1;
	double lambdaN2;
	double deltaQN1;
	double deltaQN2;
	double tx; //t/h from (12)
	std::vector <double> aMinusP;
	std::vector <double> aPlusP;
	std::vector <double> aMinusU;
	std::vector <double> aPlusU;
};

#endif // GODUNOVSOLVER_H

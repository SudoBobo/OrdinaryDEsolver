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
	int iSize;
	double alphaN1;
	double alphaN2;
	double wN1 [2];
	double wN2 [2];
	std::vector <double[2]> aMinus;
	std::vector <double[2]> aPlus;
	double qNext [2];
};

#endif // GODUNOVSOLVER_H

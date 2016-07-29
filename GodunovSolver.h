#ifndef GODUNOVSOLVER_H
#define GODUNOVSOLVER_H


#include "Solver.h"

class GodunovSolver : public Solver
{
public:
	void solve();
	GodunovSolver(const System & system, std::vector<State> & state,
							 double a, double b, double h);
};

#endif // GODUNOVSOLVER_H

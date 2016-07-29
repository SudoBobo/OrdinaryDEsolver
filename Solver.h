#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include "System.h"
#include "State.h"

class Solver
{
public:
	virtual void solve() = 0;
	virtual	~Solver();
	Solver(const System & system, std::vector <State> & state,
				double a, double b, double h, double tau);

protected:
	double                       a, b, h, tau;
	int                          currentPosition;
	const System &               system;
	std::vector <State> &                      state;
};

#endif // SOLVER_H

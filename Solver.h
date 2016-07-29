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
				double a, double b, double h);

protected:
	double                       a, b, h;
	int                          currentPosition;
	const System &               system;
	std::vector <State> &                      state;
};

#endif // SOLVER_H

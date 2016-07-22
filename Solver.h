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
	Solver(const System & system, State & state,
	            double a, double b, double h,
	            const std::vector <double> & yInitial);

protected:
	double                       a, b, h;
	const std::vector <double> & yInitial;
	int                          currentPosition;
	const System &               system;
	State &                      state;
};

#endif // SOLVER_H

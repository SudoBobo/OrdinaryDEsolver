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
				double a, double b, double h, double yInitial);

protected:
	double            a, b, h, yInitial;
	int            currentPosition;
	const System & system;
	State &        state;
};

class EulerSolver : public Solver
{
public:
	void solve();
	EulerSolver(const System & system, State & state,
							 double a, double b, double h, double yInitial);
};

class RungeKuttaSolver : public Solver
{
public:
	void solve();
	RungeKuttaSolver(const System & system, State & state,
							 double a, double b, double h, double yInitial);
};




#endif // SOLVER_H

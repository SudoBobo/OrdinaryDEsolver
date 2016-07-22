#ifndef RUNGEKUTTASOLVER_H
#define RUNGEKUTTASOLVER_H

#include "Solver.h"

class RungeKuttaSolver : public Solver
{
public:
	void solve();
	RungeKuttaSolver(const System & system, State & state,
							 double a, double b, double h, double yInitial);
};

#endif // RUNGEKUTTASOLVER_H

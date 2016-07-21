#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include "System.h"
#include "State.h"

class Solver
{
public:
	virtual void solve() const;
	void Solver(const System & system, std::vector <double> & state,
				double a, double b, double h, double yInitial);

protected:
	int            a, b, h, yInitial;
	State &        state;
	const System & system;
};

class EulerSolver : public Solver
{
	void solve() const;


};

//class RungeKuttaSolver : public Solver
//{
//	void solve() const;
//};




#endif // SOLVER_H

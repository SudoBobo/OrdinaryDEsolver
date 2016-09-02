#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include "System.h"
#include "State.h"
#include "Stream.h"
#include "Conditions.h"
#include "GodunovStream.h"

//checked

class Solver
{
public:
	virtual void solve() = 0;
	virtual double dU(int l, int jPrevious, int j, int jNext) = 0;
	virtual	~Solver();
	Solver(const System & system, const State & currentState, State & nextState,
				double a, double b, Conditions & conditions);
	int spatialOrder() const;
	const State & currentState() const;
	State & nextState ();
	State & tempState();
protected:
	double                       m_a, m_b;

	const System &               m_system;
	const State &                m_currentState;
	State &                      m_nextState;
	State                        m_tempState;
	Conditions &                 m_conditions;
};

#endif // SOLVER_H

#include <iostream>
#include <exception>
#include <stdexcept>

#include "Solver.h"


Solver::~Solver()
{

}

Solver::Solver(const System & system, const State & currentState, State & nextState,
			   double a, double b, Conditions & conditions) :
			m_system(system), m_currentState(currentState),
			m_nextState (nextState), m_tempState(m_currentState),
		  m_conditions(conditions)
{
	m_a = a;
	m_b = b;
}

int Solver::spatialOrder() const
{
	return m_currentState.spatialOrder();
}

const State & Solver::currentState() const
{
	return m_currentState;
}

State & Solver::tempState()
{
	return m_tempState;
}

State & Solver::nextState()
{
	return m_nextState;
}

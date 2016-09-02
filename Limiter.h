#ifndef LIMITER_H
#define LIMITER_H

#include "State.h"
#include "Conditions.h"

//checked
class Limiter
{
public:
	Limiter(State & originalState, Conditions & conditions);
	// vDx = численному значению производной по х в точке j
	virtual void operator ()(int jPrevious, int j, int jNext, double vDx) = 0;
	virtual void limit() = 0;
	void merge();
protected:
	State & m_originalState;
	Conditions & m_conditions;
	int m_numberOfCalls;
	State m_newState;
};

#endif // LIMITER_H

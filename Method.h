#ifndef METHOD_H
#define METHOD_H

#include "Conditions.h"
#include "Solver.h"
#include "Limiter.h"

//checked
class Method
{
public:
	virtual void calculateNext () = 0;
	Method (Solver & solver, Limiter & limiter, Conditions & conditions);
protected:
	Solver &     m_solver;
	Limiter &    m_limiter;
	Conditions & m_conditions;

};

#endif // METHOD_H

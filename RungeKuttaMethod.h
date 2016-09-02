#ifndef RUNGEKUTTAMETHOD_H
#define RUNGEKUTTAMETHOD_H

#include "Method.h"

//checked
class RungeKuttaMethod: public Method
{
public:
	RungeKuttaMethod(Solver & solver, Limiter & limiter, Conditions & Conditions);
	void calculateNext();
private:

};

#endif // RUNGEKUTTAMETHOD_H

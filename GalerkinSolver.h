#ifndef GALERKINSOLVER_H
#define GALERKINSOLVER_H

#include "System.h"
#include "Solver.h"
#include "Conditions.h"
#include "Method.h"

//checked
class GalerkinSolver : public Solver
{
public:
	GalerkinSolver(const System & system, const State & currentState, State & nextState,
				   Stream & stream, double a, double b, Conditions & conditions);

	double dU (int l, int jPrevious, int j, int jNext);
	void solve();
	void changeMethod(Method * newMethod);
protected:
	Polynomial expr;
	// classes below must have uniformed interface
	Method *               m_method;
	Stream &               m_stream;
//	Basis &                basis;
};

#endif // GALERKINSOLVER_H

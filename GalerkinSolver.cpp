#include "GalerkinSolver.h"
#include "MyMath.h"
#include "RungeKuttaMethod.h"

#include <iostream>
GalerkinSolver::GalerkinSolver(const System & system,
							   const State & currentState, State & nextState,
							   Stream &  stream,  double a, double b,
							   Conditions & conditions)
:Solver(system, currentState, nextState, a, b, conditions), m_stream(stream)
{

}

void GalerkinSolver::solve()
{
		// получаем разностную схему, используя функцию из системы
		// решаем её некоторым методом
		// метод конструируется с определённым лимитером
			m_method->calculateNext();
}

double GalerkinSolver::dU(int l, int jPrevious, int j, int jNext )
{
	static double xJ;
	static double xJnext;
	static double xJprev;
	static double xJminus;
	static double xJplus;
	static double integral;
	static const double m_h = m_conditions.getH();
	return m_tempState.value(j, 0) * m_tempState.value(j, 0);
//	xJ =     j * m_h;
//	xJnext = jNext * m_h;
//	xJprev = jPrevious * m_h;
//	xJminus = (xJ + xJprev) / 2.0;
//	xJplus = (xJ + xJnext) / 2.0;
////	std::cout << xJ << " " << xJnext << " " << xJprev << std::endl;
//		// !!!
//		integral = integral24(m_tempState(j, 0), l, m_tempState.spatialOrder(),
//												  xJminus, xJplus,
//							  m_conditions.getH());
////		std::cout << integral << std::endl;
//		// поток в точке x(j+1/2)
//		// uA = предельное значение слева, то есть значение в точке x(j)
//		// uB = предельное значение справа, то есть значение в точке x(j+1)
//		return ((2.0 * l + 1.0) / m_h) *
//				(
//				   (integral) - (m_stream(m_tempState.value(j,0),
//										  m_tempState.value(jNext, 0)) -
//						std::pow(-1.0, l) *
//						m_stream(m_tempState.value(jPrevious, 0),
//								 m_tempState.value(j, 0)))
//				);

}

void GalerkinSolver::changeMethod(Method * newMethod)
{
		m_method = newMethod;
}

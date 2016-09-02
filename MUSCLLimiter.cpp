#include "MUSCLLimiter.h"
#include "MyMath.h"

#include <exception>
#include <stdexcept>

MUSCLLimiter::MUSCLLimiter(State & originalState, Conditions & conditions)
	: Limiter (originalState, conditions)
{
	if (m_originalState.spatialOrder() == 1)
	{
		//it's ok
	}
	else
		throw std::range_error("no use MUSCL limiter with non-linear apr");
}
void MUSCLLimiter::operator ()(int jPrevious, int j, int jNext, double vDx)
{
	// may be mistake
//	static double b;
//	static double c;
//	static double m_h = m_conditions.getH();

//	// можно сделать иначе
//	// ню джитое представить не как число, а как набор коэффициентов
//	b = ((m_originalState.value(jNext, 0) - m_originalState.value(j, 0)) / m_h);
//	c = ((m_originalState.value(j, 0) -
//		  m_originalState.value(jPrevious, 0)) / m_h);

//	m_newState(j, 0, 0) = m_originalState.value(j, 0) - (j * m_h) * m(b, c);
//	m_newState(j, 0, 1) = m(b,c);

////	 m_newState(j, 0, 0) = m_originalState(j, 0, 0);
////	 m_newState(j, 0, 1) = m_originalState(j, 0, 1);

//	m_numberOfCalls ++;
}

void MUSCLLimiter::limit()
{
//	static const double vDx = 666;
//	static int iSize = m_originalState.iSize();
//	this->operator ()(iSize - 1, 0, 1, vDx);
//	this->operator ()(iSize - 2, iSize - 1, 0, vDx);
//	for (int i = 1; i < iSize - 1; i++)
//	{
//		this->operator()(i - 1, i, i + 1, vDx);
//	}
//	this->merge();
}

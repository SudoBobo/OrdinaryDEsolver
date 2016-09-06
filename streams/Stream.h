#ifndef STREAM_H
#define STREAM_H

#include "Problem.h"

class Stream
{
public:
	Stream(Problem * problem);
	virtual double operator()(const double uA, const double uB) const = 0;
	// поток в точке x(j+1/2)
	// uA = предельное значение слева, то есть значение в точке x(j)
	// uB = предельное значение справа, то есть значение в точке x(j+1)
protected:
	Problem * m_problem;
};

#endif // STREAM_H

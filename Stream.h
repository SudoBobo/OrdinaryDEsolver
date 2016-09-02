#ifndef STREAM_H
#define STREAM_H

#include <algorithm>
#include "System.h"

class Stream
{
public:
	Stream(System & system);
	virtual double operator()(double uA, double uB) = 0;
	// поток в точке x(j+1/2)
	// uA = предельное значение слева, то есть значение в точке x(j)
	// uB = предельное значение справа, то есть значение в точке x(j+1)
protected:
	System & m_system;
};

#endif // STREAM_H

#ifndef LIMITER_H
#define LIMITER_H

#include "Conditions.h"

class Limiter
{
public:
	Limiter(Conditions * conditions);
//	/ limit(coef j-1, coef j, coef j+1)
protected:
	Conditions * m_conditions;
};

#endif // LIMITER_H

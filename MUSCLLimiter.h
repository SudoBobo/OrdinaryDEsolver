#ifndef MUSCLLIMITER_H
#define MUSCLLIMITER_H

#include "Limiter.h"
//сhecked
class MUSCLLimiter: public Limiter
{
public:
	MUSCLLimiter(State & originalState, Conditions & conditions);
	void operator ()(int jPrevious, int j, int jNext, double vDx);
	void limit();
};

#endif // MUSCLLIMITER_H

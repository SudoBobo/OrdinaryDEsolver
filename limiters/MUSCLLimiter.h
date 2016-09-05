#ifndef MUSCLLIMITER_H
#define MUSCLLIMITER_H

#include "Limiter.h"

class MUSCLLimiter: public Limiter
{
public:
	MUSCLLimiter(Conditions * conditions);
};

#endif // MUSCLLIMITER_H

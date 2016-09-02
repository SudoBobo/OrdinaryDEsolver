#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <cmath>
#include <algorithm>

#include <Polynomial.h>
#include "State.h"

class System
{
public:
	System ();
	System (const System &);

	double f(double u);
//	Polynomial f(std::vector <double> coefficients);
};
#endif // SYSTEM_H

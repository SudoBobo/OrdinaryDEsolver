#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <cmath>

class System
{
public:
	double computeDerivativeNo0 (double t, const std::vector <double> & y) const;
	double computeDerivativeNo1 (double t, const std::vector <double> & y) const;
};

#endif // SYSTEM_H

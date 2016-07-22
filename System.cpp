#include "System.h"

double System::computeDerivativeNo0 (double t, const std::vector <double> y) const
{
	return y[1];
}

double System::computeDerivativeNo1 (double t, const std::vector <double> y) const
{
	return exp(-1.0 * t * y[0]);
}

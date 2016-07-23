#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <cmath>

class System
{
protected:
	int nEquations = 2;
public:
	System();
	static double computeDerivativeNo0 (double t,
										 std::vector <double> & y);
	static double computeDerivativeNo1 (double t,
										 std::vector <double> & y);
	std::vector <double (*) (double, std::vector<double> &) > functions;
};
#endif // SYSTEM_H

#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <cmath>
#include <algorithm>

#include "State.h"

class System
{
protected:
	State & m_currentState;
	const double m_h;
public:
//	System();
//	static double computeDerivativeNo0 (double t,
//										 std::vector <double> & y);
//	static double computeDerivativeNo1 (double t,
//										 std::vector <double> & y);
//	std::vector <double (*) (double, std::vector<double> &) > functions;
	System (State & currentState, double h);
	double duN0 (int previousJ, int currentJ, int nextJ) const;

};
#endif // SYSTEM_H

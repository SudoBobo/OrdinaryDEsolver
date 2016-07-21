#ifndef EULERSOLVER_H
#define EULERSOLVER_H

#include "System.h"
#include <vector>
class EulerSolver
{
public:
	EulerSolver();
	void solve(const System & system, std::vector <double> & state,
				  double a, double b, double h, double yInitial);
private:

};

#endif // EULERSOLVER_H

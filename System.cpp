#include "System.h"

//System::System()
//{
//	functions.push_back(this->computeDerivativeNo0);
//	functions.push_back(this->computeDerivativeNo1);
//}



//double System::computeDerivativeNo0 (double t,
//									  std::vector<double> & y)
//{
//	return y[1];
//}

//double System::computeDerivativeNo1 (double t,
//									  std::vector<double> & y)
//{
//	return exp(-1.0 * t * y[0]);
//}

//double System::computeDerivativeNo0 (double t,
//									  std::vector<double> & y)
//{
//	return y[1];
//}

//double System::computeDerivativeNo1 (double t,
//									  std::vector<double> & y)
//{
//	return cos(3.0 * t) - 4.0 * y[0];
//}

System::System(State & currentState, double h):
	m_currentState(currentState), m_h(h)
{

}

// typical arguments are u[j] and u[j+1] aka state.value(j,0)
// and state.value(j+1, 0)
double godunovStream(double a, double b);

double System::duN0(int previousJ, int currentJ, int nextJ) const
{


	return  -1.0 * (godunovStream(m_currentState.value(currentJ, 0),
						   m_currentState.value(nextJ, 0)) -
			 godunovStream(m_currentState.value(previousJ, 0),
						   m_currentState.value(currentJ, 0)));
}

double godunovStream(double a, double b)
{
	if (a <= b)
		return std::min((a * a / 2.0), (b * b / 2.0));
	if (b < a)
		return std::max((a * a / 2.0), (b * b / 2.0));
}

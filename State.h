#ifndef STATE_H
#define STATE_H

#include <exception>
#include <stdexcept>

class State
{
public:
	//uniform structure constructor
	State(int iMax, int jMax, int kMax);


	double   operator()  (int i, int j, int k) const;
	double & operator()  (int i, int j, int k);

	int iMax() const;
	int jMax() const;
	int kMax() const;

private:
	double *** m_state;
	int        m_iMax, m_jMax, m_kMax;

};

#endif // STATE_H

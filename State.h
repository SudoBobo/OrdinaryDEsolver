#ifndef STATE_H
#define STATE_H

#include <exception>
#include <stdexcept>

class State
{
public:
	//uniform structure constructor
	State(int iSize, int jSize, int kSize);
	State(const State & anotherState);

	double   operator()  (int i, int j, int k) const;
	double & operator()  (int i, int j, int k);

//? what does this return type mean?
	State & operator =(const State & anotherState);

	int iSize() const;
	int jSize() const;
	int kSize() const;

private:
	double *** m_state;
	int        m_iSize, m_jSize, m_kSize;

};

#endif // STATE_H

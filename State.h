#ifndef STATE_H
#define STATE_H

#include <Conditions.h>

//checked
class State
{
public:
	// i == pointN, j == valueN, k == basisFunctionN
	State(int iSize, int jSize, int kSize, Conditions & conditions );
	~State();
	State(const State & anotherState);
	State operator +(const State & anotherState) const;
	State operator *(double coefficient) const;
	double     operator ()  (int i, int j, int k) const;
	const double *   operator ()  (int i, int j) const;
	double & operator()  (int i, int j, int k);
	// double * вызов верхушки

	void calculateValues ();
	double value   (int i, int j) const;
	double & value (int i, int j);
	Conditions & getConditions() const;

//? what does this return type mean?
	State & operator = (const State & anotherState);

	int iSize() const;
	int jSize() const;
	int kSize() const;

	int spatialOrder() const;

private:
	int        m_iSize, m_jSize, m_kSize;
	Conditions & m_conditions;
	double *** m_state;
	double **  m_value;
};

#endif // STATE_H

#include "State.h"




State::State(int iMax, int jMax, int kMax)
{
	this->m_iMax = iMax;
	this->m_jMax = jMax;
	this->m_kMax = kMax;

	m_state = new double** [m_iMax];
	for (int i = 0; i < m_iMax; i++) {
		  m_state[i] = new double* [m_jMax];
		  for (int j = 0; j < m_jMax; j++) {
			  m_state[i][j] = new double[m_kMax];
		  }
	}

}

double State::operator()(int i, int j, int k) const
{
	if((i > m_iMax) || (j > m_jMax) || (k > m_kMax) ||(i < 0)||(j<0)
																	||(k <0))
		throw std::range_error("Try to get an access to point that doesn't exist");

	return m_state[i][j][k];
}

double & State::operator()(int i, int j, int k)
{
	if((i > m_iMax) || (j > m_jMax) || (k > m_kMax) || (i <0)||(j <0)
																	 || (k<0))
		throw std::range_error("Try to get an access to point that doesn't exist");

	return m_state[i][j][k];
}


int State::iMax() const
{
	return m_iMax;
}

int State::jMax() const
{
	return m_jMax;
}

int State::kMax() const
{
	return m_kMax;
}

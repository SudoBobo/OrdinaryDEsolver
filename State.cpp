#include "State.h"




State::State(int iSize, int jSize, int kSize)
{
	this->m_iSize = iSize;
	this->m_jSize = jSize;
	this->m_kSize = kSize;

	m_state = new double** [m_iSize];
	for (int i = 0; i < m_iSize; i++) {
		  m_state[i] = new double* [m_jSize];
		  for (int j = 0; j < m_jSize; j++) {
			  m_state[i][j] = new double[m_kSize];
		  }
	}

}

double State::operator()(int i, int j, int k) const
{
	if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) ||(i < 0)||(j<0)
																	||(k <0))
		throw std::range_error("Try to get an access to point that doesn't exist");

	return m_state[i][j][k];
}

double & State::operator()(int i, int j, int k)
{
	if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) || (i <0)||(j <0)
																	 || (k<0))
		throw std::range_error("Try to get an access to point that doesn't exist");

	return m_state[i][j][k];
}


int State::iSize() const
{
	return m_iSize;
}

int State::jSize() const
{
	return m_jSize;
}

int State::kSize() const
{
	return m_kSize;
}

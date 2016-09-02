#include "State.h"

#include <exception>
#include <stdexcept>


State::State(int iSize, int jSize, int kSize, Conditions & conditions)
	: m_conditions(conditions)
{
		this->m_iSize = iSize;
		this->m_jSize = jSize;
		this->m_kSize = kSize;

		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_state[i][j] = new double[m_kSize];
				  }
		}

		m_value = new double* [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_value[i] = new double [m_jSize];
		}

}

State::State(const State & anotherState)
	: m_conditions(anotherState.getConditions())
{
		this->m_iSize = anotherState.iSize();
		this->m_jSize = anotherState.jSize();
		this->m_kSize = anotherState.kSize();

		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_state[i][j] = new double[m_kSize];
						  for (int k = 0; k < m_kSize; k++)
						  {
								  m_state[i][j][k] = anotherState(i, j, k);
						  }
				  }
		}

		m_value = new double* [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_value[i] = new double [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_value[i][j] = anotherState.value(i, j);
				  }
		}
}

State::~State()
{
	for (int i = 0; i < m_iSize; i++)
	{
			  for (int j = 0; j < m_jSize; j++)
			  {
					  delete [] m_state[i][j];
			  }
			  delete [] m_state[i];
	}
	delete [] m_state;
}
double State::operator()(int i, int j, int k) const
{
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) ||(i < 0)||(j<0)
																																		||(k <0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

const double * State::operator()(int i, int j) const
{
		if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j];
}

double & State::operator()(int i, int j, int k)
{
		if((i > m_iSize) || (j > m_jSize) || (k > m_kSize) || (i <0)||(j <0)
																																		 || (k<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_state[i][j][k];
}

State & State:: operator =(const State & anotherState)
{
		if (this == &anotherState)
		{
			return *this;
		}

		for (int i = 0; i < m_iSize; i++){
				for (int j = 0; j < m_jSize; j++){
						delete [] m_state[i][j];
				}
				delete [] m_state[i];
		}
		delete [] m_state;

		this->m_iSize = anotherState.iSize();
		this->m_jSize = anotherState.jSize();
		this->m_kSize = anotherState.kSize();



		m_state = new double** [m_iSize];
		for (int i = 0; i < m_iSize; i++) {
				  m_state[i] = new double* [m_jSize];
				  for (int j = 0; j < m_jSize; j++) {
						  m_state[i][j] = new double[m_kSize];
						  for (int k = 0; k < m_kSize; k++) {
								  m_state[i][j][k] = anotherState(i, j, k);
						  }
				  }
		}

		m_value = new double* [m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
				  m_value[i] = new double [m_jSize];
				  for (int j = 0; j < m_jSize; j++)
				  {
						  m_value[i][j] = anotherState.value(i, j);
				  }
		}

		return *this;
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

int State::spatialOrder() const
{
		return m_kSize - 1;
}

double State::value (int i, int j) const
{
		if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
				throw std::range_error("Try to get an access to point that doesn't exist");

		return m_value[i][j];
}

double & State::value (int i, int j)
{
				if((i > m_iSize) || (j > m_jSize) ||(i < 0)||(j<0))
						throw std::range_error("Try to get an access to point that doesn't exist");

				return m_value[i][j];
}

void State::calculateValues()
{
		if (m_kSize == 2)
		{
				for (int i = 0; i < m_iSize; i++)
				{
						  for (int j = 0; j < m_jSize; j++)
						  {
								m_value[i][j] = m_state[i][j][0] +
												(i * m_conditions.getH())
												* m_state[i][j][1];
						  }
				}
		}

		if (m_kSize == 1)
		{
			for (int i = 0; i < m_iSize; i++)
			{
					  for (int j = 0; j < m_jSize; j++)
					  {
							m_value[i][j] = m_state[i][j][0];
					  }
			}
		}
}
\
State State::operator +(const State & anotherState) const
{
		State temp(m_iSize, m_jSize, m_kSize, m_conditions);
		for (int i = 0; i < m_iSize; i++)
		{
				  for (int j = 0; j < m_jSize; j++)
				  {
						  for (int k = 0; k < m_kSize; k++)
						  {
								  temp(i, j, k) = m_state[i][j][k] + anotherState(i, j, k);
						  }
				  }
		}
		return temp;
}

State State::operator *(double coefficient) const
{
		State temp(m_iSize, m_jSize, m_kSize, m_conditions);
		for (int i = 0; i < m_iSize; i++)
		{
				  for (int j = 0; j < m_jSize; j++)
				  {
						  for (int k = 0; k < m_kSize; k++)
						  {
								  temp(i, j, k) = m_state[i][j][k] * coefficient;
						  }
				  }
		}
		return temp;
}

Conditions & State::getConditions() const
{
	return m_conditions;
}

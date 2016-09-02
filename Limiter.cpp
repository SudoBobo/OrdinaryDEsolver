#include "Limiter.h"

#include <exception>
#include <stdexcept>

Limiter::Limiter(State & originalState, Conditions & conditions)
	: m_originalState(originalState),
	  m_conditions(conditions),
	  m_newState (originalState.iSize(),
	  originalState.jSize(),
				  originalState.kSize(), conditions)
{
	m_numberOfCalls = 0;
}


void Limiter::merge()
{
	if (m_numberOfCalls == m_originalState.iSize())
	{
		m_originalState = m_newState;
		m_numberOfCalls = 0;
	}
	else
	{
		throw std::range_error("An attempt to merge before finishing calc");
	}
}


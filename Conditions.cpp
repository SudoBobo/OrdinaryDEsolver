#include "Conditions.h"

Conditions::Conditions(double h, double tau)
{
	m_h = h;
	m_tau = tau;
}

Conditions::Conditions(const Conditions & anotherConditions)
{
	m_h   = anotherConditions.getH();
	m_tau = anotherConditions.getTau();

}

double Conditions::getH() const
{
	return m_h;
}

double Conditions::getTau() const
{
	return m_tau;
}

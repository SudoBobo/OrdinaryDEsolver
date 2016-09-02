#ifndef CONDITIONS_H
#define CONDITIONS_H

//checked

class Conditions
{
public:
	Conditions(double h, double tau);
	Conditions(const Conditions & anotherConditions);
	double getH() const;
	double getTau() const;

private:
	double m_h;
	double m_tau;
};

#endif // CONDITIONS_H

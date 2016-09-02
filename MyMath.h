#ifndef MYMATH
#define MYMATH
#include <vector>
#include <Polynomial.h>
#include <cmath>

//checked

// m - function from limiter definition from article
//http://keldysh.ru/papers/2005/prep105/prep2005_105.html
double m(double a, double b);
double m (double a, double b, double c);
double m(double a, double b, double c, double d);
double mTilda (double a, double b, double c);
int sgn (double val);
//Polynomial legendrePolynomials (int l);
//Polynomial <double> legedrePolynomialsDerivative (int l);
double integral24 (const double * coefficients, int l, int k, double a, double b,
				   double h);
#endif // MYMATH


#include <exception>
#include <stdexcept>

#include "MyMath.h"



//Polynomial legendrePolynomials(int l)
//{
//	// вычислить один раз, потом просто возращать
//	Polynomial temp(l+1);
//	//?
//	switch(l)
//	{
//	case 0:
//		{
//			temp[0] = 1.0;
//			return temp;
//			break;
//		}
//	case 1:
//		{

//		}
//	case 2:
//		{

//		}
//	case 3:
//		{

//		}
//	case 4:
//		{

//		}
//	case 5:
//		{

//		}
//	case 6:
//		{

//		}
//	case 7:
//		{

//		}
//	case 8:
//		{

//		}
//	case 9:
//		{

//		}
//	case 10:
//		{

//		}
//	default:
//		{

//		}
//	}

//	// захардкодить до десятого
//}

//Polynomial legedrePolynomialsDerivative(int l)
//{
//	// Захардкодить до десятого

//}


double integral24 (const double * coefficients, int l, int k, double a, double b,
				   double h)
{
	// coefficients.size() - 1 = число базисных функций
	// l - номер коэф. для которого расчитываем приращение (см. 2.3)

	switch(k)
	{

	case 0:
		return 0.0;
	case 1:
		switch(l)
		{
			case 0:
				return 0.0;
			case 1:
				return	(
						(coefficients[0] * coefficients[0] *(b - a)) +
			(coefficients[0] * coefficients[1] * (b*b - a*a)) +
			((coefficients[1] * coefficients[1] / 3.0) * (b*b*b - a*a*a))
						) / h;
		}
//	case 2:
//		switch(l)
//		{
//		case 0:
//			return 0.0;
//		case 1:
//			return (
//						// wrong! miss coeff[2]
////					(coefficients[0] * coefficients[0] *(b - a)) +
////			(coefficients[0] * coefficients[1] * (b*b - a*a)) +
////			((coefficients[1] * coefficients[1] / 3.0) * (b*b*b))
////					) / h;
//						);
//		case 2:
//// a^2+2 a b x+6 a c x^2-2 a c+b^2 x^2+6 b c x^3-2 b c x+9 c^2 x^4-6 c^2 x^2+c^2
//// here comes the mistake
//// phi(l) != P_l(x)
//// phi(l) == 0.5 * P_l(x-x_j)
//			return    0.5 * ((coefficients[0] * coefficients[0])             +
//					  (2.0 * coefficients[0] * coefficients[1]  * (b-a))     +
//					  (6.0 * coefficients[0] * coefficients[2] *(b*b - a*a)) -
//					  (2.0 * coefficients[0] * coefficients[2])              +
//					  (coefficients[1] * coefficients[1] * (b*b - a*a))      +
//					  (6.0 * coefficients[1]*coefficients[2]*(b*b*b - a*a*a))-
//					  (2.0 * coefficients[1] * coefficients[2] * (b - a))    +
//			(9.0 * coefficients[2] * coefficients[2] * (pow(b,4) - pow(a,4)))-
//					  (6.0 * coefficients[2] * coefficients[2] * (b*b - a*a))+
//					  (coefficients[2] * coefficients[2]));
//		}
	default:
		throw std::range_error("unexpected case in integral24 function");
	}

}

double m (double a, double b)
{
	if (sgn(a) == sgn(b))
	{
		return sgn(a) * (std::min(std::abs(a), std::abs(b)));
	}
	else
	{
		return 0.0;
	}
}

double m(double a, double b, double c)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::abs(c));
	}
	else
	{
		return 0.0;
	}
}

double m(double a, double b, double c, double d)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)) && (sgn(c) == sgn(d)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::min(std::abs(c), std::abs(d)));
	}
	else
	{
		return 0.0;
	}
}



//??
double mTilda(double a, double b, double c)
{
	if ((sgn(a) == sgn(b)) && (sgn(b) == sgn(c)))
	{
		return sgn(a) * std::min(std::min(std::abs(a), std::abs(b)),
								 std::abs(c));
	}
	else
	{
		return 0.0;
	}
}
int sgn (double val)
{
	return ((0.0 < val) - (val < 0.0));
}

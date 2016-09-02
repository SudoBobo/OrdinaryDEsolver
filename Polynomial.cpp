//#include "Polynomial.h"


//Polynomial & Polynomial::operator = (const Polynomial & another)
//{
//	coefficients = another;
//}

//Polynomial::Polynomial(size_t size): coefficients(size)
//{

//}

//double Polynomial::operator [] (int i) const
//{
//	return coefficients[i];
//}

//void Polynomial::resize(size_t newSize)
//{
//	coefficients.resize(newSize);
//}

//size_t Polynomial::size() const
//{
//	return coefficients.size();
//}

//Polynomial Polynomial::operator + (const Polynomial & another) const
//{
//	const size_t thisSize = coefficients.size();
//	const size_t anotherSize = another.size();
//	if (thisSize <= anotherSize)
//	{
//		Polynomial temp = another;

//		for (int i = 0; i < thisSize; i++)
//		{
//			temp += coefficients[i];
//		}
//	}
//	else
//	{
//		Polynomial temp = *this;

//		for (int i = 0; i < anotherSize; i++)
//		{
//			temp += another[i];
//		}
//	}

//	return temp;
//}

//Polynomial Polynomial::operator * (const Polynomial & another) const
//{

//	const size_t tempSize = (coefficients.size() + another.size() - 2);
//	Polynomial temp(tempSize);


//	return temp;
//}

//double Polynomial::integrate (double a, double b) const
//{
//	Polynomial temp = *this;

//	// размер вектора = число базисных функций = порядок точности + 1
//	// т.к. когда раскладываем по одной функции - то это нулевой порядок
//	// по двум {1, x} - первый, и т.д.

//	size_t size = coefficients.size();
//	temp.resize(size);

//	double sum;

//	for (int i = 1; i < size; i++)
//	{
//		temp[i] = temp [i - 1] / i;
//		sum += (temp[i] * (std::pow(b, i) - std::pow(a, i)));
//	}

//	return sum;
//	// Не всё там лишь только где
//}

//double Polynomial::integral24 (int l, double a, double b) const
//{
//	// coefficients.size() - 1 = число базисных функций
//	// l - номер коэф. для которого расчитываем приращение (см. 2.3)

//	switch(coefficients.size() - 1)

//	case(0):
//	{
//		return 0.0;
//		break;
//	}

//	case(1):
//	{
//		switch(l)
//		case(0):
//			return 0.0;
//		case(1):
//			return 0.5 * (coefficients[0] * coefficients[0] *(b - a)) +
//			(coefficients[0] * coefficients[1] * (b*b - a*a)) +
//			((coefficients[1] * coefficients[1] / 3.0) * (b*b*b));
//	}
//	case(2):
//	{
//		switch(l)
//		case(0):
//			return 0.0;
//		case(1):
//			return 0.5 * (coefficients[0] * coefficients[0] *(b - a)) +
//			(coefficients[0] * coefficients[1] * (b*b - a*a)) +
//			((coefficients[1] * coefficients[1] / 3.0) * (b*b*b));
//		case(2):


//	}
//}

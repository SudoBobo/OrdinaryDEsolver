#ifndef MYMATH_H
#define MYMATH_H

//вычисляет среднее значение величины u по промежутку j
//это значение также используется как численное значение u в точке x(j)
double calcAvgValue(const int k, const int j, const double spatialStep,
				 const double * u);
double integral23(const int k, const int j, const int l, const double spatialStep,
				  const double * u);
#endif // MYMATH_H

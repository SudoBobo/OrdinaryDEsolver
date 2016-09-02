#ifndef GODUNOVSTREAM_H
#define GODUNOVSTREAM_H

#include "Stream.h"
//checked
class GodunovStream: public Stream
{
public:
	GodunovStream(System & system);
	double operator()(double uA, double uB);
};

#endif // GODUNOVSTREAM_H

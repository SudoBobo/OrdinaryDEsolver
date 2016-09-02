#include "GodunovStream.h"

GodunovStream::GodunovStream(System & system): Stream (system)
{

}

double GodunovStream::operator ()(double uA, double uB)
{
        // поток в точке x(j+1/2)
        // uA = предельное значение слева, то есть значение в точке x(j)
        // uB = предельное значение справа, то есть значение в точке x(j+1)
        if (uA <= uB)
                return std::min(m_system.f(uA), m_system.f(uB));
        else //if (uB < uA)
                return std::max(m_system.f(uA), m_system.f(uB));
}

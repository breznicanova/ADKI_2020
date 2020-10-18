#ifndef SORTBYANGLE_H
#define SORTBYANGLE_H
#include "algorithms.h"
#include <QtGui>


class SortByAngle
{
public:
    struct AngleStruct
    {
        QPoint p;    // Point
        double a;    // Omega
        double d;    // Distance
    };

    SortByAngle();
    bool operator ()(AngleStruct &p1, AngleStruct &p2)
    {
        //Is omega2 bigger than omega1
        return (p1.a < p2.a) || ((p1.a == p2.a) && (p1.d < p2.d));

    }
};

#endif // SORTBYANGLE_H

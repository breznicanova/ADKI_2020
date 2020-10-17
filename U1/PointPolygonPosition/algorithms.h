#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <QPoint>

class Algorithms
{
public:
    Algorithms();

    int getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2);
    double getAngle(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);
    int getPositionWinding(QPoint &q, std::vector<QPoint> &pol);
    int getPositionRay(QPoint &q, std::vector<QPoint> &pol);

};

#endif // ALGORITHMS_H

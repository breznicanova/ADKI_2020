#ifndef SORTBYCOORDINATE_H
#define SORTBYCOORDINATE_H
#include <QtGui>


class SortByCoordinate
{
public:
    SortByCoordinate();
    bool operator ()(QPoint &p1, QPoint &p2)
    {
        return (p1.y() < p2.y()) || ((p1.y() == p2.y()) && (p1.x() < p2.x()));
    }
};

#endif // SORTBYCOORDINATE_H

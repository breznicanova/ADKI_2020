#include "algorithms.h"

Algorithms::Algorithms()
{

}

double Algorithms::lh(std::vector <QPoint> points)
{
    double area = 0;
    int n = points.size();

    //Process all points except first and last
    for (int i=1; i < n-1;i++)
    {
        area += points[i].x() * (points[i+1].y()-points[i-1].y());
    }

    //Point with index 0 (first point)
    area+= points[0].x() * (points[1].y()-points[n-1].y());

    //Point with index n-1 (last point)
    area += points[n-1].x() * (points[0].y()-points[n-2].y());

    return area/2;
}

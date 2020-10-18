#include "algorithms.h"
#include <cmath>


Algorithms::Algorithms()
{

}


int Algorithms::getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2)
{
    //Get point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //Determinant
    double t = ux * vy - uy * vx;

    //Point in the left halfplane
    if ( t > 0)
         return 1;

    //Point in the right halfplane
    if (t < 0)
        return 0;

    //Point on the line
    return -1;
}


double Algorithms::getAngle(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4)
{
    //Get vectors u, v
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    //Dot product
    double dot = ux * vx + uy * vy;

    return fabs(acos(dot/(nu*nv)));
}


int Algorithms::getPositionWinding(QPoint &q, std::vector<QPoint> &pol)
{
    //Position of a point and polygon: Winding Number Algorithm
    //q inside P: 1
    //q outside P: 0
    //q on P boundary: -1

    double Omega = 0.0;

    //Set tolerance
    const double eps = 1.0e-6;

    //Amount of polygon vertices
    const int n = pol.size();

    //Process all vertices of the polygon
    for (int i = 0; i < n; i++)
    {
        //Get angle omega
        double om = getAngle(q,pol[i],q,pol[(i+1)%n]);

        //Get orientation of q and pol[i], pol[i+1]
        int orientation = getPointLinePosition(q, pol[i], pol[(i+1)%n]);

        //Point in the left halfplane
        if (orientation == 1)
            Omega += om;

        //Point in the right halfplane
        else
            Omega -= om;
    }

    //Point q inside polygon
    if (fabs(fabs(Omega) - 2*M_PI) < eps)
        return 1;

    //Point q outside polygon
    return 0;
}


int Algorithms::getPositionRay(QPoint &q, std::vector<QPoint> &pol)
{
    //Position of a point and polygon: Ray Crossing Algorithm
    //q inside P: 1
    //q outside P: 0
    //q on P boundary: -1

    //Amount of intersections
    int k = 0;

    //Amount of polygon vertices
    const int n = pol.size();

    //Process all vertices of the polygon
    for (int i = 1; i < n + 1 ; i++)
    {
        //Compute xi, yi, xii, yii
        double xir = pol[i%n].x() - q.x();
        double yir = pol[i%n].y() - q.y();
        double xiir = pol[i-1].x() - q.x();
        double yiir = pol[i-1].y() - q.y();

        //Does segment (pi-1, pi) intersect ray
        if ((yir > 0) && (yiir <= 0) || (yiir > 0) && (yir <= 0))
        {
            //Compute x coordinate of intersection
            double xm = (xir * yiir - xiir * yir)/(yir - yiir);

            //Point q in the right halfplane
            if (xm > 0)
                k += 1;
        }
    }

    //Get amount of intersections: odd or even
    return k%2;
}



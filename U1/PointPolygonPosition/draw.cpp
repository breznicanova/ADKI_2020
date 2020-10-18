#include "draw.h"
#include <QMessageBox>
#include <algorithms.h>
#include <iostream>


Draw::Draw(QWidget *parent) : QWidget(parent)
{
    //Set default draw mode
    draw_mode = true;

    //Draw point outside Canvas
    q.setX(-50);
    q.setY(-50);
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Cursor position
    double x = e->pos().x();
    double y = e->pos().y();

    //Mode = polygon
    if (draw_mode)
    {
        //Create new point
        QPoint p(x, y);

        //Add point to the polygon
        polygon.push_back(p);
    }

    //Mode = q
    else
    {
        //Change coordinates of q
        q.setX(x);
        q.setY(y);
    }

    repaint();
}


void Draw::paintEvent(QPaintEvent *e)
{
    //Start drawing
    QPainter painter(this);
    painter.begin(this);

    //Create polygon
    QPolygon pol;

    //Copy all points into polygon
    for (int i = 0; i< polygon.size(); i++ )
    {
         pol.append(polygon[i]);
    }

    //Draw polygon
    painter.drawPolygon(pol);

    //Draw q point
    int r = 5;
    painter.drawEllipse(q.x(), q.y(), 2 * r, 2 *r);

    //End drawing
    painter.end();
}


void Draw::importPolygon(std::string path)
{
    //Open the file
    std::ifstream sourceFile;
    sourceFile.open(path);

    //Check if the file is opened
    if(!sourceFile.is_open())
    {
        sourceFile.close();
        QMessageBox::warning(this, "Error!", "File can't be opened.");
    }

    //Get the number of polygons in text file
    int polygonCount;

    sourceFile >> polygonCount;
    //Number of points in the polygon
    int pointsCount;

    //Vector for single polygon points
    std::vector<QPoint> singlePolygon;

    //Go through whole file and store all polygons to variable polygon
    while(sourceFile.good() && polygonCount--)
    {
        //Get number of points in one polygon
        sourceFile >> pointsCount;

        //Go through all points in single polygon and store them in variable single_polygon
        while(pointsCount--)
        {
            QPoint single_point;
            double point_x, point_y;
            sourceFile >> point_x;
            sourceFile >> point_y;
            single_point.setX(point_x);
            single_point.setY(point_y);
            singlePolygon.push_back(single_point);
        }
     }

    sourceFile.close();

}

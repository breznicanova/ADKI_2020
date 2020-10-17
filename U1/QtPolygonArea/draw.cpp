#include "draw.h"

#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Create new point at a position of cursor
    QPoint p(e->pos().x(), e->pos().y());

    //Add point to the list
    points.push_back(p);

    //Repaint Canvas
    repaint();
}


void Draw::paintEvent(QPaintEvent *e)
{
    //Create new object for painting
    QPainter painter(this);

    //Begin paint
    painter.begin(this);

    //Draw polygon
    QPolygon pol;
    for (int i = 0; i < points.size(); i++)
        pol.append(points[i]);
    painter.drawPolygon(pol);

    //End paint
    painter.end();
}

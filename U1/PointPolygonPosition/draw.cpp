#include "draw.h"

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

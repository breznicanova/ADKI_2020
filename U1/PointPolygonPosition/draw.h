#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <QWidget>
#include <QtGui>
#include <fstream>
#include <string>
#include <iostream>
#include <QPainterPath>
#include <QBrush>
#include <QPen>

class Draw : public QWidget
{
    Q_OBJECT
private:
    boolean draw_mode;  //true = polygon, false = point
    std::vector <QPoint> polygon;
    QPoint q;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void changeMode(){draw_mode = !draw_mode;}
    QPoint & getPoint(){return q;}
    std::vector<QPoint> & getPolygon (){return polygon;}
    void importPolygon(std::string path);
};

#endif // DRAW_H

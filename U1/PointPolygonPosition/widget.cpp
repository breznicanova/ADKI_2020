#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include <QtGui>
#include <QMessageBox>
#include <fstream>
#include <string.h>
#include "qdebug.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_drawPointPolygon_clicked()
{
    //Change drawing mode
    ui->Canvas->changeMode();
}


void Widget::on_analyze_clicked()
{
    //Get point q
    QPoint &q= ui->Canvas->getPoint();

    //Get polygon
    std::vector<QPoint>& polygon = ui->Canvas->getPolygon();

    //Get combo-box status, select method
    int result;
    Algorithms alg;

    //Winding Number Algorithm
    if (ui->comboBox->currentIndex()==0)
        result = alg.getPositionWinding(q, polygon);

    //Ray Crossing Algorithm
    else
        result = alg.getPositionRay(q,polygon);

    //Print results
    if(result == 1)
        ui->label->setText("Inside");
    else
        ui->label->setText("Outside");
}


void Widget::on_clear_clicked()
{
    //Get polygon
    std::vector<QPoint>& polygon = ui->Canvas->getPolygon();

    //Clear polygon
    polygon.clear();

    //Repaint screen
    repaint();
}


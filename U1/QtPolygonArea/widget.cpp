#include "widget.h"
#include "ui_widget.h"

#include "algorithms.h"


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


void Widget::on_pushButton_clicked()
{
    //Get points
    std::vector<QPoint> canvas_points = ui->Canvas->getPoints();

    //Compute area
    Algorithms a;
    double area=a.lh(canvas_points);

    //Print area to label
    ui->label_2->setText(QString::number(area));

}

void Widget::on_pushButton_2_clicked()
{
    //Get reference to points
    std::vector<QPoint> &canvas_points = ui->Canvas->getPoints();

    //Delete all points
    canvas_points.clear();

    //Repaint screen
    repaint();
}

#include "guataijiwidget.h"

GuaTaijiWidget::GuaTaijiWidget()
{
    setFixedWidth(111);
    setFixedHeight(111);
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(50);
}

void GuaTaijiWidget::paintEvent(QPaintEvent *){
    rot += 1;
    QPainter painter(this);
    painter.rotate(rot);
    painter.setWindow(-210,-210,420,420);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.setPen(QPen(Qt::red,0,Qt::NoPen,Qt::RoundCap));
    painter.drawPie(-200,-200,400,400,93*16,180*16);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter.drawPie(-200,-200,400,400,273*16,180*16);
    painter.drawPie(-100,-200,200,200,93*16,180*16);
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.drawPie(-100,0,200,200,273*16,180*16);
    painter.drawEllipse(-20,-130,40,40);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter.drawEllipse(-20,70,40,40);
}

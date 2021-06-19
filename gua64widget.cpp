#include "gua64widget.h"

#define INITIAL_Y_LOCATION 27
#define OFFSET 12

Gua64Widget::Gua64Widget(int hexKey, QString stringKey, QWidget *parent) : QWidget(parent)
{
    hex = hexKey;
    string = stringKey;
    setFixedWidth(121);
    setFixedHeight(110);
}

void Gua64Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int y = INITIAL_Y_LOCATION;
    for (int i = 5; i >= 0; i--) {
        if (!((hex >> i) & 1)) {
            painter.setPen(QPen(Qt::black,1));
            painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
            painter.drawRect(20,y,35,8);
            painter.drawRect(65,y,35,8);
        } else {
            painter.setPen(QPen(Qt::red,1));
            painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
            painter.drawRect(20,y,80,8);
        }
        y += OFFSET;
    }
}

void Gua64Widget::mouseReleaseEvent(QMouseEvent *){
    SubWidget::getInstance()->showGua(hex,string);
    emit clicked();
}


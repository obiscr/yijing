#include "gua8widget.h"

#define INITIAL_Y_LOCATION 20
#define OFFSET 20

Gua8Widget::Gua8Widget(int hexKey, QString stringKey, QWidget *parent) : QWidget(parent)
{
    hex = hexKey;
    string = stringKey;
    setFixedWidth(121);
    setFixedHeight(87);
}

void Gua8Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int y = INITIAL_Y_LOCATION;
    for (int i = 2; i >= 0; i--) {
        if (!((hex >> i) & 1)) {
            painter.setPen(QPen(Qt::black,1));
            painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
            painter.drawRect(20,y,35,10);
            painter.drawRect(65,y,35,10);
        } else {
            painter.setPen(QPen(Qt::red,1));
            painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
            painter.drawRect(20,y,80,10);
        }
        y += OFFSET;
    }
}

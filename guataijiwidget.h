#ifndef GUATAIJIWIDGET_H
#define GUATAIJIWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTimer>

class GuaTaijiWidget : public QWidget
{
public:
    GuaTaijiWidget();
protected:
    virtual void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
private:
    double rot;
};

#endif // GUATAIJIWIDGET_H

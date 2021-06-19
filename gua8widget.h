#ifndef GUA8WIDGET_H
#define GUA8WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

#include "tool.h"

class Gua8Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Gua8Widget(int hexKey, QString stringKey, QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
private:
    int hex;
    QString string;
signals:

public slots:
};

#endif // GUA8WIDGET_H

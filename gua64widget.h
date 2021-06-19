#ifndef GUA64WIDGET_H
#define GUA64WIDGET_H
#include <string>
#include <cstring>

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTextEdit>
#include <QLocale>
#include <QLabel>

#include "tool.h"
#include "qborderlayout.h"
#include "subwidget.h"

class Gua64Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Gua64Widget(int hexKey, QString stringKey, QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    virtual void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;
private:
    int hex;
    QString string;

signals:
    void clicked();
public slots:
};

#endif // GUA64WIDGET_H

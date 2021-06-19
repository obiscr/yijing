#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>

#include "tool.h"
#include "qborderlayout.h"
#include "gua64widget.h"
#include "mainwindow.h"

class SubWidget : public QDialog
{
    Q_OBJECT
public:
    explicit SubWidget(QDialog *parent = nullptr);
    void showGua(int hex, QString string);
    static SubWidget* getInstance(void)
    {
        static SubWidget s_instance;
        return &s_instance;
    }

signals:

public slots:
};

#endif // SUBWIDGET_H

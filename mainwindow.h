#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>

#include "gua64widget.h"
#include "gua8widget.h"
#include "guataijiwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* getInstance(void)
    {
        static MainWindow s_instance;
        return &s_instance;
    }

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

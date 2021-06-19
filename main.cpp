#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    qputenv("QT_SCALE_FACTOR", "1.5");
    QApplication a(argc, argv);
    MainWindow *w = MainWindow::getInstance();
    w->show();
    return a.exec();
}

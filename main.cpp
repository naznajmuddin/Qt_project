#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(484,422);
    w.setWindowTitle("Air Quality Index Sensor GUI");
    w.show();

    return a.exec();
}

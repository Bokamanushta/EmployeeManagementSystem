#include "mainwindow.h"
#include "test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int width = 1360;
    int height = 700;
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedWidth(width);
    w.setFixedHeight(height);
    w.show();
    return a.exec();
}

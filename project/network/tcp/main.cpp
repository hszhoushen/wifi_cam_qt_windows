#include "mainwindow.h"
#include <QApplication>

void ErrorHandling(char * message);
void tcp_init();

int main(int argc, char ** argv)
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}


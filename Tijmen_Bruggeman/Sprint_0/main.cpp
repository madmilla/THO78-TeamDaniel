#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    if(argc >1 && strcmp(argv[1], "-test") == 0){
        std::cout << "this is a tests\n";
    }
    else{
        std::cout << "this is not a test\n";
        QApplication a(argc, argv);
        MainWindow w;
        qDebug() << "start";
        w.show();
        return a.exec();
    }
}

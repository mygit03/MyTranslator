#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator translator;
//    translator.load(":/cn.qm");
//    a.installTranslator(&translator);

    QFile qssFile(":/style.qss");
    qssFile.open(QIODevice::ReadOnly);
    if ( qssFile.isOpen() ){
        QString qss = qssFile.readAll();
        a.setStyleSheet(qss);
        qssFile.close();
    }

    MainWindow w;
    w.show();

    return a.exec();
}

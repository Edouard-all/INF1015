 #include "mainwindow.h"
#include <QApplication>
#include "vueEchiquier.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    VueEchiquier echequier;
    echequier.show();
    return QCoreApplication::exec();
}

#include "SimonUI.h"
#include <QApplication>
//Author:Devin White
//Cs 3505
//A5 SIMON GAME
//Main Method, simply calls UI.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

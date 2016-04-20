#include "mainwindow.h"
#include "computer_intelligence.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI widj;
    ComputeIntelligence comp;

    widj.createGUI();

    return a.exec();
}

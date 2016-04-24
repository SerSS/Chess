#ifndef COMPUTER_INTELLIGENCE
#define COMPUTER_INTELLIGENCE

#include "mainwindow.h"


class ComputeIntelligence : public QObject  {
    Q_OBJECT

public:
    GUI gui;
    AllArrays *arr = &gui.arr;



    void findDangerCell();
    int priceFigure(int x, int y);
    int priceFigure(int figure);
};

#endif // COMPUTER_INTELLIGENCE


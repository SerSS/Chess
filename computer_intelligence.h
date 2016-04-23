#ifndef COMPUTER_INTELLIGENCE
#define COMPUTER_INTELLIGENCE

#include "mainwindow.h"


class ComputeIntelligence : public QObject  {
    Q_OBJECT

public:
    GUI gui;
    AllArrays* arr = &gui.arr;
    int unwantedMove[8][8];

    void findDangerCell();
    int priceFigure(int x, int y);
    int priceFigure(int figure);
};

#endif // COMPUTER_INTELLIGENCE


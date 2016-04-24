#include "computer_intelligence.h"

//1 - фигура пользователя  2 - фигура компа   5 - пуста клетка опасный ход   7 - фигура пользователя под защитой
//8 - фигура компа под защитой

void ComputeIntelligence::findDangerCell() {
    for (int x = 0; x < 8; x++) {
        for (int y  = 0; y < 8; y++) {

        }
    }
}

int ComputeIntelligence::priceFigure(int x, int y) {
    switch (arr->figuresOnBoard[x][y]) {
        case 1:     //ладья
            return 5;
        case 2:     //лошадь
            return 3;
        case 3:     //офицер
            return 3;
        case 4:     //дамка
            return 10;
        case 5:     //король
            return 20;
        case 6:     //пешка
            return 1;
        default:
            return 0;
    }
}

int ComputeIntelligence::priceFigure(int figure) {
    switch (figure) {
        case 1:     //ладья
            return 5;
        case 2:     //лошадь
            return 3;
        case 3:     //офицер
            return 3;
        case 4:     //дамка
            return 10;
        case 5:     //король
            return 20;
        case 6:     //пешка
            return 1;
        default:
            return 0;
    }
}


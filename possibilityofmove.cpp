#include "mainwindow.h"

void GUI::checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY){

    switch (figuresOnBoard[x][y]) {
        case 1://ладья

            break;
        case 2://лошадь

            break;
        case 3://офицер

            break;
        case 4://дамка

            break;
        case 5://король

            break;
        case 8://пешка
            if (playerOnBoard[x][y] == 1) {

            } else if (playerOnBoard[x][y] == 2) {

            }
            break;
    }
}

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
            if (playerOnBoard[x][y] == 1) {//белые
                if (checkableX < x) {//не пытаются ли пойти назад
                    if (checkableY == y) {//вперед ли ход
                        if (playerOnBoard[checkableX][checkableY] == 0) {//пустая ли ячейка
                            if (x == 6) { //первий ли ход
                                //реализация первого хода




                            } else {
                                //реализация остальных ходоа



                            }
                        }
                    } else if ((checkableY == (y+1) || checkableY == (y-1)) &&
                               checkableX == (x-1) &&           //возможен ли бой
                               playerOnBoard[checkableX][checkableY] == 2) {
                        //реализация боя






                    }
                }
            } else if (playerOnBoard[x][y] == 2) {//черные
                if (checkableX > x) {//не пытаются ли пойти назад
                    if (checkableY == y) {//вперед ли ход
                        if (playerOnBoard[checkableX][checkableY] == 0) {//пустая ли ячейка
                            if (x == 1) { //первий ли ход
                                //реализация первого хода




                            } else {
                                //реализация остальных ходоа



                            }
                        }
                    } else if ((checkableY == (y+1) || checkableY == (y-1)) &&
                               checkableX == (x+1) &&           //возможен ли бой
                               playerOnBoard[checkableX][checkableY] == 1) {
                        //реализация боя






                    }
                }
            }
            break;
    }
}

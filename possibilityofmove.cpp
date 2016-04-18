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
                    if (y == checkableY &&      //проверка ход или бой
                            playerOnBoard[checkableX][checkableY] == 0) {
                        if (playerOnBoard[x][y] == 6) {//прверка первого хода
                            if (checkableX >= 4) {
                                //реализация первго хода






                            }
                        } else {
                            if (checkableX == (x-1)) {
                                //реализация остальных ходов




                            }
                        }


                    } else if ((checkableY == (y-1) || checkableY == (y+1)) &&
                               checkableX == (x-1) &&           //проверка боя
                               playerOnBoard[checkableX][checkableY] == 2) {
                        //реализация боя






                    }
                }
            } else if (playerOnBoard[x][y] == 2) {//черные
                if (checkableX > x) {//не пытаются ли пойти назад
                    if (y == checkableY &&      //проверка ход или бой
                            playerOnBoard[checkableX][checkableY] == 0) {
                        if (playerOnBoard[x][y] == 1) {//прверка первого хода
                            if (checkableX <= 3) {
                                //реализация первго хода






                            }
                        } else {
                            if (checkableX == (x+1)) {
                                //реализация остальных ходов




                            }
                        }


                    } else if ((checkableY == (y-1) || checkableY == (y+1)) &&
                               checkableX == (x+1) &&           //проверка боя
                               playerOnBoard[checkableX][checkableY] == 1) {
                        //реализация боя






                    }
                }
            }
            break;
    }
}

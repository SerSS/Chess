#include "mainwindow.h"

void GUI::checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY){
    //проверка попытки боя своей фигуры
    if (playerOnBoard[x][y] == 1 && playerOnBoard[checkableX][checkableY] == 1) {
        return;
    } else if (playerOnBoard[x][y] == 2 && playerOnBoard[checkableX][checkableY] == 2) {
        return;
    }

    switch (figuresOnBoard[x][y]) {
        case 1://ладья
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if (checkableX == x) {
                    if (checkableY < y) {//влево
                        for (int i = y - 1; i > checkableY; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableY > y) {//вправо
                        for (int i = y + 1; i < checkableY; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                } else if (checkableY == y) {
                    if (checkableX < x) {//вверх
                        for (int i = x - 1; i > checkableX; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableX > x) {//вниз
                        for (int i = x + 1; i < checkableX; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                }
            }
            break;
        case 2://лошадь
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if (checkableX == (x-2)) {//вверх
                    if (checkableY == (y-1)) {//влево
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableY == (y+1)) {//вправо
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                } else if (checkableX == (x+2)) {//вниз
                    if (checkableY == (y-1)) {//влево
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableY == (y+1)) {//вправо
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                } else if (checkableY == (y-2)) {//влево
                    if (checkableX == (x-1)) {//вверх
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableX == (x+1)) {//вниз
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                } else if (checkableY == (y+2)) {//вправо
                    if (checkableX == (x-1)) {//вверх
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableX == (x+1)) {//вниз
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                }
            }
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
                            if (checkableX >= 4 && figuresOnBoard[x-1][y] == 0) {//нет ли по пути фигуры
                                //реализация первго хода
                                moveOneStep(x, y, checkableX, checkableY);
                                if (checkableX == 0) {
                                    //замена пешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        } else {
                            if (checkableX == (x-1)) {
                                //реализация остальных ходов
                                moveOneStep(x, y, checkableX, checkableY);
                                if (checkableX == 0) {
                                    //замена пешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        }

                    } else if ((checkableY == (y-1) || checkableY == (y+1)) &&
                               checkableX == (x-1) &&           //проверка боя
                               playerOnBoard[checkableX][checkableY] == 2) {
                        //реализация боя
                        moveOneStep(x, y, checkableX, checkableY);
                        if (checkableX == 0) {
                            //замена пешки
                            exchangeOfAPawn(checkableX, checkableY);
                        }
                    }
                }
            } else if (playerOnBoard[x][y] == 2) {//черные
                if (checkableX > x) {//не пытаются ли пойти назад
                    if (y == checkableY &&      //проверка ход или бой
                            playerOnBoard[checkableX][checkableY] == 0) {
                        if (playerOnBoard[x][y] == 1) {//прверка первого хода
                            if (checkableX <= 3 && figuresOnBoard[x+1][y]) {//нет ли по пути фигуры
                                //реализация первго хода
                                moveOneStep(x, y, checkableX, checkableY);
                                if (checkableX == 7) {
                                    //замена пеешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        } else {
                            if (checkableX == (x+1)) {
                                //реализация остальных ходов
                                moveOneStep(x, y, checkableX, checkableY);
                                if (checkableX == 7) {
                                    //замена пеешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        }

                    } else if ((checkableY == (y-1) || checkableY == (y+1)) &&
                               checkableX == (x+1) &&           //проверка боя
                               playerOnBoard[checkableX][checkableY] == 1) {
                        //реализация боя
                        moveOneStep(x, y, checkableX, checkableY);
                        if (checkableX == 7) {
                            //замена пеешки
                            exchangeOfAPawn(checkableX, checkableY);
                        }
                    }
                }
            }
            break;
    }
}

void GUI::moveOneStep(int x, int y, int checkableX, int checkableY) {

}

void GUI::exchangeOfAPawn(int x, int y) {

}

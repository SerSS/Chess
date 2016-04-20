#include "mainwindow.h"

bool GUI::checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY){
    //проверка попытки боя своей фигуры
    if (playerOnBoard[x][y] == 0 || playerOnBoard[x][y] == playerOnBoard[checkableX][checkableY] || (x==checkableX && y==checkableY)) {
        return;
    }

    switch (figuresOnBoard[x][y]) {
        case 1://ладья
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if (checkableX == x) {
                    if (checkableY < y) {//влево
                        for (int i = y - 1; i > checkableY; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    } else if (checkableY > y) {//вправо
                        for (int i = y + 1; i < checkableY; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    }
                } else if (checkableY == y) {
                    if (checkableX < x) {//вверх
                        for (int i = x - 1; i > checkableX; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    } else if (checkableX > x) {//вниз
                        for (int i = x + 1; i < checkableX; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return false;
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

                    } else if (checkableY == (y+1)) {//вправо
                        //реализация хода

                    }
                } else if (checkableX == (x+2)) {//вниз
                    if (checkableY == (y-1)) {//влево
                        //реализация хода

                    } else if (checkableY == (y+1)) {//вправо
                        //реализация хода

                    }
                } else if (checkableY == (y-2)) {//влево
                    if (checkableX == (x-1)) {//вверх
                        //реализация хода

                    } else if (checkableX == (x+1)) {//вниз
                        //реализация хода

                    }
                } else if (checkableY == (y+2)) {//вправо
                    if (checkableX == (x-1)) {//вверх
                        //реализация хода

                    } else if (checkableX == (x+1)) {//вниз
                        //реализация хода

                    }
                }
            }
            break;
        case 3://офицер
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if((x - checkableX) == (y - checkableY) || (x - checkableX) == ((y - checkableY) * (-1))){//проверка по диагонали он ходит или нет
                    //запускаем проверку нет ли фигур по пути
                    if(x < checkableX && y < checkableY){// вниз вправо
                        for(int i=x, j=y; i < checkableX; i++, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x < checkableX && y > checkableY){// вниз влево
                        for(int i=x, j=y; i < checkableX; i++, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x > checkableX && y < checkableY){// вверх вправо
                        for(int i=x, j=y; i > checkableX; i--, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x > checkableX && y > checkableY){// вверх влево
                        for(int i=x, j=y; i > checkableX; i--, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                }
            }
            break;
        case 4://дамка
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {//
                //Проверка ход был сделан по горизонтали или вертикали
                if (checkableX == x) {
                    if (checkableY < y) {//влево
                        for (int i = y - 1; i > checkableY; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    } else if (checkableY > y) {//вправо
                        for (int i = y + 1; i < checkableY; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    }
                } else if (checkableY == y) {
                    if (checkableX < x) {//вверх
                        for (int i = x - 1; i > checkableX; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    } else if (checkableX > x) {//вниз
                        for (int i = x + 1; i < checkableX; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return false;
                            }
                        }
                        //реализация хода

                    }
                }
                //проверка ход был сделан по диагонали или нет
                else if((x - checkableX) == (y - checkableY) || (x - checkableX) == ((y - checkableY) * (-1))){
                    //запускаем проверку нет ли фигур по пути
                    if(x < checkableX && y < checkableY){// вниз вправо
                        for(int i=x, j=y; i < checkableX; i++, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x < checkableX && y > checkableY){// вниз влево
                        for(int i=x, j=y; i < checkableX; i++, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x > checkableX && y < checkableY){// вверх вправо
                        for(int i=x, j=y; i > checkableX; i--, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    if(x > checkableX && y > checkableY){// вверх влево
                        for(int i=x, j=y; i > checkableX; i--, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                 }
            }
            break;
        case 5://король
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if(x - checkableX == 1 || x - checkableX == (-1) || x - checkableX == 0){
                    if(y - checkableY == 1 || y - checkableY == (-1) || y - checkableY == 0){
                        //реализация хода

                    }
                }
            }
            break;
        case 8://пешка
            if (playerOnBoard[x][y] == 1) {//белые
                if (checkableX < x) {//не пытаются ли пойти назад
                    if (y == checkableY &&      //проверка ход или бой
                            playerOnBoard[checkableX][checkableY] == 0) {
                        if (playerOnBoard[x][y] == 6) {//прверка первого хода
                            if (checkableX >= 4 && figuresOnBoard[x-1][y] == 0) {//нет ли по пути фигуры
                                //реализация первго хода

                                if (checkableX == 0) {
                                    //замена пешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        } else {
                            if (checkableX == (x-1)) {
                                //реализация остальных ходов

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

                                if (checkableX == 7) {
                                    //замена пеешки
                                    exchangeOfAPawn(checkableX, checkableY);
                                }
                            }
                        } else {
                            if (checkableX == (x+1)) {
                                //реализация остальных ходов

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

void GUI::moveOneStep(int x, int y, int checkableX, int checkableY) {   //Делает ход (перемещает фигуру)
    figuresOnBoard[checkableX][checkableY] = figuresOnBoard[x][y];      //Перемещаем значение фигуры
    figuresOnBoard[x][y] = 0;

    playerOnBoard[checkableX][checkableY] = playerOnBoard[x][y];        //Перемещаем значение игрока
    playerOnBoard[x][y] = 0;

    cellButtons[checkableX][checkableY].setIcon(figureImage[playerOnBoard[checkableX][checkableY]-1]        //Отображаем картинку
                                                              [figuresOnBoard[checkableX][checkableY]-1]);  //фигуры на новой позиции
    cellButtons[checkableX][checkableY].setIconSize(cellButtons[x][y].size());

    cellButtons[x][y].setIcon(QIcon(QPixmap("")));      //Убираем картинку фигуры со старой позиции
}

void GUI::exchangeOfAPawn(int x, int y) {

}

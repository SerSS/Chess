#include "mainwindow.h"

bool GUI::checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY){
    if (x < 0 || y < 0 || x > 7 || y > 7 || checkableX < 0 || checkableY < 0 || checkableX > 7 || checkableY > 7 || //проверка выхода за розмерность доски
        playerOnBoard[x][y] == 0 || playerOnBoard[x][y] == playerOnBoard[checkableX][checkableY] || (x==checkableX && y==checkableY)) { //проверка попытки боя своей фигуры
        click =0;
        return false;
    }

    switch (figuresOnBoard[x][y]) {
        case 1://ладья
            /*if (x != checkableX && y != checkableY) {
                return false;
            }*/
            if (x == checkableX) {
                if (checkableY > y) {
                    for (int i = y + 1; i < checkableY; i++) {
                        if (figuresOnBoard[x][i] != 0) {
                            return false;
                        }
                    }
                } else if (checkableY < y) {
                    for (int i = y - 1; i > checkableY; i--) {
                        if (figuresOnBoard[x][i] != 0) {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            } else if (y == checkableY) {
                if (checkableX > x) {
                    for (int i = x + 1; i < checkableX; i++) {
                        if (figuresOnBoard[i][y] != 0) {
                            return false;
                        }
                    }
                } else if (checkableX < x) {
                    for (int i = x - 1; i > checkableX; i--) {
                        if (figuresOnBoard[i][y] != 0) {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
            break;
        case 2://лошадь

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
                        moveOneStep(x, y, checkableX, checkableY);
                    } else if (checkableY > y) {//вправо
                        for (int i = y + 1; i < checkableY; i++) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[x][i] != 0) {
                                return false;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                } else if (checkableY == y) {
                    if (checkableX < x) {//вверх
                        for (int i = x - 1; i > checkableX; i--) {//проверка нет ли по пути фигур
                            if (figuresOnBoard[i][y] != 0) {
                                return false;
                            }
                        }
                        //реализация хода
                        moveOneStep(x, y, checkableX, checkableY);
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
                        moveOneStep(x, y, checkableX, checkableY);
                    }
                }
            }
            break;
        case 6://пешка

            break;
    }
    moveOneStep(x, y, checkableX, checkableY);
    return true;
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

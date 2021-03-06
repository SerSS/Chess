#include "mainwindow.h"

bool GUI::checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY){
    if (x < 0 || y < 0 || x > 7 || y > 7 || checkableX < 0 || checkableY < 0 || checkableX > 7 || checkableY > 7 || //проверка выхода за розмерность доски
        playerOnBoard[x][y] == 0 || playerOnBoard[x][y] == playerOnBoard[checkableX][checkableY] || (x==checkableX && y==checkableY)) { //проверка попытки боя своей фигуры
        return false;
    }

    switch (figuresOnBoard[x][y]) {
        case 1://ладья
            if (x == checkableX) {
                if (checkableY > y) {//вправо
                    for (int i = y + 1; i < checkableY; i++) {//проверка нет ли по пути фигруы
                        if (figuresOnBoard[x][i] != 0) {
                            return false;
                        }
                    }
                } else if (checkableY < y) {//влево
                    for (int i = y - 1; i > checkableY; i--) {//проверка нет ли по пути фигруы
                        if (figuresOnBoard[x][i] != 0) {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            } else if (y == checkableY) {
                if (checkableX > x) {//вниз
                    for (int i = x + 1; i < checkableX; i++) {//проверка нет ли по пути фигруы
                        if (figuresOnBoard[i][y] != 0) {
                            return false;
                        }
                    }
                } else if (checkableX < x) {//вверх
                    for (int i = x - 1; i > checkableX; i--) {//проверка нет ли по пути фигруы
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
            if ((checkableX == (x+2) || checkableX == (x-2)) && (checkableY == (y+1) || checkableY == (y-1))) {

            } else if ((checkableX == (x+1) || checkableX == (x-1)) && (checkableY == (y+2) || checkableY == (y-2))) {

            } else {
                return false;
            }
            break;
        case 3://офицер
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if((x - checkableX) == (y - checkableY) || (x - checkableX) == ((y - checkableY) * (-1))){//проверка по диагонали он ходит или нет
                    //запускаем проверку нет ли фигур по пути
                    if(x < checkableX && y < checkableY){// вниз вправо
                        for(int i=x+1, j=y+1; i < checkableX; i++, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x < checkableX && y > checkableY){// вниз влево
                        for(int i=x+1, j=y-1; i < checkableX; i++, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x > checkableX && y < checkableY){// вверх вправо
                        for(int i=x-1, j=y+1; i > checkableX; i--, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x > checkableX && y > checkableY){// вверх влево
                        for(int i=x-1, j=y-1; i > checkableX; i--, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else {
                        return false;
                    }
                }else {
                    return false;
                }
            }else {
                return false;
            }
            break;
        case 4://дамка
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {//
                //Проверка ход был сделан по горизонтали или вертикали
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
                }
                //проверка ход был сделан по диагонали или нет
                else if((x - checkableX) == (y - checkableY) || (x - checkableX) == ((y - checkableY) * (-1))){
                    if(x < checkableX && y < checkableY){// вниз вправо
                        for(int i=x+1, j=y+1; i < checkableX; i++, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x < checkableX && y > checkableY){// вниз влево
                        for(int i=x+1, j=y-1; i < checkableX; i++, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x > checkableX && y < checkableY){// вверх вправо
                        for(int i=x-1, j=y+1; i > checkableX; i--, j++){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else if(x > checkableX && y > checkableY){// вверх влево
                        for(int i=x-1, j=y-1; i > checkableX; i--, j--){
                            if(figuresOnBoard[i][j] != 0){
                                return false;
                            }
                        }
                    }
                    else {
                        return false;
                    }
                }else {
                    return false;
                }
            } else{
                return false;
            }
            break;
        case 5://король
            if (checkableX < 8 && checkableY < 8 && checkableX >= 0 && checkableY >= 0) {
                if(x - checkableX > 1 || x - checkableX < (-1)){
                    return false;
                }
                else if(y - checkableY > 1 || y - checkableY < (-1)){
                    return false;
                }
            }
            break;
        case 6://пешка
            if (playerOnBoard[x][y] == 1) {//белые
                if (checkableX > x || checkableY > (y+1) || checkableY < (y-1)) {
                    return false;
                }
                if (checkableY == y) {
                    if (x == 6) {
                        if (checkableX >= (x-2)) {
                            for (int i = 5; i >= checkableX; i--) {
                                if (figuresOnBoard[i][y] != 0) {
                                    return false;
                                }
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (checkableX == (x-1)) {
                            if (figuresOnBoard[checkableX][checkableY] != 0) {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                } else if ((checkableX == (x-1)) && (checkableY == (y+1) || checkableY == (y-1))){
                    if (playerOnBoard[checkableX][checkableY] != 2) {
                        return false;
                    }
                } else {
                    return false;
                }
                if (checkableX == 0) {
                    exchangeOfAPawn(x, y);
                }
            } else if (playerOnBoard[x][y] == 2) {//черные
                if (checkableX < x || checkableY > (y+1) || checkableY < (y-1)) {
                    return false;
                }
                if (checkableY == y) {
                    if (x == 1) {
                        if (checkableX <= (x+2)) {
                            for (int i = 2; i <= checkableX; i++) {
                                if (figuresOnBoard[i][y] != 0) {
                                    return false;
                                }
                            }
                        } else {
                            return false;
                        }
                    } else {
                        if (checkableX == (x+1)) {
                            if (figuresOnBoard[checkableX][checkableY] != 0) {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                } else if ((checkableX == (x+1)) && (checkableY == (y+1) || checkableY == (y-1))){
                    if (playerOnBoard[checkableX][checkableY] != 1) {
                        return false;
                    }
                } else {
                    return false;
                }
                if (checkableX == 7) {
                    exchangeOfAPawn(x, y);
                }
            } else {
                return false;
            }
            break;
    default:
        return false;
    }
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

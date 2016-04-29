#include "computer_intelligence.h"

void ComputeIntelligence::findDangerCell() {
    //1-фигура пользователя,2-фигура компьютера,  кратное 5-опасный ход(попадает под бой),
    //кратное 7-фигура пользователя(которая стоит под защитой другой фигуры),
    //кратное 8-фигура компа(которая стоит под защитой другой фигуры)

    arr->whoAtackKing[0] = 0;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            arr->unwantedMove[x][y] = 0;
            arr->figureKillers[x][y][0] = 0;
        }
    }
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (arr->playerOnBoard[x][y] != gui.idComputer) {

            } else if (arr->playerOnBoard[x][y] == gui.idComputer) {
                if (arr->unwantedMove[x][y] == 0) {
                    arr->unwantedMove[x][y] = 2;
                }
                gui.allPossibleMove(x, y, arr->figuresOnBoard[x][y], gui.idComputer);

                for (int count = 0; count < arr->counterWhereMove; count++) {
                    if (arr->playerOnBoard[arr->whereMove[count][0]][arr->whereMove[count][1]] == gui.idComputer
                        && (arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] == 0
                        || arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] == 2))
                    {
                        arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] = 8;
                    }
                    else if (arr->playerOnBoard[arr->whereMove[count][0]][arr->whereMove[count][1]] == gui.idComputer
                             && arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] > 0
                             && arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] % 8 == 0)
                    {
                        arr->unwantedMove[arr->whereMove[count][0]][arr->whereMove[count][1]] += 8;
                    }
                }
            } else {

            }
        }
    }
}

int ComputeIntelligence::priceFigure(int x, int y) {
    switch(arr->figuresOnBoard[x][y]){
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 1;
        default:
            return 0;
    }
}

int ComputeIntelligence::priceFigure(int figure) {
    switch(figure){
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 1;
        default:
            return 0;
    }
}

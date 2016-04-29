#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include <QPalette>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QRect>
#include <QPoint>

#include <QTextStream>

const int cellWidth = 50;
const int cellHeight = 50;

class AllArrays : public QObject {
    Q_OBJECT

public:
    QPushButton cellButtons[8][8];
    QIcon figureImage[2][6] = {{             //Массив с обьектами изображений фигур
                            QPixmap(QDir::currentPath() + "/image/ladyaW.png"),
                            QPixmap(QDir::currentPath() + "/image/horseW.png"),
                            QPixmap(QDir::currentPath() + "/image/oficerW.png"),
                            QPixmap(QDir::currentPath() + "/image/damaW.png"),
                            QPixmap(QDir::currentPath() + "/image/korolW.png"),
                            QPixmap(QDir::currentPath() + "/image/peshkaW.png")},

                            {QPixmap(QDir::currentPath() + "/image/ladyaB.png"),
                            QPixmap(QDir::currentPath() + "/image/horseB.png"),
                            QPixmap(QDir::currentPath() + "/image/oficerB.png"),
                            QPixmap(QDir::currentPath() + "/image/damaB.png"),
                            QPixmap(QDir::currentPath() + "/image/korolB.png"),
                            QPixmap(QDir::currentPath() + "/image/peshkaB.png")}};

    int figuresOnBoard[8][8];
    int playerOnBoard[8][8];
    int startFilling[8] = { 1, 2, 3, 4, 5, 3, 2, 1};        //Начальная расстановка фигур

    int unwantedMove[8][8];                             //Опасные хода
    int whereMove[100][2];                              //Возможные хода
    int whoAtackKing[25];
    int figureKillers[8][8][25];

    int counterWhereMove = 0;
    int shah = 0;
};

class GUI : public QObject  {
    Q_OBJECT

public:
    AllArrays arr;
    QWidget* mainWidj;
    QGridLayout* mainLay;

    int playerWhoMakesMove = 1; //игрок который делает ход, первым ходят белые
    int click = 0;          //Отвечает за распознавание выбора начальнойпозиции или позиции на которую ходим
    int startX = 0;         //Координаты фигуры которой хотим походить
    int startY = 0;         //
    int nextX = 0;          //Координаты клетки на которую хотим походить
    int nextY = 0;          //
    int idComputer = 1;

    void createGUI();
    bool checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY);
    void initialFilling();
    void moveOneStep(int x, int y, int checkableX, int checkableY);
    void exchangeOfAPawn(int x, int y);

    void allPossibleMove(int x, int y, int figure, int player);


public slots:
    void startComputeWay();
};

#endif // MAINWINDOW_H

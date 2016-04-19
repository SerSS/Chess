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


class GUI : public QObject  {
    Q_OBJECT

public:
    QWidget* mainWidj;
    QGridLayout* mainLay;
    QPushButton cellButtons[8][8];

    QIcon pixmap[2][6] = {{             //Массив с обьектами изображений фигур
                            QPixmap(QDir::currentPath() + "/image/ladyaB.png"),
                            QPixmap(QDir::currentPath() + "/image/horseB.png"),
                            QPixmap(QDir::currentPath() + "/image/oficerB.png"),
                            QPixmap(QDir::currentPath() + "/image/damaB.png"),
                            QPixmap(QDir::currentPath() + "/image/korolB.png"),
                            QPixmap(QDir::currentPath() + "/image/peshkaB.png")},

                            {QPixmap(QDir::currentPath() + "/image/ladyaW.png"),
                             QPixmap(QDir::currentPath() + "/image/horseW.png"),
                             QPixmap(QDir::currentPath() + "/image/oficerW.png"),
                             QPixmap(QDir::currentPath() + "/image/damaW.png"),
                             QPixmap(QDir::currentPath() + "/image/korolW.png"),
                             QPixmap(QDir::currentPath() + "/image/peshkaW.png")}
                        };

    int figuresOnBoard[8][8];
    int playerOnBoard[8][8];
    int startFilling[8] = { 1, 2, 3, 4, 5, 3, 2, 1};        //Начальная расстановка фигур

    int click = 0;          //Отвечает за распознавание выбора начальнойпозиции или позиции на которую ходим
    int startX = 0;         //Координаты фигуры которой хотим походить
    int startY = 0;         //
    int nextX = 0;          //Координаты клетки на которую хотим походить
    int nextY = 0;          //

    void createGUI();
    void checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY);
    void initialFilling();
    void moveOneStep(int x, int y, int checkableX, int checkableY);
    void exchangeOfAPawn(int x, int y);

public slots:
    void startComputeWay();
};

#endif // MAINWINDOW_H

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

//int figuresOnBoard[8][8];
//int playerOnBoard[8][8];
<<<<<<< HEAD
=======

>>>>>>> Sima

class GUI : public QObject  {
    Q_OBJECT

public:
    QWidget* mainWidj;
    QGridLayout* mainLay;
    QPushButton cellButtons[8][8];

    int figuresOnBoard[8][8];
    int playerOnBoard[8][8];
<<<<<<< HEAD
=======
    int startFilling[8] = { 1, 2, 3, 4, 5, 3, 2, 1};
>>>>>>> Sima

    void createGUI();
    void checkThePossibilityOfStep(int x, int y, int checkableX, int checkableY);
    void initialFilling();

public slots:
    void startComputeWay();
};

#endif // MAINWINDOW_H

#include "mainwindow.h"

void GUI::createGUI() {
    mainWidj = new QWidget;
    mainLay = new QGridLayout;

    //Перемещает главное окно в центр экрана
    QDesktopWidget desktop;
        QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
        QPoint center = rect.center(); //координаты центра экрана
        center.setX(center.x() - (mainWidj->width()/2));  // учитываем половину ширины окна
        center.setY(center.y() - (mainWidj->height()/2));  // .. половину высоты
        mainWidj->move(center);
    mainLay->setSpacing(0);
    mainWidj->setLayout(mainLay);

    QPalette* palette1 = new QPalette();
    palette1->setColor(QPalette::ButtonText, Qt::transparent);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            mainLay->addWidget(&cellButtons[i][j], i, j);

            cellButtons[i][j].setText(QString::number(i) + QString::number(j));
            cellButtons[i][j].setPalette(*palette1);
            cellButtons[i][j].setFocusPolicy(Qt::NoFocus);
            cellButtons[i][j].setFixedSize(cellWidth, cellHeight);

            if (i % 2 == 0)             //Изменяем цвет клеток на белый и чёрный
            {
                if (j % 2 == 0) cellButtons[i][j].setStyleSheet(QString::fromUtf8(
                                                                    "background-color: black;"));
                else cellButtons[i][j].setStyleSheet(QString::fromUtf8(
                                                         "background-color: white;"));
            }
            else {
                if (j % 2 == 0) cellButtons[i][j].setStyleSheet(QString::fromUtf8(
                                                                    "background-color: white;"));
                else cellButtons[i][j].setStyleSheet(QString::fromUtf8(
                                                         "background-color: black;"));
            }

            cellButtons[i][j].connect(&cellButtons[i][j], SIGNAL(clicked()), this, SLOT(startComputeWay()));
            cellButtons[i][j].show();
    }

    mainWidj->show();
    }
}
void GUI::startComputeWay() {
    QObject* obj = QObject::sender();
    QPushButton* sendBut = (QPushButton*)obj;

    std::string strText = sendBut->text().toStdString();
    const char buttonText[] = {(const char)strText[0], (const char)strText[1]};

    int first = (int)buttonText[0] - 48;
    int second = (int)buttonText[1] - 48;

    //checkThePossibilityOfStep();

    //QTextStream cout(stdout);
    //cout << QString(QString::number(first)) << "-" << QString(QString::number(second));
    //cellButtons[first][second].setStyleSheet(QString::fromUtf8("background-color: blue;"));
}

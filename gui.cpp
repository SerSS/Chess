#include "mainwindow.h"

void GUI::createGUI() {         //Создание главного окна
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

    for(int i=0; i<8; i++){         //Добавление кнопок на главное окно
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
    }
    initialFilling();
    mainWidj->show();
}
void GUI::startComputeWay() {
    QTextStream cout(stdout);
    QObject* obj = QObject::sender();
    QPushButton* sendBut = (QPushButton*)obj;

    std::string strText = sendBut->text().toStdString();
    const char buttonText[] = {(const char)strText[0], (const char)strText[1]};

    int first = (int)buttonText[0] - 48;
    int second = (int)buttonText[1] - 48;

    if(click == 0){     //Если выбираем фигуру которой хотим походить, то записываем координаты  выбранной фигуры
        click = 1;
        startX = first;
        startY = second;
    }
    else if(click == 1){     //Записываем координаты клетки на которую хотим
        nextX = first;          //походить и вызываем проверку возможности этого хода
        nextY = second;
        if (checkThePossibilityOfStep(startX, startY, nextX, nextY)) {
            moveOneStep(startX, startY, nextX, nextY);
        }
        click = 0;
    }
    //QTextStream cout(stdout);
    //cout << QString(QString::number(first)) << "-" << QString(QString::number(second));
}

void GUI::initialFilling() {        //Начальное размещение фигур на доске
    QTextStream cout(stdout);
    int k = 7;
    for(int i=0; i<8; i++){
        figuresOnBoard[0][i] = startFilling[i];
        figuresOnBoard[1][i] = 6;
        figuresOnBoard[6][i] = 6;
        figuresOnBoard[7][i] = startFilling[k];

        playerOnBoard[0][i] = 2;
        playerOnBoard[1][i] = 2;
        playerOnBoard[6][i] = 1;
        playerOnBoard[7][i] = 1;
        k--;
    }
    for(int i=2; i<6; i++){
        for(int j=0; j<8; j++){
            figuresOnBoard[i][j] = 0;
            playerOnBoard[i][j] = 0;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << figuresOnBoard[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i<8; i++){//Отображаем картинку
        for(int j=0; j<8; j++){
            if(playerOnBoard[i][j]<=0 || figuresOnBoard[i][j]<=0) continue;
            else {
                cellButtons[i][j].setIcon(figureImage[playerOnBoard[i][j]-1][figuresOnBoard[i][j]-1]);
                cellButtons[i][j].setIconSize(cellButtons[i][j].size());
            }
        }
    }
}

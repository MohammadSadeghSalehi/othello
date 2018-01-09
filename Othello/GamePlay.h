//
// Created by mss on 1/6/18.
//

#ifndef OTHELLO_GAMEPLAY_H
#define OTHELLO_GAMEPLAY_H
#include <QWidget>
#include <QtWidgets>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qtextedit.h>
#include <cstring>

using namespace std;

class GamePlay : public QWidget {

Q_OBJECT

public:
    GamePlay(int height,int width,QWidget *parent=0);
    ~GamePlay();
    void checkValid();
public slots:


private:
    QLabel *plate[8][8];
    QPushButton *piece[8][8];
    QChar cScore='0',pScore='0';
    QString str1= "cpu score: ",str2="player score: ";
    QLabel *cpuScore;
    QLabel *playerScore;
};

#endif //OTHELLO_GAMEPLAY_H

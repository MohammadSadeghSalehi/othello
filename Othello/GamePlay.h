//
// Created by mss on 1/6/18.
//

#ifndef OTHELLO_GAMEPLAY_H
#define OTHELLO_GAMEPLAY_H
#include <QWidget>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtextedit.h>

using namespace std;

class GamePlay : public QWidget {

Q_OBJECT

public:
    GamePlay(int height,int width,QWidget *parent=0);
    ~GamePlay();
public slots:


private:


};

#endif //OTHELLO_GAMEPLAY_H

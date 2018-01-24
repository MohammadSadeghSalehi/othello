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
    void paint();
    void changeB(int,int);
    void changeW(int,int);
    void hint();
    void reset(int,int);
    void run();
    void cpu();

public slots:
void click00();void click01();void click02();void click03();void click04();void click05();void click06();void click07();
void click10();void click11();void click12();void click13();void click14();void click15();void click16();void click17();
void click20();void click21();void click22();void click23();void click24();void click25();void click26();void click27();
void click30();void click31();void click32();void click33();void click34();void click35();void click36();void click37();
void click40();void click41();void click42();void click43();void click44();void click45();void click46();void click47();
void click50();void click51();void click52();void click53();void click54();void click55();void click56();void click57();
void click60();void click61();void click62();void click63();void click64();void click65();void click66();void click67();
void click70();void click71();void click72();void click73();void click74();void click75();void click76();void click77();

private:
    QLabel *plate[8][8];
    QPushButton *piece[8][8];
    int handler[8][8];
    int temp[8][8];
    QChar cScore='0',pScore='0';
    QString str1= "cpu score: ",str2="player score: ";
    QLabel *cpuScore;
    QLabel *playerScore;
    int counter=0;
};

#endif //OTHELLO_GAMEPLAY_H

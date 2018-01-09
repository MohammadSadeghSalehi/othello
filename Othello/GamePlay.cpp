//
// Created by Mohammad Sadegh Salehi.
//
#include "GamePlay.h"
#include <string>
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/QApplication>
using namespace std;


GamePlay::GamePlay(int height, int width, QWidget *parent) {
    this -> setGeometry( width ,  height , width, height);
    QPalette palette1 = palette();
    palette1.setColor(QPalette::Background, Qt::darkBlue);
    this->setAutoFillBackground(true);
    this->setPalette(palette1);

    str1=str1+cScore;
    str2=str2+pScore;
    cpuScore=new QLabel(str1,this);
    cpuScore->setGeometry(50,10,120,40);
    cpuScore->setStyleSheet("background-color: gray;border-radius:10px;");
    cpuScore->setAlignment(Qt::AlignCenter);
    playerScore=new QLabel(str2,this);
    playerScore->setGeometry(330,10,120,40);
    playerScore->setStyleSheet("background-color: gray;border-radius:10px;");
    playerScore->setAlignment(Qt::AlignCenter);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            piece[i][j]= new QPushButton(this);
            piece[i][j]->setGeometry(50+(j*50),100+(50*i),50,50);
            piece[i][j]->setStyleSheet("background-color: green;border: 0.5px solid black;");

            plate[i][j]= new QLabel(this);
            plate[i][j]->setGeometry(52+(j*50),102+(50*i),46,46);
            plate[i][j]->setStyleSheet("background-color: rgba(0,0,0,0%);border-radius:25px;");
        }
    }
    plate[3][3]->setStyleSheet("background-color: white;border-radius:23px;");
    plate[4][3]->setStyleSheet("background-color: black;border-radius:23px;");
    plate[3][4]->setStyleSheet("background-color: black;border-radius:23px;");
    plate[4][4]->setStyleSheet("background-color: white;border-radius:23px;");
}


GamePlay::~GamePlay() {

}

void GamePlay::checkValid() {

}

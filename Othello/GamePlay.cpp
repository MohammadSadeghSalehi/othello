//
// Created by Mohammad Sadegh Salehi.
//
#include "GamePlay.h"
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/QApplication>



GamePlay::GamePlay(int height, int width, QWidget *parent) {
    this -> setGeometry( width ,  height , width, height);

}


GamePlay::~GamePlay() {

}

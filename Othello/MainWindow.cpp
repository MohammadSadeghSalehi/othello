//
// Created by Mohammad Sadegh Salehi.
//

#include "MainWindow.h"
#include <QtCore/qcoreapplication.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(500, 600);
    QPalette palette1 = palette();
    palette1.setColor(QPalette::Background, Qt::darkGreen);
    this->setAutoFillBackground(true);
    this->setPalette(palette1);

    l1=new QLabel("Othello",this);
    l1->setGeometry(100,50,300,100);
    l1->setStyleSheet("background-color: rgba(0,0,0,0%);color: black;font: bold 50px;");
    l1->setAlignment(Qt::AlignCenter);

    startButton = new QPushButton("Start Game", this);
    startButton->setGeometry(100, 200, 300, 100);
    startButton->setStyleSheet("background-color: black;color: white;font: bold 20px;border-style:outset;border-radius:15px;");

    exit = new QPushButton("EXIT", this);
    exit->setGeometry(100, 350, 300, 100);
    exit->setStyleSheet("background-color: black;color: white;font: bold 20px;border-style:outset;border-radius:15px;");

    l2=new QLabel("Created by Mohammad Sadegh Salehi",this);
    l2->setGeometry(50,500,400,100);
    l2->setStyleSheet("background-color: rgba(0,0,0,0%);color: blue;font: bold 20px;");
    l2->setAlignment(Qt::AlignCenter);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(exit, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));
}

void MainWindow::start() {
    this->hide();
    GamePlay *gamePlay = new GamePlay(600,500);
    gamePlay->show();
}

MainWindow::~MainWindow() {
    disconnect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    disconnect(exit, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));

    delete startButton;
    delete exit;
}
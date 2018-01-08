
#ifndef EXAMPLE_MAINWINDOW_H
#define EXAMPLE_MAINWINDOW_H

#include <QtWidgets>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtextedit.h>
#include "GamePlay.h"

using namespace std;

class MainWindow : public QMainWindow {

Q_OBJECT

public:
    MainWindow(QWidget * = 0);
    ~MainWindow();

public slots:
    void start();

private:
    QPushButton *exit;
    QPushButton *startButton;
    QLabel *l1;
    QLabel *l2;
};


#endif //EXAMPLE_MAINWINDOW_H
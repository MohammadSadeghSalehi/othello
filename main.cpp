#include <iostream>
#include <QtWidgets/qapplication.h>
#include "MainWindow.h"
#include "GamePlay.h"

using namespace std;
int main(int argc, char **argv) {
    QApplication myApp(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return myApp.exec();
}
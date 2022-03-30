#include "mainwindow.h"
#include <QApplication>

Game* game;
MainWindow* mainWin;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    mainWin = new MainWindow();
    mainWin->show();

    //game = new Game();
    //game->show();

    return a.exec();
}

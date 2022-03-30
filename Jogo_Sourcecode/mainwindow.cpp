#include "mainwindow.h"
#include "ui_mainwindow.h"

extern Game* game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Lonely St.");

    QPixmap pix(":/src/mainwin.png");
    int w = ui->back->width();
    int h = ui->back->height();
    ui->back->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    about = new About();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Jogar_clicked()
{
    start_game();
}

void MainWindow::start_game()
{
    game = new Game();
    game->show();
    this->close();
}


void MainWindow::on_Sair_clicked()
{
    close();
}


void MainWindow::on_Sobre_clicked()
{
    about->show();
}


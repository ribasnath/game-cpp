#include "resetgame.h"
#include "ui_resetgame.h"

extern Game* game;
extern MainWindow* mainWin;

resetGame::resetGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetGame)
{
    ui->setupUi(this);

    // 1 = game over; 2 = ganhou
    if(game->mens == 1)
    {
        ui->message->setText("<font color='red'>Game Over!</font>");
    }
    if(game->mens == 2)
    {
        ui->message->setText("<font color='green'>Você ganhou!</font>");
    }
}

resetGame::~resetGame()
{
    delete ui;
}

void resetGame::on_exit_clicked()
{
    game->close();
    close();
}


void resetGame::on_playAgain_clicked()
{
    game->close();
    delete game;
    mainWin->show();
    close();
}


#ifndef RESETGAME_H
#define RESETGAME_H

#include <QDialog>

#include "game.h"
#include "mainwindow.h"

namespace Ui {
class resetGame;
}

class resetGame : public QDialog
{
    Q_OBJECT

public:
    explicit resetGame(QWidget *parent = nullptr);
    ~resetGame();

private slots:
    void on_exit_clicked();

    void on_playAgain_clicked();

private:
    Ui::resetGame *ui;
};

#endif // RESETGAME_H

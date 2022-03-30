#include <QFont>
#include "game.h"
#include "level2.h"

extern Game* game;

Level2::Level2(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    lv2g = 0;
    lv2rino = 0;
    flaglv2 = 0;

    setPlainText(QString("Mate 10 fantasmas: ") + QString::number(lv2g) + QString("\nMate 3 rinos: ") + QString::number(lv2rino));
    setDefaultTextColor(Qt::black);
    setFont(QFont("minecraft", 14));
}

void Level2::lvl2(int n)
{
    // Avisa que atingiu ghost
    if(n == 1)
    {
        if(lv2g < 10 && lv2rino < 3)
        {
            lv2g++;
            setPlainText(QString("Mate 10 fantasmas: ") + QString::number(lv2g) + QString("\nMate 3 rinos: ") + QString::number(lv2rino));
            setDefaultTextColor(Qt::black);
            setFont(QFont("minecraft", 14));
        }
        else if(lv2g < 10 && lv2rino == 3)
        {
            lv2g++;
            setPlainText(QString("Mate 10 fantasmas: ") + QString::number(lv2g));
        }
        else if(lv2g == 10 && lv2rino < 3)
            setPlainText(QString("\nMate 3 rinos: ") + QString::number(lv2rino));
    }

    // Avisa que atingiu Rino
    else if(n == 2)
    {
        if(lv2g < 10 && lv2rino < 3)
        {
            lv2rino++;
            setPlainText(QString("Mate 10 fantasmas: ") + QString::number(lv2g) + QString("\nMate 3 rinos: ") + QString::number(lv2rino));
            setDefaultTextColor(Qt::black);
            setFont(QFont("minecraft", 14));
        }
        else if(lv2g < 10 && lv2rino == 3)
        {
            setPlainText(QString("Mate 10 fantasmas: ") + QString::number(lv2g));
        }
        else if(lv2g == 10 && lv2rino < 3)
        {
            lv2rino++;
            setPlainText(QString("\nMate 3 rinos: ") + QString::number(lv2rino));
        }
    }

    if(lv2g == 10 && lv2rino == 3)
    {
        setPlainText(QString(""));
        flaglv2 = 1;
    }

    if(flaglv2 == 1)
    {
        if(game->player->pos().x() < 740)
        {
            flaglv2 = 0;
            game->timerFofo->stop();
            game->timer->stop();
            game->mens = 2;
            game->gameOver();
        }
    }
}

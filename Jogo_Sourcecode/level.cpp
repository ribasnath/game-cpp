#include <QFont>
#include "level.h"
#include "game.h"

extern Game* game;

Level::Level(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    lv1g = 0;
    lv1sl = 0;
    flaglv1 = 0;

    setPlainText(QString("Mate 5 fantasmas: ") + QString::number(lv1g) + QString("\nMate 5 slimes: ") + QString::number(lv1sl));
    setDefaultTextColor(Qt::black);
    setFont(QFont("minecraft", 14));
}

void Level::lvl1(int n)
{
    // Avisa que atingiu ghost
    if(n == 1)
    {
        if(lv1g < 5 && lv1sl < 5)
        {
            lv1g++;
            setPlainText(QString("Mate 5 fantasmas: ") + QString::number(lv1g) + QString("/5") + QString("\nMate 5 slimes: ") + QString::number(lv1sl) + QString("/5"));
            setDefaultTextColor(Qt::black);
            setFont(QFont("minecraft", 14));
        }
        else if(lv1g < 5 && lv1sl == 5)
        {
            lv1g++;
            setPlainText(QString("Mate 5 fantasmas: ") + QString::number(lv1g) + QString("/5"));
        }
        else if(lv1g == 5 && lv1sl < 5)
            setPlainText(QString("\nMate 5 slimes: ") + QString::number(lv1sl) + QString("/5"));
    }

    // Avisa que atingiu slime
    else if(n == 2)
    {
        if(lv1sl < 5 && lv1g < 5)
        {
            lv1sl++;
            setPlainText(QString("Mate 5 fantasmas: ") + QString::number(lv1g) + QString("/5") + QString("\nMate 5 slimes: ") + QString::number(lv1sl) + QString("/5"));
            setDefaultTextColor(Qt::black);
            setFont(QFont("minecraft", 14));
        }
        else if(lv1sl < 5 && lv1g == 5)
        {
            lv1sl++;
            setPlainText(QString("\nMate 5 slimes: ") + QString::number(lv1sl) + QString("/5"));
        }
        else if(lv1sl == 5 && lv1g < 5)
            setPlainText(QString("Mate 5 fantasmas: ") + QString::number(lv1g) + QString("/5"));
    }

    if(lv1g == 5 && lv1sl == 5 && flaglv1 == 0)
    {
        setPlainText(QString(""));
        flaglv1 = 1;
    }

    if(flaglv1 == 1)
    {
        if(game->player->pos().x() < 740)
        {
            flaglv1 = 0;
            game->timerFofo->stop();
            game->timer->stop();
            game->nextLevel();
            game->upLevel();
        }
    }
}

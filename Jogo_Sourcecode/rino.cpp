#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

#include "rino.h"
#include "game.h"

extern Game* game;

Rino::Rino()
{
    setPos(0,290);

    setPixmap(QPixmap(":/src/enemies/rino/rino004.png"));

    QTimer* timerR = new QTimer();
    connect(timerR, SIGNAL(timeout()), this, SLOT(move()));

    timerR->start(20);
}

void Rino::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();

    for(int i=0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i])) == typeid(Player))
        {
            game->mens = 1;
            game->health->setHealth(0);
            game->gameOver();
            scene()->removeItem(this);
            return;
        }
    }

    setPos(x()+10,y());

    if(pos().y() > 800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy removed";
    }
}

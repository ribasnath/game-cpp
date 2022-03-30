#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

#include "snail.h"
#include "game.h"

extern Game* game;

Snail::Snail()
{
    setPos(0,290);

    setPixmap(QPixmap(":/src/enemies/snail/snail009.png"));

    QTimer* timerSn = new QTimer();
    connect(timerSn, SIGNAL(timeout()), this, SLOT(move()));

    timerSn->start(70);
}

void Snail::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();

    for(int i=0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i])) == typeid(Player))
        {
            if(game->health->getHealth() > 1)
            {
                game->health->decrease();
                scene()->removeItem(this);
            }
            else
            {
                game->mens = 1;
                game->gameOver();
                scene()->removeItem(this);
                //delete this;
            }
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

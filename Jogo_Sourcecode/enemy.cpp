#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

#include "enemy.h"
#include "game.h"

extern Game* game;

Enemy::Enemy()
{
    //int random_number = rand() % 700;
    setPos(800,270);

    setPixmap(QPixmap(":/src/enemies/ghost/006.png"));

    QTimer* timerG = new QTimer();
    connect(timerG, SIGNAL(timeout()), this, SLOT(move()));

    timerG->start(30);
}

void Enemy::move()
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

    setPos(x()-10,y());

    if(pos().y() > 800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy removed";
    }
}

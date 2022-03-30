//#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>

#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include "slime.h"
#include "snail.h"
#include "rino.h"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/src/char/magpow.png"));

    if(game->getLevel() == 1)
    {
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(50);
    }
    else if(game->getLevel() == 2)
    {
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move2()));
        timer->start(50);
    }
    else if(game->getLevel() == 3)
    {
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move3()));
        timer->start(50);
    }
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();

    for(int i=0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i])) == typeid(Enemy))
        {
            game->score->increase(3);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            game->level->lvl1(1);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Slime))
        {
            game->score->increase(2);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            game->level->lvl1(2);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Snail))
        {
            game->score->increase(1);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Rino))
        {
            game->score->increase(5);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }
    }

    setPos(x()-20,y());

    if(pos().x() < +10)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet removed";
    }
}

void Bullet::move2()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();

    for(int i=0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i])) == typeid(Enemy))
        {
            game->score->increase(3);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            game->level2->lvl2(1);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Slime))
        {
            game->score->increase(2);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Snail))
        {
            game->score->increase(1);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }
        else if(typeid(*(colliding_item[i])) == typeid(Rino))
        {
            game->score->increase(5);
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            game->level2->lvl2(2);

            delete colliding_item[i];
            delete this;
            return;
        }
    }

    setPos(x()-20,y());

    if(pos().x() < +10)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet removed";
    }
}

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

#include "game.h"
#include "fofinho.h"

extern Game* game;

Fofinho::Fofinho()
{
    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/src/cloud.png"));

    QTimer* timerG = new QTimer();
    connect(timerG, SIGNAL(timeout()), this, SLOT(move()));

    timerG->start(30);
}

void Fofinho::move()
{
    setPos(x(), y()+5);

     if(pos().y() > 400)
     {
         scene()->removeItem(this);
         delete this;
     }

     QList<QGraphicsItem *> colliding_item = collidingItems();

     for(int i=0, n=colliding_item.size(); i<n; i++)
     {
         if(typeid(*(colliding_item[i]))== typeid(Player))
         {
             game->score->increase(4);
             scene()->removeItem(this);

             delete this;
             return;
         }
     }

     if(pos().y() > 290)
     {
         game->Fcaiu->decreaseCaiu();
         scene()->removeItem(this);
         delete this;
         qDebug() << "Fofinho removed";
     }
}

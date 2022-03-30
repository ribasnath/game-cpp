#include "health.h"

#include <QFont>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("minecraft", 14));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("minecraft", 14));
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth(int h)
{
    health = h;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("minecraft", 14));
}

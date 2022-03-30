#ifndef BULLET_H
#define BULLET_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent=0);

public slots:
    void move();
    void move2();
};

#endif // BULLET_H

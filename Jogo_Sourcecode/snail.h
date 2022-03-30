#ifndef SNAIL_H
#define SNAIL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Snail : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Snail();

public slots:
    void move();
};

#endif // SNAIL_H

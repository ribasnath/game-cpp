#ifndef SLIME_H
#define SLIME_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Slime : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Slime();

public slots:
    void move();
};

#endif // SLIME_H

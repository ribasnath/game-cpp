#ifndef RINO_H
#define RINO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Rino : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Rino();

public slots:
    void move();
};

#endif // RINO_H

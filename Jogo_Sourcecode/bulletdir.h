#ifndef BULLETDIR_H
#define BULLETDIR_H

#include <QGraphicsPixmapItem>
#include <QObject>

class bulletdir : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bulletdir(QGraphicsItem* parent=0);

public slots:
    void move();
    void move2();
};

#endif // BULLETDIR_H

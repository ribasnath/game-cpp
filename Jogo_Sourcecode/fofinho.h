#ifndef FOFINHO_H
#define FOFINHO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Fofinho : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fofinho();
    int caiu;

public slots:
    void move();
};

#endif // FOFINHO_H

#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "bullet.h"

class Level : public QGraphicsTextItem
{
public:
    Level(QGraphicsItem* parent=0);
    void lvl1(int n);

    // vai verificar se a missão tá completa
    int flaglv1;

private:
    int lv1g;
    int lv1sl;    
};

#endif // LEVEL_H

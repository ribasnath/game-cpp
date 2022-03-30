#ifndef LEVEL2_H
#define LEVEL2_H

#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "bullet.h"

class Level2 : public QGraphicsTextItem
{
public:
    Level2(QGraphicsItem* parent=0);
    void lvl2(int n);

private:
    int lv2g;
    int lv2rino;

    // vai verificar se a missão tá completa
    int flaglv2;
};

#endif // LEVEL2_H

#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include "bulletdir.h"
#include "enemy.h"
#include "slime.h"
#include "snail.h"
#include "fofinho.h"
#include "rino.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);

    Enemy* enemy;
    Slime* slime;
    Snail* snail;
    Fofinho* fofinho;
    Rino* rino;

public slots:
    void spawn();
    void spawnFofo();

private:
    QMediaPlayer* bulletsound;
    int l;
};

#endif // PLAYER_H

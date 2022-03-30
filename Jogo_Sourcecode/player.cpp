#include "player.h"
//#include "bullet.h"
//#include "bulletdir.h"
//#include "enemy.h"
//#include "slime.h"
//#include "snail.h"
//#include "fofinho.h"
//#include "rino.h"

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/src/char/mag_d.png"));

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/src/Laser.mp3"));
    bulletsound->setVolume(10);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key press detected";

    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
            setPos(x()-10, y());

        setPixmap(QPixmap(":/src/char/mag_a.png"));

        l = 1;
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()+100 < 800)
            setPos(x()+10, y());

        setPixmap(QPixmap(":/src/char/mag_d.png"));

        l = 2;
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPixmap(QPixmap(":/src/char/mag_w.png"));
    }
    else if(event->key() == Qt::Key_Down)
    {
        //setPos(x(), y()+10);
        setPixmap(QPixmap(":/src/char/mag_s.png"));
    }

    else if(event->key() == Qt::Key_Space && l == 2)
    {
        bulletdir* bullet = new bulletdir();
        bullet->setPos(x()+20, y()+15);
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }

    else if(event->key() == Qt::Key_Space && l == 1)
    {
        Bullet* bullet = new Bullet();
        bullet->setPos(x()-20, y()+15);
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    int sp = rand() % 100;

    if(sp <= 30)
    {
        // Ghost
        enemy = new Enemy();
        scene()->addItem(enemy);
    }
    else if(sp >= 31 && sp <= 61)
    {
        slime = new Slime();
        scene()->addItem(slime);
    }
    else if(sp >= 62 && sp <= 70)
    {
        snail = new Snail();
        scene()->addItem(snail);
    }
    else if(sp >= 71)
    {
        rino = new Rino();
        scene()->addItem(rino);
    }
}

void Player::spawnFofo()
{
    fofinho = new Fofinho();
    scene()->addItem(fofinho);
}

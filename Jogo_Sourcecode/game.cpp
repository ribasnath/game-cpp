#include <QGraphicsTextItem>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <qstyle.h>
#include <QDebug>

#include "game.h"
#include "enemy.h"

#include "resetgame.h"

Game::Game(QWidget* parent)
{
    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,800,400);
    scene->setBackgroundBrush(QBrush(QImage(":/src/background.png")));

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,400);

    player = new Player();
    player->setPos(200,270);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    timerFofo = new QTimer();
    QObject::connect(timerFofo, SIGNAL(timeout()), player, SLOT(spawnFofo()));
    timerFofo->start(1700);

    score = new Score();
    score->setPos(score->x()+10, score->y()+15);
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+10, health->y()+35);
    scene->addItem(health);

    Fcaiu = new FofinhoCaiu();
    Fcaiu->setPos(health->x()+480, health->y()+35);
    scene->addItem(Fcaiu);

    nextLevel();
    upLevel();

    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/src/music_adv.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* music = new QMediaPlayer(this);
    music->setPlaylist(playlist);
    music->setVolume(10);
    music->play();

    show();
}

void Game::gameOver()
{
    drawPanel(0,0,800,400,Qt::black,0.65);

    timer->stop();
    timerFofo->stop();
    scene->removeItem(player);
    delete player;
    resetGame resg;
    resg.setModal(true);
    resg.exec();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::setLevel(int lv)
{
    nlvl = lv;
}

int Game::getLevel()
{
    return nlvl;
}

void Game::upLevel()
{
    if(nlvl == 1)
    {
        level = new Level();
        level->setPos(level->x()+10, level->y()+90);
        scene->addItem(level);
    }
    else if(nlvl == 2)
    {
        health->setHealth(5);
        Fcaiu->setCaiu(10);
        player->setPos(200,270);
        timer->start(1600);
        timerFofo->start(1650);
        level2 = new Level2();
        level2->setPos(level2->x()+10, level2->y()+90);
        scene->addItem(level2);
        qDebug() << getLevel();
    }
}

void Game::nextLevel()
{
    nlvl++;
}








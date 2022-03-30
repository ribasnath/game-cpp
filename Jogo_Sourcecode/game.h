#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include "player.h"
#include "score.h"
#include "health.h"
#include "fofinhocaiu.h"
#include "level.h"
#include "level2.h"

#include "mainwindow.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=0);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
    FofinhoCaiu* Fcaiu;
    Level* level;
    Level2* level2;
    QTimer* timer;
    QTimer* timerFofo;

    int mens;

    void gameOver();
    void setLevel(int lv);
    int getLevel();
    void upLevel();

   void nextLevel();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    int nlvl = 0;
};

#endif // GAME_H

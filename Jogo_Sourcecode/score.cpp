#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("minecraft", 14));
}

void Score::increase(int n)
{
    // Snail
    if(n == 1)
    {
        score++;
    }
    // Slime
    if(n == 2)
    {
        score += 3;
    }
    // Ghost
    if(n == 3)
    {
        score += 10;
    }
    // Fofinho
    if(n == 4)
    {
        score += 100;
    }
    // Rino
    if(n == 5)
    {
        score += 50;
    }

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("minecraft", 14));
}

int Score::getScore()
{
    return score;
}

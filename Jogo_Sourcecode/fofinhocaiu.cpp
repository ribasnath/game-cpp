#include "fofinhocaiu.h"
#include <QFont>

#include "game.h"

extern Game* game;

FofinhoCaiu::FofinhoCaiu(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    caiu = 15;
    setPlainText(QString("Não deixe o fofinho cair!\nSuas chances: ") + QString::number(caiu));
    setDefaultTextColor(Qt::darkMagenta);
    setFont(QFont("minecraft", 12));
}

void FofinhoCaiu::decreaseCaiu()
{
    caiu--;
    setPlainText(QString("Não deixe o fofinho cair!\nSuas chances: ") + QString::number(caiu));
    setDefaultTextColor(Qt::darkMagenta);
    setFont(QFont("minecraft", 12));

    if(caiu <= 0)
    {
        game->mens = 1;
        game->gameOver();
    }
}

int FofinhoCaiu::getCaiu()
{
    return caiu;
}

void FofinhoCaiu::setCaiu(int c)
{
    caiu = c;
    setPlainText(QString("Não deixe o fofinho cair!\nSuas chances: ") + QString::number(caiu));
    setDefaultTextColor(Qt::darkMagenta);
    setFont(QFont("minecraft", 12));
}

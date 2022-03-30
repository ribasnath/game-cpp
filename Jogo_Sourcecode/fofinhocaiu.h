#ifndef FOFINHOCAIU_H
#define FOFINHOCAIU_H

#include <QGraphicsTextItem>

class FofinhoCaiu : public QGraphicsTextItem
{
public:
    FofinhoCaiu(QGraphicsItem* parent=0);

    int getCaiu();
    void decreaseCaiu();
    void setCaiu(int c);

private:
    int caiu;
};

#endif // FOFINHOCAIU_H

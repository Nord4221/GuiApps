#ifndef ITEMSCONTROLLERTROLLER_H
#define ITEMSCONTROLLERTROLLER_H

#include <QObject>
#include <QVector>
#include "GraphicItem.h"

class ItemsController : public GraphicItem
{
public:
    ItemsController();

private:
    QVector<GraphicItem *> ItemVector;

public slots:
    void SlotCreateGraphicItem(QPointF _LocalPos);
    void SlotDeleteItem(GraphicItem *_itemToDelete);

};

#endif // ITEMSCONTROLLERTROLLER_H

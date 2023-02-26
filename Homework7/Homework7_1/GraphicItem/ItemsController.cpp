#include "ItemsController.h"

ItemsController::ItemsController()
{

}

void ItemsController::SlotDeleteItem(GraphicItem *_itemToDelete)
{

    ItemVector.remove(ItemVector.indexOf(_itemToDelete));

}

void ItemsController::SlotCreateGraphicItem(QPointF _LocalPos)
{
    ItemVector.push_back(new GraphicItem);
    ItemVector.last()->setPos(_LocalPos);
    static FigureForm currentFormState = FigureForm::RECTANGLE;
    switch (currentFormState)
    {
        case FigureForm::RECTANGLE:
            ItemVector.last()->SetFigureFormRectangle();
            currentFormState = FigureForm::ELLIPS;
            break;
        case FigureForm::ELLIPS:
            ItemVector.last()->SetFigureFormEllips();
            currentFormState = FigureForm::STAR;
            break;
        case FigureForm::STAR:
            ItemVector.last()->SetFigureFormStar();
            currentFormState = FigureForm::RECTANGLE;
            break;
    }
    connect(ItemVector.last(), &GraphicItem::SignalItemDeleted, this, &ItemsController::SlotDeleteItem);
    emit SignalItemCreated(ItemVector.last());
}


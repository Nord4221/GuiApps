#include "GraphicItem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

GraphicItem::GraphicItem(QObject *parent) : QObject(parent), QGraphicsItem()
{

    PosX = 0;
    PosY = 0;
    CurrentForm = FigureForm::RECTANGLE;
    FigurePen.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    setPos(0,0);
    emit SignalItemCreated(this);
    emit SignalReDraw();
}

GraphicItem::~GraphicItem()
{
    emit SignalItemDeleted(this);
    emit SignalReDraw();
    this->deleteLater();
}

void GraphicItem::SetFigureFormRectangle()
{
    CurrentForm = FigureForm::RECTANGLE;
}

void GraphicItem::SetFigureFormEllips()
{
    CurrentForm = FigureForm::ELLIPS;
}

void GraphicItem::SetFigureFormStar()
{
    CurrentForm = FigureForm::STAR;
}

void GraphicItem::SetPosition(QPointF _newPos)
{
     setPos(_newPos);
     PosX = _newPos.toPoint().x();
     PosY = _newPos.toPoint().y();
}

void GraphicItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        IsMoving = true;
        FigurePosition = event->pos().toPoint();
    }
    if (event->button() == Qt::RightButton)
    {
        this->~GraphicItem();
    }
}

void GraphicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        IsMoving = false;

        emit SignalReDraw();
    }
}

void GraphicItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (IsMoving)
    {
        QPoint p = event->pos().toPoint() - FigurePosition;
        PosX += p.x();
        PosY += p.y();
        FigurePosition = event->pos().toPoint();
        emit SignalReDraw();
    }
}


void GraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(FigurePen);

    switch (CurrentForm)
    {
        case FigureForm::RECTANGLE:
            painter->drawRect(PosX, PosY, 200, 100);
            break;
        case FigureForm::ELLIPS:
            painter->drawEllipse(PosX, PosY, 200, 100);
            break;
        case FigureForm::STAR:
            painter->drawPolygon(QPolygon() << QPoint(PosX,PosY+100) << QPoint(PosX+40,PosY+40)
                                            << QPoint(PosX+100,PosY) << QPoint(PosX+40,PosY-40)
                                            << QPoint(PosX,PosY-100) << QPoint(PosX-40,PosY-40)
                                            << QPoint(PosX-100,PosY) << QPoint(PosX-40,PosY+40)
                                            << QPoint(PosX,PosY+100)
                                 );
            break;
    }
    Q_UNUSED(option)
    Q_UNUSED(widget)

}

QRectF GraphicItem::boundingRect() const
{
    return QRectF(PosX, PosY, 200, 100);
}

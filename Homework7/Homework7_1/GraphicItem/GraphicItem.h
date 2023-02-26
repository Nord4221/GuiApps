#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QPen>

class GraphicItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPen FigurePen)
public:
    explicit GraphicItem(QObject *parent = nullptr);
    ~GraphicItem() override;
    void SetFigureFormRectangle();
    void SetFigureFormEllips();
    void SetFigureFormStar();
    void GetForm();
    void SetPosition(QPointF _newPos);
signals:
    void SignalReDraw();
    void SignalDoubleClick();
    void SignalItemDeleted(GraphicItem* _currentItem);
    void SignalItemCreated(GraphicItem* _createdItem);

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    enum FigureForm  {RECTANGLE, ELLIPS, STAR};
private:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    int PosX, PosY;
    bool IsMoving = false;
    FigureForm CurrentForm;
    QPen FigurePen;
    QPoint FigurePosition;
};

#endif // GRAPHICITEM_H

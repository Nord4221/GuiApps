#include "SceneWindow.h"
#include "ui_SceneWindow.h"
#include <QGraphicsSceneMouseEvent>
#include "GraphicItem/ItemsController.h"

SceneWindow::SceneWindow(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::SceneWindow)
{
    srand(clock());
    CurrentScene = new QGraphicsScene(this);
    setScene(CurrentScene);

    GraphicItemsController = new ItemsController();
    connect(GraphicItemsController, &ItemsController::SignalItemCreated, this, &SceneWindow::SlotNewItemCreated);
    connect(GraphicItemsController, &ItemsController::SignalItemDeleted, this, &SceneWindow::SlotItemDeleted);
}

SceneWindow::~SceneWindow()
{
    delete ui;
}

void SceneWindow::SlotReDraw()
{
    CurrentScene->update();
    update();
}

void SceneWindow::SlotNewItemCreated(GraphicItem *_newItem)
{
    CurrentScene->addItem(_newItem);
    connect(_newItem, &GraphicItem::SignalReDraw, this, &SceneWindow::SlotReDraw);
}

void SceneWindow::SlotItemDeleted(GraphicItem *_deletedItem)
{
    CurrentScene->removeItem(_deletedItem);
}

void SceneWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        GraphicItemsController->SlotCreateGraphicItem(event->localPos());
    }
}

#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "GraphicItem/ItemsController.h"

namespace Ui {
class SceneWindow;
}

class SceneWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit SceneWindow(QWidget *parent = nullptr);
    ~SceneWindow();
public slots:
    void SlotReDraw();
    void SlotNewItemCreated(GraphicItem *_newItem);
    void SlotItemDeleted(GraphicItem *_deletedItem);

private:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    Ui::SceneWindow *ui;
    QGraphicsScene *CurrentScene;
    ItemsController *GraphicItemsController;
};

#endif // SCENEWINDOW_H

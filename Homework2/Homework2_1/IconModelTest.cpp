#include "IconModelTest.h"
#include "ui_IconModelTest.h"
#include <QFileDialog>

IconModelTest::IconModelTest(QWidget *parent) :
    QMainWindow(parent),
    uiPtr(new Ui::IconModelTest)
{
    uiPtr->setupUi(this);
    ItemModelPtr = new QStandardItemModel(this);
    uiPtr->listViewIconModel->setModel(ItemModelPtr);
    uiPtr->listViewIconModel->setMovement(QListView::Movement::Free);
    uiPtr->listViewIconModel->setResizeMode(QListView::ResizeMode::Adjust);
    uiPtr->listViewIconModel->setFlow(QListView::Flow::TopToBottom);
    uiPtr->listViewIconModel->setDragDropMode(QListView::DragDropMode::InternalMove);
    ItemModelPtr->appendRow(new QStandardItem(QIcon("./CPP_icon.png"),"C++"));
    ItemModelPtr->appendRow(new QStandardItem(QIcon("./PY_icon.png"),"Python"));
    connect(uiPtr->pushButtonAddElement, &QPushButton::clicked, this, &IconModelTest::AddItemToModel);
    connect(uiPtr->pushButtonDeleteElement, &QPushButton::clicked, this, &IconModelTest::RemoveItemFromModel);
    connect(uiPtr->checkBoxViewIconsOnly, &QCheckBox::stateChanged, this, &IconModelTest::ChangeModelView);
}

IconModelTest::~IconModelTest()
{
    delete uiPtr;
}

void IconModelTest::AddItemToModel()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Choose .png file"), "", tr("Images (*.png *.xpm *.jpg)"));
    ItemModelPtr->appendRow(new QStandardItem(QIcon(FileName),"Enter name"));
}

void IconModelTest::RemoveItemFromModel()
{
    ItemModelPtr->removeRow(uiPtr->listViewIconModel->currentIndex().row());
}

void IconModelTest::ChangeModelView()
{
    uiPtr->checkBoxViewIconsOnly->checkState() == Qt::Checked ? uiPtr->listViewIconModel->setViewMode(QListView::ViewMode::IconMode):
                                                                uiPtr->listViewIconModel->setViewMode(QListView::ViewMode::ListMode);

}

#include "CustomFyleSystem.h"
#include "ui_CustomFyleSystem.h"
#include <QDir>

CustomFyleSystem::CustomFyleSystem(QWidget *parent) :
    QWidget(parent),
    UiPtrFs(new Ui::CustomFyleSystem)
{
    UiPtrFs->setupUi(this);
    ModelPtr = new QFileSystemModel(this);
    ModelPtr->setRootPath(QDir::currentPath());
    ModelPtr->setReadOnly(false);

    UiPtrFs->treeViewFileSystem->setModel(ModelPtr);
    UiPtrFs->treeViewFileSystem->setRootIndex(ModelPtr->index(QDir::currentPath()));
    connect(UiPtrFs->treeViewFileSystem, &QTreeView::clicked, this, &CustomFyleSystem::SlotShowCurrentDirPath);
    connect(UiPtrFs->pushButtonSelectFile, &QPushButton::clicked, this, &CustomFyleSystem::SlotFileSelected);
    CustomFyleSystem::show();
}

CustomFyleSystem::~CustomFyleSystem()
{
    delete UiPtrFs;
}

void CustomFyleSystem::SlotShowCurrentDirPath()
{
    UiPtrFs->lineEditCurrentDir->setText(ModelPtr->filePath(UiPtrFs->treeViewFileSystem->currentIndex()));
}

void CustomFyleSystem::SlotFileSelected()
{
    emit SignalCurrentPathFound(ModelPtr->filePath(UiPtrFs->treeViewFileSystem->currentIndex()));
    this->deleteLater();
}

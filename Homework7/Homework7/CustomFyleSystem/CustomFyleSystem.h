#ifndef CUSTOMFYLESYSTEM_H
#define CUSTOMFYLESYSTEM_H

#include <QWidget>
#include <QFileSystemModel>
namespace Ui {
class CustomFyleSystem;
}

class CustomFyleSystem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomFyleSystem(QWidget *parent = nullptr);
    ~CustomFyleSystem();
public slots:
    void SlotShowCurrentDirPath();
    void SlotFileSelected();
signals:
    void SignalCurrentPathFound(QString _CurrentPathStr);
private:
    Ui::CustomFyleSystem *UiPtrFs;
    QFileSystemModel *ModelPtr;
};

#endif // CUSTOMFYLESYSTEM_H

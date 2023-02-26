#ifndef ICONMODELTEST_H
#define ICONMODELTEST_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class IconModelTest;
}

class IconModelTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconModelTest(QWidget *parent = nullptr);
    ~IconModelTest();
    void AddItemToModel();
    void RemoveItemFromModel();
    void ChangeModelView();
private:
    Ui::IconModelTest *uiPtr;
    QStandardItemModel *ItemModelPtr;
};

#endif // ICONMODELTEST_H

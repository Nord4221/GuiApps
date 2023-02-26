#include "TaskWindow.h"
#include "ui_TaskWindow.h"
#include <QStandardItemModel>

TaskWindow::TaskWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaskWindow)
{
    ui->setupUi(this);
    TaskWindow::hide();
}

TaskWindow::~TaskWindow()
{
    delete ui;
}

void TaskWindow::ShowDataBaseTable(QStringList _taskList)
{
    TaskWindow::show();
    QStandardItemModel *model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    QList<QStandardItem*>list;
    for(auto curTask : _taskList)
        list.append(new QStandardItem(curTask));
    model->appendColumn(list);
}

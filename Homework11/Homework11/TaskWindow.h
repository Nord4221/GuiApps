#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QMainWindow>

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaskWindow(QWidget *parent = nullptr);
    ~TaskWindow();
    void ShowDataBaseTable(QStringList _taskList);

private:
    Ui::TaskWindow *ui;
};

#endif // TASKWINDOW_H

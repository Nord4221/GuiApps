#ifndef WINDOWWIDGET_H
#define WINDOWWIDGET_H

#include <QMainWindow>
#include "TextParser.h"

namespace Ui {
class WindowWidget;
}

class WindowWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowWidget(QWidget *parent = nullptr);
    ~WindowWidget();

private:
    Ui::WindowWidget *UiPtr;
    void SlotTextChanged();
    TextParser *ParceTextPtr;

};

#endif // WINDOWWIDGET_H

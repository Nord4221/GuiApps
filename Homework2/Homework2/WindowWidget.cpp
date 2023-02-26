#include "WindowWidget.h"
#include "ui_WindowWidget.h"

WindowWidget::WindowWidget(QWidget *parent) :
    QMainWindow(parent),
    UiPtr(new Ui::WindowWidget)
{
    UiPtr->setupUi(this);
    ParceTextPtr = new TextParser();
    connect(UiPtr->plainTextEditWindow, &QPlainTextEdit::textChanged, this, &WindowWidget::SlotTextChanged);
}

WindowWidget::~WindowWidget()
{
    delete UiPtr;
}

void WindowWidget::SlotTextChanged()
{
    QString str = UiPtr->plainTextEditWindow->toPlainText(); // получаем текст виджета
    if (ParceTextPtr->TextChange(str)) // были ли коды
        UiPtr->plainTextEditWindow->setPlainText(ParceTextPtr->GetText()); // заменяем текст


}

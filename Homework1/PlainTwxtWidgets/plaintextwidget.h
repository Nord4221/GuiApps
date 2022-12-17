#ifndef PLAINTEXTWIDGET_H
#define PLAINTEXTWIDGET_H

#include <QMainWindow>

namespace Ui {
class PlainTextWidget;
}

class PlainTextWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlainTextWidget(QWidget *parent = nullptr);
    ~PlainTextWidget();
    void    ReplaceText();
    void    SwapText();
    void    PrintHTMLText();
private:
    Ui::PlainTextWidget *ui;
    const QString HtmlString = "<fontcolor='red'>Hello</font>";
};

#endif // PLAINTEXTWIDGET_H

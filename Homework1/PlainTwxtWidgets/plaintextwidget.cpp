#include "plaintextwidget.h"
#include "ui_plaintextwidget.h"

PlainTextWidget::PlainTextWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlainTextWidget)
{
    ui->setupUi(this);
    connect(ui->pushButtonReplace,  &QPushButton::clicked,this, &PlainTextWidget::ReplaceText);
    connect(ui->pushButtonSwap,     &QPushButton::clicked,this, &PlainTextWidget::SwapText);
    connect(ui->pushButtonPrintHTML,&QPushButton::clicked,this, &PlainTextWidget::PrintHTMLText);
}

PlainTextWidget::~PlainTextWidget()
{
    delete ui;
}

void PlainTextWidget::ReplaceText()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}

void PlainTextWidget::SwapText()
{
    QString TmpStringHolder = ui->plainTextEdit_2->toPlainText();
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText()); //ReplaceText()
    ui->plainTextEdit->setPlainText(TmpStringHolder);
}

void PlainTextWidget::PrintHTMLText()
{
    ui->plainTextEdit_2->setPlainText(HtmlString.toHtmlEscaped());
}

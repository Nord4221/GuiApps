#include "FilePrinter.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

FilePrinter::FilePrinter(QWidget *parent) : QWidget(parent)
{
    connect(this, &FilePrinter::SignalPrintEnd, this, &FilePrinter::SlotDestroy);
}

FilePrinter::~FilePrinter()
{
    this->deleteLater();
}

void FilePrinter::PrintText(QString *_textPtr)
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print"));
    if (dialog.exec() != QDialog::Accepted)
        return;
    QChar *list = _textPtr->data();
    QStringList strList;
    int line = 0, cursor = 0;
    for (bool getst = true;getst;)
    {
        int index = _textPtr->indexOf("\n", cursor);
        QString s = "";
        if (index == -1)
        {
            getst = false;
            s.append(&list[cursor], _textPtr->length() - cursor);
        }
        else s.append(&list[cursor], index - cursor);
        cursor = index + 1;
        strList << s;
    }

    QPainter painter;
    painter.begin(&printer);
    int windowHeight = painter.window().height();
    int strAmount = strList.count();
    QFont font = painter.font();
    QFontMetrics fmetrics(font);
    for (int i = 0; i < strAmount; i++)
    {
        QPointF pf;
        pf.setX(10);
        pf.setY(line);
        painter.drawText(pf, strList.at(i));
        line += fmetrics.height();
        if (windowHeight - line <= fmetrics.height())
        {
            printer.newPage();
            line = 0;
        }
    }
    painter.end();
    emit SignalPrintEnd();
}

void FilePrinter::SlotPrintFromTextBrowser(QTextBrowser *_browserPtr)
{
    QString textFromBrowser = _browserPtr->toPlainText();
    PrintText(&textFromBrowser);
}

void FilePrinter::SlotDestroy()
{
    this->~FilePrinter();
}

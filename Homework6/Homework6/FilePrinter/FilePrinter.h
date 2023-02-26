#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <QWidget>
#include <QTextBrowser>

class FilePrinter : public QWidget
{
    Q_OBJECT
public:
    explicit FilePrinter(QWidget *parent = nullptr);
    ~FilePrinter();
    void PrintText(QString *_textPtr);
signals:
    void SignalPrintEnd();
public slots:
    void SlotPrintFromTextBrowser(QTextBrowser *_browserPtr);
    void SlotDestroy();
};

#endif // FILEPRINTER_H

#ifndef FILEFINDERDIALOG_H
#define FILEFINDERDIALOG_H

#include <QDialog>

#include "MyThread.h"
#include "FileFinder.h"

namespace Ui {
class FileFinderDialog;
}

class FileFinderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileFinderDialog(QWidget *parent = nullptr);
    ~FileFinderDialog();

public slots:
    void SlotFindFile();
    void SlotFileFound(QString _fileName);
    void SlotReturnToMain();
signals:
    void SignalReturnFileName(QString _dileName);
private:
    MyThread *newTread;
    Ui::FileFinderDialog *UiFindFilePtr;
};

#endif // FILEFINDERDIALOG_H

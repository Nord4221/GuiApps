#include "FileFinderDialog.h"
#include "ui_FileFinderDialog.h"



FileFinderDialog::FileFinderDialog(QWidget *parent) :
    QDialog(parent),
    UiFindFilePtr(new Ui::FileFinderDialog)
{
    UiFindFilePtr->setupUi(this);
    connect(UiFindFilePtr->pushButtonStartSearch, &QPushButton::clicked, this, &FileFinderDialog::SlotFindFile);
    connect(UiFindFilePtr->pushButtonReturnToMainProgram, &QPushButton::clicked, this, &FileFinderDialog::SlotReturnToMain);
    this->show();
}

FileFinderDialog::~FileFinderDialog()
{  
    delete UiFindFilePtr;
    this->deleteLater();
}

void FileFinderDialog::SlotFindFile()
{
    QString searchFileName = UiFindFilePtr->lineEditFileName->text();
    if(!searchFileName.isEmpty())
    {
        newTread = new MyThread();
        FileFinder *fileFinder = new FileFinder(this);

        connect(fileFinder, &FileFinder::SignalValueChanged,UiFindFilePtr->progressBar, &QProgressBar::setValue);
        connect(fileFinder, &FileFinder::SignalMaximumValueChanged,UiFindFilePtr->progressBar, &QProgressBar::setMaximum);
        connect(fileFinder, &FileFinder::SignalFileNameFound,this, &FileFinderDialog::SlotFileFound);
        fileFinder->moveToThread(newTread);
        newTread->start();
        fileFinder->SlotStartSearch(searchFileName);
        UiFindFilePtr->lineEditSearchResult->setText(tr("Searching ") + searchFileName);
    }
    else
    {
        UiFindFilePtr->lineEditSearchResult->setText(tr("Please set file name"));
    }

}

void FileFinderDialog::SlotFileFound(QString _fileName)
{
    newTread->exit();
    emit SignalReturnFileName(_fileName);
    this->~FileFinderDialog();
}

void FileFinderDialog::SlotReturnToMain()
{
    emit SignalReturnFileName("no files found");
    this->~FileFinderDialog();
}

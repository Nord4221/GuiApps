#include "FileFinder.h"

#include <QDirIterator>
#include <QFileDialog>

FileFinder::FileFinder(QObject *parent)
{

}

FileFinder::~FileFinder()
{

}

void FileFinder::SlotStartSearch(QString _fileName)
{
    QStringList fileNamesList;
    QDirIterator it(QFileDialog::getExistingDirectory(), QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext())
        fileNamesList << it.next();
    emit SignalMaximumValueChanged(fileNamesList.size());
    int i = 0;
    for(auto currentFileName : fileNamesList)
    {
        emit SignalValueChanged(i++);
        if(currentFileName.contains(_fileName) && !currentFileName.contains(".obj"))
        {
            emit SignalFileNameFound(currentFileName);
            break;
        }
    }
}


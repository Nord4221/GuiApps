#include "Organizer.h"
#include <QDebug>
Organizer::Organizer(QObject *parent) : QObject(parent)
{
}

Organizer::~Organizer()
{
    WriteDataToFile();
}

void Organizer::slotOpenDataFile()
{
    if(filePtr == nullptr)
    {
        filePtr = new QFile("./dataBase.bin", this);

        if (!filePtr) return;
        if (!filePtr->open(QIODevice::ReadWrite))
        {
            emit fileOpenedChanged(false);
            return;
        }
        dataStrList = new  QStringList;

        while(!filePtr->atEnd())
            dataStrList->append(QString::fromUtf8(filePtr->readLine()));

        emit fileOpenedChanged(true);
    }
}

void Organizer::slotAddNewTask(QString _taskForAdd)
{
    dataStrList->append(_taskForAdd + "\n");
}

void Organizer::WriteDataToFile()
{
    for(auto currentStr : *dataStrList)
    {
        qDebug() << currentStr;
        filePtr->write(currentStr.toUtf8());
    }
}

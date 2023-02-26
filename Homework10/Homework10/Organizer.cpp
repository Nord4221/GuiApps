#include "Organizer.h"
#include <QDebug>
#include <QDate>

Organizer::Organizer(QObject *parent) : QObject(parent)
{
    TaskVector.resize(TASK_COMPONENT_AMOUNT);
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
        taskAmountCurrent(dataStrList->size());
    }
}

void Organizer::slotAddNewTask()
{
    QString newTaskStr;
    for(auto currentPair : TaskVector)
        if(currentPair.first == true)
            newTaskStr.push_back(currentPair.second);
        else
            return;
    dataStrList->append(newTaskStr + "\n");
    taskAmountCurrent(dataStrList->size());
}

void Organizer::slotCheckDate(QString _taskDate)
{
    if(_taskDate.length() > 9)
    {
        int day = _taskDate.mid(0,2).toInt();
        int month = _taskDate.mid(3,2).toInt();
        int year  = _taskDate.mid(6,4).toInt();
        if(QDate(year, month, day).isValid())
        {
            qDebug() << "valid";
            TaskVector[DATE_POS].first = true;
            TaskVector[DATE_POS].second = _taskDate;
        }
        else
            TaskVector[DATE_POS].first = false;
    }
    else
        TaskVector[DATE_POS].first = false;
    emit dateStatus(TaskVector[DATE_POS].first);
}

void Organizer::slotCheckDescription(QString _taskDescription)
{
    if(_taskDescription.length() > 0)
    {
        TaskVector[DESC_POS].first = true;
        TaskVector[DESC_POS].second = _taskDescription;
    }
    else
        TaskVector[DESC_POS].second = _taskDescription;
    emit descStatus(TaskVector[DESC_POS].first);
}

void Organizer::slotCheckTaskState(QString _taskState)
{
    if(_taskState.length() > 0)
    {
        if(_taskState.toInt() <= 10)
        {
            TaskVector[STAT_POS].first = true;
            TaskVector[STAT_POS].second = _taskState;
        }
    }
    else
        TaskVector[STAT_POS].second = _taskState;
    emit stateStatus(TaskVector[STAT_POS].first);
}

void Organizer::WriteDataToFile()
{
    for(auto currentStr : *dataStrList)
    {
        qDebug() << currentStr;
        filePtr->write(currentStr.toUtf8());
    }
}

#include "Organizer.h"
#include <QDebug>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>

Organizer::Organizer(QObject *parent) : QObject(parent)
{
    TaskVector.resize(TASK_COMPONENT_AMOUNT);
    TaskWindowPtr = new TaskWindow;
}

Organizer::~Organizer()
{
    Database.close();
}

void Organizer::slotOpenDataBase()
{
    if (!Database.isOpen())
    {
        Database = QSqlDatabase::addDatabase("QSQLITE");
        Database.setDatabaseName("./taskBase.db");
        if (!Database.open())
        {
            qDebug() << "Can't Open base";
            emit fileOpenedChanged(false);
            return;
        }
        QSqlQuery query(Database);
        QString sqlCommand = "CREATE TABLE IF NOT EXISTS TaskTable("
                             "id INTEGER PRIMARY KEY NOT NULL,"
                             "date VARCHAR(9),"
                             "description VARCHAR(25),"
                             "state VARCHAR(2)"
                             ");" ;

        if(!query.exec(sqlCommand))
        {
            qDebug() << "Can't CreateTable";
            emit fileOpenedChanged(false);
            return;
        }
        DataStrList = new  QStringList;
        ReadDataBase();
    }
}

void Organizer::ReadDataBase()
{
    DataStrList->clear();
    QSqlQuery query;

    if(!query.exec("SELECT * FROM TaskTable;"))
    {
        qDebug() << "Unable to read table";
    }
    QSqlRecord tableRecord = query.record();

    while(query.next())
    {
        DataStrList->append("Date: " + query.value(tableRecord.indexOf("date")).toString()+
                            "\t Desc: " + query.value(tableRecord.indexOf("description")).toString()+
                            "\t State: " + query.value(tableRecord.indexOf("state")).toString());
    }

    taskAmountCurrent(DataStrList->size());
}

void Organizer::slotAddNewTask()
{
    for(auto currentPair : TaskVector)
        if(currentPair.first != true)
            return;
    WriteDataToFile();
}

void Organizer::slotPrintAllTasks()
{
    ReadDataBase();
    TaskWindowPtr->ShowDataBaseTable(*DataStrList);
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
    QSqlQuery query;
    QString sqlCommand = "INSERT INTO TaskTable (date, description, state)"
                         "VALUES('%1', '%2', '%3');" ;
    QString sqlComWithParams = sqlCommand.arg(TaskVector[DATE_POS].second).arg(TaskVector[DESC_POS].second).arg(TaskVector[STAT_POS].second);
    if(!query.exec(sqlComWithParams))
    {
        qDebug() << sqlComWithParams;
    }
}



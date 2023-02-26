#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include <QFile>
#include <QtQml>
#include <QtQuick>
#include <QPair>

const int DATE_POS = 0;
const int DESC_POS = 1;
const int STAT_POS = 2;
const int TASK_COMPONENT_AMOUNT = 3;

class Organizer : public QObject
{
    Q_OBJECT

public:
    explicit Organizer(QObject *parent = nullptr);
    ~Organizer();

    void WriteDataToFile();

signals:
    void fileOpenedChanged(bool _isInitSuccess);
    void dateStatus(bool _isDateCorrect);
    void descStatus(bool _isDescriptionCorrect);
    void stateStatus(bool _isStateCorrect);
    void taskAmountCurrent(int _currentAmount);
public slots:
    Q_INVOKABLE void slotOpenDataFile();
    Q_INVOKABLE void slotAddNewTask();

    Q_INVOKABLE void slotCheckDate(QString _taskDate);
    Q_INVOKABLE void slotCheckDescription(QString _taskDescription);
    Q_INVOKABLE void slotCheckTaskState(QString _taskState);
private:
    QFile *filePtr = nullptr;
    QStringList *dataStrList = nullptr;
    QVector<QPair<bool, QString>> TaskVector;
    bool isDateChecked = 0;
    bool isDescriprionChecked = 0;
};

#endif // ORGANIZER_H

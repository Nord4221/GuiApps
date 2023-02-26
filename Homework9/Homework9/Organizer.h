#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include <QFile>
#include <QtQml>
#include <QtQuick>

class Organizer : public QObject
{
    Q_OBJECT

public:
    explicit Organizer(QObject *parent = nullptr);
    ~Organizer();

    void WriteDataToFile();

signals:
    void fileOpenedChanged(bool _isInitSuccess);

public slots:
    Q_INVOKABLE void slotOpenDataFile();
    Q_INVOKABLE void slotAddNewTask(QString _taskForAdd);

private:
    QFile *filePtr = nullptr;
    QStringList *dataStrList = nullptr;
    int CurrentTaskPos = 0;

};

#endif // ORGANIZER_H

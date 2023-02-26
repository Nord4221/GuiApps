#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QObject>

class FileFinder : public QObject
{
    Q_OBJECT

public:
    FileFinder( QObject *parent = nullptr);
    ~FileFinder();
signals:
    void SignalFileNameFound(QString _fileName);
    void SignalValueChanged(int _value);
    void SignalMaximumValueChanged(int _value);
public slots:
    void SlotStartSearch(QString _fileName);
};

#endif // FILEFINDER_H

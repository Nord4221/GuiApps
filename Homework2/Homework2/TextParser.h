#ifndef TEXTPARSER_H
#define TEXTPARSER_H

#include <QString>
#include <QMap>

#define MIN(a, b) (a < b) ? a : b

class TextParser
{
public:
    TextParser();
    bool TextChange(QString _ChangedText);
    QString GetSymbol(QString _SymbolCode);
    QString GetText();
private:
    QString LastText;//Последний текст
    QString ModifiedText; //Текст с правкой примера
    qint32 Position;//позиция указателя поиска
    QMap<QString, QString> SymbolMap;
};

#endif // TEXTPARSER_H

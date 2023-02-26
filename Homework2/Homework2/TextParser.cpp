#include "TextParser.h"

const QString ERROR_MSG = "(Incorrect symbol code)";

TextParser::TextParser()
{
    LastText = "";
    ModifiedText = "";
    Position = 0;
    SymbolMap.insert("RUB#", "╜");
    SymbolMap.insert("GUARD#", "©");
    SymbolMap.insert("PROM#", "‰");
}

bool TextParser::TextChange(QString _ChangedText)
{
    qint32 length = MIN(MIN(LastText.length(), _ChangedText.length()), Position);
    ModifiedText = "";
    for (qint32 i = 0; i < length; i++)
    {
        if (LastText[i] != _ChangedText[i])
        {
            Position = i;
            break;
        }
    }
    const QChar *textArray = _ChangedText.constData();
    qint32 pPosition = 0, lastPosition = -1; // курсор на начало символа, с которого будет осуществлять происк метки #@


    bool isChanges = false; // есть изменения текста?
    for (qint32 fnd = _ChangedText.indexOf("#@", Position); // поиск первого примера в тексте
         fnd != -1 && lastPosition != Position; // -1 - означает, что в строке нет (больше)примеров
         fnd = _ChangedText.indexOf("#@", Position))
    {
        ModifiedText.insert(ModifiedText.length(), &textArray[pPosition], fnd); // копируем текст до примера
        lastPosition = Position;
        Position = fnd;
        int r = _ChangedText.indexOf('#', fnd+1);//если есть равенство, то пример завершен
        int space = _ChangedText.indexOf(' ', fnd);
        if ((r < space || space == -1) && r != -1) // проверяем, что равно для текущего примера, а не следующего
        {
            QString symbolCode = "";
            symbolCode.insert(0, &textArray[fnd + 2], r - fnd - 1);
            QString rez = GetSymbol(symbolCode);
            ModifiedText += rez;
            Position = r + 1;
            isChanges = true;
        }
        ModifiedText.insert(ModifiedText.length(), &textArray[Position], _ChangedText.length() - Position); // дописываем оставшийся текст

    }
    return isChanges;
}

QString TextParser::GetSymbol(QString _SymbolCode)
{
    return SymbolMap.value(_SymbolCode, ERROR_MSG);
}

QString TextParser::GetText()
{
    LastText = ModifiedText;
    return LastText;
}

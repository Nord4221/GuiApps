#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTranslator>

#include "CustomFyleSystem/CustomFyleSystem.h"
#include "FilePrinter/FilePrinter.h"
#include "FontEditor/FontEditor.h"

const QString HTML_EXTENSION = "html";
const QString TXT_EXTENSION  = "txt";

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

    bool IsFileOpenable(QFile *_file);
    void ClearTextField();
    QString GetTemperature(QByteArray *_baToFind);

public slots:
    void SlotOpenFile(QString _filePath);
    void SlotSaveFile();
    void SlotPrintFile();
    void SlotSelectFile();
    void SlotFindFileAndOpen();
    void SlotShowHelpInfo();
    void SlotSwitchLanguage();
    void SlotSwitchStyle();
    void SlotQuit();
    void SlotPasteDataAndTime();
protected:

private:
    Ui::TextEditor *UiPtr;
    QFile* CurrentFilePtr = nullptr;
    CustomFyleSystem* FileSystemPtr;
    QTranslator Translator;   
};

#endif // TEXTEDITOR_H

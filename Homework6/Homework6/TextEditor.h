#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTranslator>
#include <QMdiArea>
#include <QMap>

#include "CustomFyleSystem/CustomFyleSystem.h"
#include "FilePrinter/FilePrinter.h"

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
    void ClearTextField(QTextBrowser *_textBrowser);
    QString GetTemperature(QByteArray *_baToFind);
public slots:
    void SlotOpenFile(QString _filePath);
    void SlotSaveFile();
    void SlotPrintFile();
    void SlotSelectFile();
    void SlotShowHelpInfo();
    void SlotSwitchLanguage();
    void SlotSwitchStyle();
    void SlotQuit();
protected:

private:
    Ui::TextEditor *UiPtr;
    QMap <QMdiSubWindow*, QFile*> MdiAreaFilesMap;
    CustomFyleSystem* FileSystemPtr;
    QMdiArea* MdiAreaPtr;
    QTranslator Translator;   
};

#endif // TEXTEDITOR_H

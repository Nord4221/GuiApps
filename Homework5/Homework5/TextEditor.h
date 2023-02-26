#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTranslator>

#include "CustomFyleSystem/CustomFyleSystem.h"

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

    bool IsFileOpenable(QFile *file);
    void ClearTextField();
    QString GetTemperature(QByteArray *_baToFind);

public slots:
    void SlotOpenFile(QString FilePath);
    void SlotSaveFile();
    void SlotShowHelpInfo();
    void SlotSwitchLanguage();
    void SlotSwitchStyle();
    void SlotSelectFile();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::TextEditor *UiPtr;
    QFile* CurrentFilePtr = nullptr;
    CustomFyleSystem* FileSystemPtr;
    QTranslator Translator;   
};

#endif // TEXTEDITOR_H

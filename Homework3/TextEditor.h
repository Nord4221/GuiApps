#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "QWebEngineView"
#include "QUrl"


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
    void SlotOpenFile();
    void SlotSaveFile();
    void SlotShowHelpInfo();
private:
    Ui::TextEditor *UiPtr;
    QFile* CurrentFilePtr = nullptr;
    QWebEngineView *WebEngView = nullptr;
};

#endif // TEXTEDITOR_H

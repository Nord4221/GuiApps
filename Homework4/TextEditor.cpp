#include "TextEditor.h"
#include "ui_TextEditor.h"
#include <QWhatsThis>
#include <QKeyEvent>
#include <QDebug>

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    UiPtr(new Ui::TextEditor)
{
    UiPtr->setupUi(this);
    TextEditor::setWindowTitle("TextEditor. v_Homework4.");

    UiPtr->textBrowserMainMindow->setTextInteractionFlags(Qt::TextEditorInteraction);

    connect(UiPtr->pushButtonOpenFile, &QPushButton::clicked, this, &TextEditor::SlotOpenFile);
    connect(UiPtr->pushButtonSaveFile, &QPushButton::clicked, this, &TextEditor::SlotSaveFile);
    connect(UiPtr->pushButtonHelp,     &QPushButton::clicked, this, &TextEditor::SlotShowHelpInfo);
    connect(UiPtr->pushButtonSwitchLanguage, &QPushButton::clicked, this, &TextEditor::SlotSwitchLanguage);
    connect(UiPtr->pushButton, &QPushButton::clicked, this, &TextEditor::SlotSwitchFileOpenKey);
}

TextEditor::~TextEditor()
{
    delete UiPtr;
}


void TextEditor::SlotOpenFile()
{
    UiPtr->pushButtonOpenFile->repaint();
    if(CurrentFilePtr != nullptr)
    {
        CurrentFilePtr->close();
        CurrentFilePtr->deleteLater();
    }
    CurrentFilePtr = new QFile;
    CurrentFilePtr->setFileName(QFileDialog::getOpenFileName(this, tr("Choose file to open"), nullptr, tr("Files(*.txt)")));

    ClearTextField();
    if(UiPtr->checkBoxReadOnly->isChecked())
        UiPtr->textBrowserMainMindow->setTextInteractionFlags(Qt::TextSelectableByMouse);
    else
        UiPtr->textBrowserMainMindow->setTextInteractionFlags(Qt::TextEditorInteraction);

    if(IsFileOpenable(CurrentFilePtr))
    {
        QByteArray baFileText;
        baFileText.resize(CurrentFilePtr->size());
        baFileText = CurrentFilePtr->readAll();
        if(baFileText.size() == 0)
        {
            UiPtr->textBrowserMainMindow->append(tr("Can't read anything from file - ") + CurrentFilePtr->fileName());
            return;
        }
        else
        {
            QString strFileText(baFileText);
            UiPtr->textBrowserMainMindow->setPlainText(strFileText);
        }
    }
    else
        return;
}

void TextEditor::SlotSaveFile()
{
    if(CurrentFilePtr == nullptr || !CurrentFilePtr->isOpen())
    {
        UiPtr->textBrowserMainMindow->append("Can't  access to file");
        return;
    }
    else
    {
        QByteArray baTextFromTextBrowser = UiPtr->textBrowserMainMindow->toPlainText().toUtf8();
        CurrentFilePtr->resize(0);
        CurrentFilePtr->write(baTextFromTextBrowser, baTextFromTextBrowser.size());
        CurrentFilePtr->close();
        CurrentFilePtr->rename(QFileDialog::getSaveFileName());
        CurrentFilePtr = nullptr;
    }
    ClearTextField();
}

void TextEditor::SlotShowHelpInfo()
{
    QFile* filePtr = new QFile(":/new/prefix1/HelpTextWindow.txt");
    filePtr->open(QIODevice::ReadOnly);
    QWhatsThis::showText(UiPtr->centralWidget->pos(), filePtr->readAll(), UiPtr->centralWidget);
    filePtr->close();
}

void TextEditor::SlotSwitchLanguage()
{
    static bool isRussianLanguage = false;
    if(isRussianLanguage)
    {
        Translator.load(":/new/translation/QtLanguage_en.qm");
        isRussianLanguage = false;
    }
    else
    {
        Translator.load(":/new/translation/QtLanguage_ru.qm");
        isRussianLanguage = true;
    }
    qApp->installTranslator(&Translator);
    UiPtr->retranslateUi(this);
}

void TextEditor::SlotSwitchFileOpenKey()
{
    isKeyChangeState = true;
}

void TextEditor::keyPressEvent(QKeyEvent *event)
{
    QKeySequence seq;
    if(event->matches(QKeySequence::Save))
        SlotSaveFile();
    if(event->matches(QKeySequence::New) || (event->nativeVirtualKey() == KeyFileOpenValue))
        SlotOpenFile();
    if((event->modifiers() == Qt::KeyboardModifier::ControlModifier) && (event->key() == Qt::Key::Key_Q))
        this->~TextEditor();
    if(isKeyChangeState)
    {
        KeyFileOpenValue = event->nativeVirtualKey();
        isKeyChangeState = false;
    }
}

void TextEditor::ClearTextField()
{
    UiPtr->textBrowserMainMindow->clear();
}

bool TextEditor::IsFileOpenable(QFile *file)
{
    if(file->exists())
    {
        file->open(QIODevice::ReadWrite);
        if(file->isOpen())
        {
            UiPtr->textBrowserMainMindow->append(tr("File opened - ") + file->fileName());
            return true;
        }
        else
        {
            UiPtr->textBrowserMainMindow->append(tr("Can't open file - ") + file->fileName());
            return false;
        }
    }
    else
    {
        UiPtr->textBrowserMainMindow->append(tr("Can't find file : ") + file->fileName());
        return false;
    }
}

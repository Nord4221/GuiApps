#include "TextEditor.h"
#include "ui_TextEditor.h"
#include <QWhatsThis>
#include <QKeyEvent>
#include <QDebug>
#include <QMenu>
#include <QDate>
#include <QTime>

#include "FileFinder/FileFinderDialog.h"

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    UiPtr(new Ui::TextEditor)
{
    UiPtr->setupUi(this);
    TextEditor::setWindowTitle("TextEditor. v_Homework8.");
    UiPtr->textBrowserMainMindow->setTextInteractionFlags(Qt::TextEditorInteraction);

    QMenu *menuFilePtr = new QMenu(this);
    menuFilePtr->setTitle(tr("Files"));
    menuFilePtr->addAction(tr("Open file"), this, &TextEditor::SlotSelectFile, QKeySequence::New);
    menuFilePtr->addAction(tr("Find file and open"), this, &TextEditor::SlotFindFileAndOpen);
    menuFilePtr->addAction(tr("Save file"), this, &TextEditor::SlotSaveFile, QKeySequence::Save);
    menuFilePtr->addAction(tr("Print file"), this, &TextEditor::SlotPrintFile, QKeySequence::Print);
    menuFilePtr->addAction(tr("Quit"), this, &TextEditor::SlotQuit, QKeySequence("Ctrl+Q"));
    UiPtr->menuBar->addMenu(menuFilePtr);
    UiPtr->menuBar->addSeparator();
    QMenu *menuWindowPtr = new QMenu(this);
    menuWindowPtr->setTitle(tr("Window"));
    menuWindowPtr->addAction(tr("Help"), this, &TextEditor::SlotShowHelpInfo);
    menuWindowPtr->addAction(tr("Switch language"), this, &TextEditor::SlotSwitchLanguage);
    menuWindowPtr->addAction(tr("Switch style"), this, &TextEditor::SlotSwitchStyle);
    UiPtr->menuBar->addMenu(menuWindowPtr);
    UiPtr->menuBar->addSeparator();
    FontEditor *fontEdit = new FontEditor(this, UiPtr->textBrowserMainMindow);
    UiPtr->menuBar->addMenu(fontEdit->GetFontMenu());
    QMenu *menuInsertionsPtr = new QMenu(this);
    menuInsertionsPtr->setTitle(tr("Paste"));
    menuWindowPtr->addAction(tr("Paste Data and Time"), this, &TextEditor::SlotPasteDataAndTime, QKeySequence("Ctrl+T"));
    UiPtr->menuBar->addMenu(menuWindowPtr);
    UiPtr->menuBar->repaint();

    SlotSwitchStyle();
}

TextEditor::~TextEditor()
{
    delete UiPtr;
}

//Homework 8---------------------------------------------------
void TextEditor::SlotFindFileAndOpen()
{

    FileFinderDialog *fileFinderDialog = new FileFinderDialog();

    connect(fileFinderDialog, &FileFinderDialog::SignalReturnFileName, this, &TextEditor::SlotOpenFile);
}
//Homework 8---------------------------------------------------

void TextEditor::SlotOpenFile(QString _filePath)
{
    if(CurrentFilePtr != nullptr)
    {
        CurrentFilePtr->close();
        CurrentFilePtr->deleteLater();
    }
    CurrentFilePtr = new QFile;
    CurrentFilePtr->setFileName(_filePath);

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

void TextEditor::SlotPrintFile()
{
    FilePrinter *filePrinterPtr = new FilePrinter(this);
    filePrinterPtr->SlotPrintFromTextBrowser(UiPtr->textBrowserMainMindow);
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



void TextEditor::SlotSwitchStyle()
{
    static bool isDarkMode = false;
    if(isDarkMode)
    {
        qApp->setStyleSheet("QPushButton {color: black; background-color: lightgray;} QMainWindow{background-color:lightgray}");
        isDarkMode = false;
    }
    else
    {
        qApp->setStyleSheet("QPushButton {color: white; background-color: black;} QMainWindow{background-color:darkgrey}");
        isDarkMode = true;
    }

    UiPtr->retranslateUi(this);
}

void TextEditor::SlotSelectFile()
{
    FileSystemPtr = new CustomFyleSystem;
    connect(FileSystemPtr, &CustomFyleSystem::SignalCurrentPathFound, this, &TextEditor::SlotOpenFile);
}


void TextEditor::SlotQuit()
{
    this->~TextEditor();
}

void TextEditor::SlotPasteDataAndTime()
{
    UiPtr->textBrowserMainMindow->insertPlainText("Date: " + QDate::currentDate().toString() + " Time: " + QTime::currentTime().toString());
}

void TextEditor::ClearTextField()
{
    UiPtr->textBrowserMainMindow->clear();
}

bool TextEditor::IsFileOpenable(QFile *_file)
{
    if(_file->exists())
    {
        _file->open(QIODevice::ReadWrite);
        if(_file->isOpen())
        {
            UiPtr->textBrowserMainMindow->append(tr("File opened - ") + _file->fileName());
            return true;
        }
        else
        {
            UiPtr->textBrowserMainMindow->append(tr("Can't open file - ") + _file->fileName());
            return false;
        }
    }
    else
    {
        UiPtr->textBrowserMainMindow->append(tr("Can't find file : ") + _file->fileName());
        return false;
    }
}

#include "TextEditor.h"
#include "ui_TextEditor.h"
#include <QWhatsThis>
#include <QKeyEvent>
#include <QDebug>
#include <QMenu>
#include <QMdiSubWindow>

TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    UiPtr(new Ui::TextEditor)
{
    UiPtr->setupUi(this);
    TextEditor::setWindowTitle("TextEditor. v_Homework6.");
    MdiAreaPtr = new QMdiArea;
    UiPtr->gridLayoutMdiArea->addWidget(MdiAreaPtr);

    MdiAreaFilesMap.insert(MdiAreaPtr->addSubWindow(new QTextBrowser(this)), nullptr);

    QMenu *menuFilePtr = new QMenu(this);
    menuFilePtr->setTitle(tr("Files"));
    menuFilePtr->addAction(tr("Open file"), this, &TextEditor::SlotSelectFile,QKeySequence::New);
    menuFilePtr->addAction(tr("Save file"), this, &TextEditor::SlotSaveFile,QKeySequence::Save);
    menuFilePtr->addAction(tr("Print file"), this, &TextEditor::SlotPrintFile,QKeySequence::Print);
    menuFilePtr->addAction(tr("Quit"), this, &TextEditor::SlotQuit,QKeySequence("Ctrl+Q"));
    UiPtr->menuBar->addMenu(menuFilePtr);

    QMenu *menuWindowPtr = new QMenu(this);
    menuWindowPtr->setTitle(tr("Window"));
    menuWindowPtr->addAction(tr("Help"), this, &TextEditor::SlotShowHelpInfo);
    menuWindowPtr->addAction(tr("Switch language"), this, &TextEditor::SlotSwitchLanguage);
    menuWindowPtr->addAction(tr("Switch style"), this, &TextEditor::SlotSwitchStyle);
    UiPtr->menuBar->addMenu(menuWindowPtr);

    SlotSwitchStyle();
}

TextEditor::~TextEditor()
{
    delete UiPtr;
}


void TextEditor::SlotOpenFile(QString _filePath)
{
    if(MdiAreaFilesMap.contains(MdiAreaPtr->activeSubWindow()))
    {
        if(MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()] != nullptr)
        {
            MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()]->close();
            MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()]->deleteLater();
        }
        MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()] = new QFile;
    }
    else
    {
       qDebug() << "??? :" <<MdiAreaPtr->activeSubWindow()  ;
       QMdiSubWindow *tmpSub = MdiAreaPtr->addSubWindow(new QTextBrowser(this));
       MdiAreaPtr->currentSubWindow()->widget()->show();
       MdiAreaFilesMap.insert(tmpSub, new QFile);
    }
    QTextBrowser *localTextBrowserPtr = (QTextBrowser*)MdiAreaPtr->activeSubWindow()->widget();
    QFile *localFilePtr = MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()];
    MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()]->setFileName(_filePath);

    ClearTextField(localTextBrowserPtr);

    if(UiPtr->checkBoxReadOnly->isChecked())
        localTextBrowserPtr->setTextInteractionFlags(Qt::TextSelectableByMouse);
    else
        localTextBrowserPtr->setTextInteractionFlags(Qt::TextEditorInteraction);

    if(IsFileOpenable(localFilePtr))
    {
        QByteArray baFileText;
        baFileText.resize(localFilePtr->size());
        baFileText = localFilePtr->readAll();
        if(baFileText.size() == 0)
        {
            localTextBrowserPtr->append(tr("Can't read anything from file - ") + localFilePtr->fileName());
            return;
        }
        else
        {
            QString strFileText(baFileText);
            localTextBrowserPtr->setPlainText(strFileText);
        }
    }
    else
        return;
}

void TextEditor::SlotSaveFile()
{ 
    if(MdiAreaFilesMap.find(MdiAreaPtr->activeSubWindow()) == MdiAreaFilesMap.end())
        return;
    else if(MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()] == nullptr || !MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()]->isOpen() )
    {
        QTextBrowser *localTextBrowserPtr = (QTextBrowser*)MdiAreaPtr->activeSubWindow()->widget();
        localTextBrowserPtr->append("Can't  access to file");
        return;
    }
    else
    {
        QTextBrowser *localTextBrowserPtr = (QTextBrowser*)MdiAreaPtr->activeSubWindow()->widget();
        QFile *localFilePtr = MdiAreaFilesMap[MdiAreaPtr->activeSubWindow()];
        QByteArray baTextFromTextBrowser = localTextBrowserPtr->toPlainText().toUtf8();
        localFilePtr->resize(0);
        localFilePtr->write(baTextFromTextBrowser, baTextFromTextBrowser.size());
        localFilePtr->close();
        localFilePtr->rename(QFileDialog::getSaveFileName());
        localFilePtr = nullptr;
        ClearTextField(localTextBrowserPtr);
    } 
}

void TextEditor::SlotPrintFile()
{
    if((MdiAreaFilesMap.find(MdiAreaPtr->activeSubWindow()) != MdiAreaFilesMap.end()) && (MdiAreaPtr->activeSubWindow() != nullptr))
    {
        FilePrinter *filePrinterPtr = new FilePrinter(this);
        QTextBrowser *localTextBrowserPtr = (QTextBrowser*)MdiAreaPtr->activeSubWindow()->widget();
        filePrinterPtr->SlotPrintFromTextBrowser(localTextBrowserPtr);
    }
    else
        return;
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

void TextEditor::ClearTextField(QTextBrowser* _textBrowser)
{
    _textBrowser->clear();
}

bool TextEditor::IsFileOpenable(QFile *_file)
{
    QTextBrowser *localTextBrowserPtr = (QTextBrowser*)MdiAreaPtr->activeSubWindow()->widget();
    if(_file->exists())
    {       
        _file->open(QIODevice::ReadWrite);
        if(_file->isOpen())
        {
            localTextBrowserPtr->append(tr("File opened - ") + _file->fileName());
            return true;
        }
        else
        {
            localTextBrowserPtr->append(tr("Can't open file - ") + _file->fileName());
            return false;
        }
    }
    else
    {
        localTextBrowserPtr->append(tr("Can't find file : ") + _file->fileName());
        return false;
    }
}

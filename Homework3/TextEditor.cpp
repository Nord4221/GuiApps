#include "TextEditor.h"
#include "ui_TextEditor.h"
#include <QWhatsThis>


TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    UiPtr(new Ui::TextEditor)
{
    UiPtr->setupUi(this);


    TextEditor::setWindowTitle("TextEditor. v_Homework2.");
    UiPtr->textBrowserMainMindow->setTextInteractionFlags(Qt::TextEditorInteraction);
    WebEngView = new QWebEngineView(this);
    WebEngView->setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    UiPtr->gridLayout_2->addWidget(WebEngView);
    WebEngView->hide();
    UiPtr->lineEdit->hide();
    connect(UiPtr->pushButtonOpenFile, &QPushButton::clicked, this, &TextEditor::SlotOpenFile);
    connect(UiPtr->pushButtonSaveFile, &QPushButton::clicked, this, &TextEditor::SlotSaveFile);
    connect(UiPtr->pushButtonHelp, &QPushButton::clicked, this, &TextEditor::SlotShowHelpInfo);
}

TextEditor::~TextEditor()
{
    delete UiPtr;
}



void TextEditor::SlotOpenFile()
{
    if(CurrentFilePtr != nullptr)
    {
        CurrentFilePtr->close();
        CurrentFilePtr->deleteLater();
    }
    CurrentFilePtr = new QFile;
    CurrentFilePtr->setFileName(QFileDialog::getOpenFileName(this, tr("Choose file to open"), nullptr, tr("Files(*.txt *.html)")));

    ClearTextField();

    if(IsFileOpenable(CurrentFilePtr))
    {
        QByteArray baFileText;
        baFileText.resize(CurrentFilePtr->size());
        baFileText = CurrentFilePtr->readAll();
        if(baFileText.size() == 0)
            UiPtr->textBrowserMainMindow->append("Can't read anything from file - " + CurrentFilePtr->fileName());
        else
        {
            QString strFileText(baFileText);
            if(QFileInfo(CurrentFilePtr->fileName()).suffix() == TXT_EXTENSION)
            {
                WebEngView->hide();
                UiPtr->lineEdit->hide();
                if(!UiPtr->gridLayout_2->isEmpty())
                    UiPtr->gridLayout_2->itemAt(0)->widget()->hide();
                UiPtr->textBrowserMainMindow->setPlainText(strFileText);
            }
            else
            {
                WebEngView->setHtml(baFileText,QUrl::fromEncoded(baFileText));
                UiPtr->textBrowserMainMindow->setPlainText(strFileText);
                //GetTemperature(&baFileText);
                UiPtr->lineEdit->setText(GetTemperature(&baFileText));
                WebEngView->show();
                UiPtr->lineEdit->show();
            }
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
    WebEngView->hide();
    UiPtr->lineEdit->hide();
    ClearTextField();
}

void TextEditor::SlotShowHelpInfo()
{
    QFile* filePtr = new QFile(":/new/prefix1/HelpTextWindow.txt");
    filePtr->open(QIODevice::ReadOnly);
    QWhatsThis::showText(UiPtr->centralWidget->pos(), filePtr->readAll(), UiPtr->centralWidget);
    filePtr->close();
}

void TextEditor::ClearTextField()
{
    UiPtr->textBrowserMainMindow->clear();
}

QString TextEditor::GetTemperature(QByteArray *_baToFind)
{
    QString replyStr = "Temperature = ";
    int positionOfDegreeSymbol = _baToFind->indexOf("°");
    if(positionOfDegreeSymbol > 0)
    {
        int positionBeforeDegree = (_baToFind->lastIndexOf(">", positionOfDegreeSymbol) > _baToFind->lastIndexOf(" ", positionOfDegreeSymbol) ?  _baToFind->lastIndexOf(">", positionOfDegreeSymbol):
                                                                                                                                                 _baToFind->lastIndexOf(" ", positionOfDegreeSymbol));
        positionBeforeDegree += 0;
        if(positionBeforeDegree > 0)
        for(int var = positionBeforeDegree; var < positionOfDegreeSymbol; var++)
        {
            replyStr.append(_baToFind->at(var));
        }
        replyStr.append("°");
        return replyStr;
    }
    return "Cant find °";
}

bool TextEditor::IsFileOpenable(QFile *file)
{
    if(file->exists())
    {
        file->open(QIODevice::ReadWrite);
        if(file->isOpen())
        {
            UiPtr->textBrowserMainMindow->append("File opened - " + file->fileName());
            return true;
        }
        else
        {
            UiPtr->textBrowserMainMindow->append("Can't open file - " + file->fileName());
            return false;
        }
    }
    else
    {
        UiPtr->textBrowserMainMindow->append("Can't find file : " + file->fileName());
        return false;
    }
}

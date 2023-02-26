/********************************************************************************
** Form generated from reading UI file 'TextEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEditor
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxReadOnly;
    QTextBrowser *textBrowserMainMindow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QString::fromUtf8("TextEditor"));
        TextEditor->resize(627, 551);
        centralWidget = new QWidget(TextEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxReadOnly = new QCheckBox(centralWidget);
        checkBoxReadOnly->setObjectName(QString::fromUtf8("checkBoxReadOnly"));

        gridLayout->addWidget(checkBoxReadOnly, 3, 0, 1, 2);

        textBrowserMainMindow = new QTextBrowser(centralWidget);
        textBrowserMainMindow->setObjectName(QString::fromUtf8("textBrowserMainMindow"));
        textBrowserMainMindow->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(textBrowserMainMindow, 0, 0, 1, 3);

        TextEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TextEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 21));
        TextEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TextEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TextEditor->addToolBar(Qt::RightToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TextEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TextEditor->setStatusBar(statusBar);

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TextEditor)
    {
        TextEditor->setWindowTitle(QCoreApplication::translate("TextEditor", "TextEditor", nullptr));
        checkBoxReadOnly->setText(QCoreApplication::translate("TextEditor", "ReadOnly mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H

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
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButtonOpenFile;
    QPushButton *pushButtonSwitchLanguage;
    QPushButton *pushButtonSaveFile;
    QTextBrowser *textBrowserMainMindow;
    QPushButton *pushButtonHelp;
    QCheckBox *checkBoxReadOnly;
    QPushButton *pushButtonSwitchStyle;
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
        pushButtonOpenFile = new QPushButton(centralWidget);
        pushButtonOpenFile->setObjectName(QString::fromUtf8("pushButtonOpenFile"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonOpenFile->sizePolicy().hasHeightForWidth());
        pushButtonOpenFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonOpenFile, 2, 0, 1, 1);

        pushButtonSwitchLanguage = new QPushButton(centralWidget);
        pushButtonSwitchLanguage->setObjectName(QString::fromUtf8("pushButtonSwitchLanguage"));
        pushButtonSwitchLanguage->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(pushButtonSwitchLanguage, 2, 2, 1, 1);

        pushButtonSaveFile = new QPushButton(centralWidget);
        pushButtonSaveFile->setObjectName(QString::fromUtf8("pushButtonSaveFile"));
        sizePolicy.setHeightForWidth(pushButtonSaveFile->sizePolicy().hasHeightForWidth());
        pushButtonSaveFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonSaveFile, 2, 1, 1, 1);

        textBrowserMainMindow = new QTextBrowser(centralWidget);
        textBrowserMainMindow->setObjectName(QString::fromUtf8("textBrowserMainMindow"));
        textBrowserMainMindow->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(textBrowserMainMindow, 1, 0, 1, 5);

        pushButtonHelp = new QPushButton(centralWidget);
        pushButtonHelp->setObjectName(QString::fromUtf8("pushButtonHelp"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonHelp->sizePolicy().hasHeightForWidth());
        pushButtonHelp->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonHelp, 0, 0, 1, 1);

        checkBoxReadOnly = new QCheckBox(centralWidget);
        checkBoxReadOnly->setObjectName(QString::fromUtf8("checkBoxReadOnly"));

        gridLayout->addWidget(checkBoxReadOnly, 5, 0, 1, 2);

        pushButtonSwitchStyle = new QPushButton(centralWidget);
        pushButtonSwitchStyle->setObjectName(QString::fromUtf8("pushButtonSwitchStyle"));
        sizePolicy.setHeightForWidth(pushButtonSwitchStyle->sizePolicy().hasHeightForWidth());
        pushButtonSwitchStyle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonSwitchStyle, 2, 3, 1, 1);

        TextEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TextEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 627, 21));
        TextEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TextEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TextEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TextEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TextEditor->setStatusBar(statusBar);

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QMainWindow *TextEditor)
    {
        TextEditor->setWindowTitle(QCoreApplication::translate("TextEditor", "TextEditor", nullptr));
        pushButtonOpenFile->setText(QCoreApplication::translate("TextEditor", "Open File", nullptr));
        pushButtonSwitchLanguage->setText(QCoreApplication::translate("TextEditor", "En/Ru", nullptr));
        pushButtonSaveFile->setText(QCoreApplication::translate("TextEditor", "Save File", nullptr));
        pushButtonHelp->setText(QCoreApplication::translate("TextEditor", "Help", nullptr));
        checkBoxReadOnly->setText(QCoreApplication::translate("TextEditor", "ReadOnly mode", nullptr));
        pushButtonSwitchStyle->setText(QCoreApplication::translate("TextEditor", "Switch StyleMode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H

/********************************************************************************
** Form generated from reading UI file 'TextEditor.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
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
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonSaveFile;
    QPushButton *pushButtonHelp;
    QTextBrowser *textBrowserMainMindow;
    QPushButton *pushButtonOpenFile;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QString::fromUtf8("TextEditor"));
        TextEditor->resize(651, 543);
        centralWidget = new QWidget(TextEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout->addLayout(gridLayout_2, 1, 3, 1, 1);

        pushButtonSaveFile = new QPushButton(centralWidget);
        pushButtonSaveFile->setObjectName(QString::fromUtf8("pushButtonSaveFile"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSaveFile->sizePolicy().hasHeightForWidth());
        pushButtonSaveFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonSaveFile, 2, 1, 1, 1);

        pushButtonHelp = new QPushButton(centralWidget);
        pushButtonHelp->setObjectName(QString::fromUtf8("pushButtonHelp"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonHelp->sizePolicy().hasHeightForWidth());
        pushButtonHelp->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonHelp, 0, 0, 1, 1);

        textBrowserMainMindow = new QTextBrowser(centralWidget);
        textBrowserMainMindow->setObjectName(QString::fromUtf8("textBrowserMainMindow"));
        textBrowserMainMindow->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(textBrowserMainMindow, 1, 0, 1, 3);

        pushButtonOpenFile = new QPushButton(centralWidget);
        pushButtonOpenFile->setObjectName(QString::fromUtf8("pushButtonOpenFile"));
        sizePolicy.setHeightForWidth(pushButtonOpenFile->sizePolicy().hasHeightForWidth());
        pushButtonOpenFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonOpenFile, 2, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 3, 1, 1);

        TextEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TextEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 651, 22));
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
        pushButtonSaveFile->setText(QCoreApplication::translate("TextEditor", "Save File", nullptr));
        pushButtonHelp->setText(QCoreApplication::translate("TextEditor", "Help", nullptr));
        pushButtonOpenFile->setText(QCoreApplication::translate("TextEditor", "Open File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H

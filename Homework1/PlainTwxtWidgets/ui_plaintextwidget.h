/********************************************************************************
** Form generated from reading UI file 'plaintextwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAINTEXTWIDGET_H
#define UI_PLAINTEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlainTextWidget
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButtonReplace;
    QPushButton *pushButtonSwap;
    QPushButton *pushButtonPrintHTML;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlainTextWidget)
    {
        if (PlainTextWidget->objectName().isEmpty())
            PlainTextWidget->setObjectName(QString::fromUtf8("PlainTextWidget"));
        PlainTextWidget->resize(315, 238);
        centralWidget = new QWidget(PlainTextWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 10, 104, 71));
        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(160, 10, 104, 71));
        pushButtonReplace = new QPushButton(centralWidget);
        pushButtonReplace->setObjectName(QString::fromUtf8("pushButtonReplace"));
        pushButtonReplace->setGeometry(QRect(40, 90, 75, 23));
        pushButtonSwap = new QPushButton(centralWidget);
        pushButtonSwap->setObjectName(QString::fromUtf8("pushButtonSwap"));
        pushButtonSwap->setGeometry(QRect(40, 120, 75, 23));
        pushButtonPrintHTML = new QPushButton(centralWidget);
        pushButtonPrintHTML->setObjectName(QString::fromUtf8("pushButtonPrintHTML"));
        pushButtonPrintHTML->setGeometry(QRect(40, 150, 75, 23));
        PlainTextWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlainTextWidget);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 315, 21));
        PlainTextWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlainTextWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PlainTextWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlainTextWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlainTextWidget->setStatusBar(statusBar);

        retranslateUi(PlainTextWidget);

        QMetaObject::connectSlotsByName(PlainTextWidget);
    } // setupUi

    void retranslateUi(QMainWindow *PlainTextWidget)
    {
        PlainTextWidget->setWindowTitle(QCoreApplication::translate("PlainTextWidget", "PlainTextWidget", nullptr));
        pushButtonReplace->setText(QCoreApplication::translate("PlainTextWidget", "Replace", nullptr));
        pushButtonSwap->setText(QCoreApplication::translate("PlainTextWidget", "Swap", nullptr));
        pushButtonPrintHTML->setText(QCoreApplication::translate("PlainTextWidget", "htmlPrint", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlainTextWidget: public Ui_PlainTextWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAINTEXTWIDGET_H

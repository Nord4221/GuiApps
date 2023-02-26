/********************************************************************************
** Form generated from reading UI file 'WindowWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWWIDGET_H
#define UI_WINDOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowWidget
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEditWindow;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowWidget)
    {
        if (WindowWidget->objectName().isEmpty())
            WindowWidget->setObjectName(QString::fromUtf8("WindowWidget"));
        WindowWidget->resize(542, 418);
        centralWidget = new QWidget(WindowWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plainTextEditWindow = new QPlainTextEdit(centralWidget);
        plainTextEditWindow->setObjectName(QString::fromUtf8("plainTextEditWindow"));
        plainTextEditWindow->setGeometry(QRect(20, 60, 481, 291));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 111, 16));
        WindowWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowWidget);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 542, 21));
        WindowWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WindowWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WindowWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WindowWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WindowWidget->setStatusBar(statusBar);

        retranslateUi(WindowWidget);

        QMetaObject::connectSlotsByName(WindowWidget);
    } // setupUi

    void retranslateUi(QMainWindow *WindowWidget)
    {
        WindowWidget->setWindowTitle(QCoreApplication::translate("WindowWidget", "WindowWidget", nullptr));
        label->setText(QCoreApplication::translate("WindowWidget", "TextParcerWindow:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowWidget: public Ui_WindowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWWIDGET_H

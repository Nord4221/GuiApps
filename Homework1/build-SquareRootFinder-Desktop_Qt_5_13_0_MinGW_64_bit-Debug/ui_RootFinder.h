/********************************************************************************
** Form generated from reading UI file 'RootFinder.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTFINDER_H
#define UI_ROOTFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootFinder
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButtonCalculate;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditMultiplierOne;
    QLineEdit *lineEditMultiplierTwo;
    QLineEdit *lineEditMultiplierThree;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RootFinder)
    {
        if (RootFinder->objectName().isEmpty())
            RootFinder->setObjectName(QString::fromUtf8("RootFinder"));
        RootFinder->resize(247, 202);
        centralWidget = new QWidget(RootFinder);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 110, 221, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 47, 13));
        pushButtonCalculate = new QPushButton(centralWidget);
        pushButtonCalculate->setObjectName(QString::fromUtf8("pushButtonCalculate"));
        pushButtonCalculate->setGeometry(QRect(10, 60, 75, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 191, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        lineEditMultiplierOne = new QLineEdit(widget);
        lineEditMultiplierOne->setObjectName(QString::fromUtf8("lineEditMultiplierOne"));

        gridLayout->addWidget(lineEditMultiplierOne, 1, 0, 1, 1);

        lineEditMultiplierTwo = new QLineEdit(widget);
        lineEditMultiplierTwo->setObjectName(QString::fromUtf8("lineEditMultiplierTwo"));

        gridLayout->addWidget(lineEditMultiplierTwo, 1, 1, 1, 1);

        lineEditMultiplierThree = new QLineEdit(widget);
        lineEditMultiplierThree->setObjectName(QString::fromUtf8("lineEditMultiplierThree"));

        gridLayout->addWidget(lineEditMultiplierThree, 1, 2, 1, 1);

        RootFinder->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RootFinder);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 247, 21));
        RootFinder->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RootFinder);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RootFinder->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RootFinder);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RootFinder->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        retranslateUi(RootFinder);

        QMetaObject::connectSlotsByName(RootFinder);
    } // setupUi

    void retranslateUi(QMainWindow *RootFinder)
    {
        RootFinder->setWindowTitle(QCoreApplication::translate("RootFinder", "RootFinder", nullptr));
        lineEdit_2->setText(QString());
        label_2->setText(QCoreApplication::translate("RootFinder", "Result", nullptr));
        pushButtonCalculate->setText(QCoreApplication::translate("RootFinder", "Calculate", nullptr));
        label->setText(QCoreApplication::translate("RootFinder", "a", nullptr));
        label_3->setText(QCoreApplication::translate("RootFinder", "b", nullptr));
        label_4->setText(QCoreApplication::translate("RootFinder", "c", nullptr));
        lineEditMultiplierTwo->setText(QString());
        lineEditMultiplierThree->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RootFinder: public Ui_RootFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTFINDER_H

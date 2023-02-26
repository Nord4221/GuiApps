/********************************************************************************
** Form generated from reading UI file 'CustomFyleSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMFYLESYSTEM_H
#define UI_CUSTOMFYLESYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomFyleSystem
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditCurrentDir;
    QPushButton *pushButtonSelectFile;
    QTreeView *treeViewFileSystem;

    void setupUi(QWidget *CustomFyleSystem)
    {
        if (CustomFyleSystem->objectName().isEmpty())
            CustomFyleSystem->setObjectName(QString::fromUtf8("CustomFyleSystem"));
        CustomFyleSystem->resize(452, 375);
        gridLayout = new QGridLayout(CustomFyleSystem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditCurrentDir = new QLineEdit(CustomFyleSystem);
        lineEditCurrentDir->setObjectName(QString::fromUtf8("lineEditCurrentDir"));

        gridLayout->addWidget(lineEditCurrentDir, 1, 0, 1, 1);

        pushButtonSelectFile = new QPushButton(CustomFyleSystem);
        pushButtonSelectFile->setObjectName(QString::fromUtf8("pushButtonSelectFile"));

        gridLayout->addWidget(pushButtonSelectFile, 1, 1, 1, 1);

        treeViewFileSystem = new QTreeView(CustomFyleSystem);
        treeViewFileSystem->setObjectName(QString::fromUtf8("treeViewFileSystem"));

        gridLayout->addWidget(treeViewFileSystem, 0, 0, 1, 2);


        retranslateUi(CustomFyleSystem);

        QMetaObject::connectSlotsByName(CustomFyleSystem);
    } // setupUi

    void retranslateUi(QWidget *CustomFyleSystem)
    {
        CustomFyleSystem->setWindowTitle(QCoreApplication::translate("CustomFyleSystem", "Form", nullptr));
        pushButtonSelectFile->setText(QCoreApplication::translate("CustomFyleSystem", "Select File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomFyleSystem: public Ui_CustomFyleSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMFYLESYSTEM_H

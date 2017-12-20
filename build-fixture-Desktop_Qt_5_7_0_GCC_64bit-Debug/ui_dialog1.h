/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QDialogButtonBox *buttonBox;
    QTreeView *treeView;
    QLabel *label;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog1);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        treeView = new QTreeView(Dialog1);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(40, 30, 321, 201));
        label = new QLabel(Dialog1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 351, 16));

        retranslateUi(Dialog1);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog1, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog1, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "Dialog", 0));
        label->setText(QApplication::translate("Dialog1", "Escoga el archivo :", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H

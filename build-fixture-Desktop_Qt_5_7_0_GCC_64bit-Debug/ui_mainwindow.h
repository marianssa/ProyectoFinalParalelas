/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QPushButton *btnsubir;
    QGroupBox *groupBox_3;
    QPushButton *btnelegir;
    QPushButton *btncerrar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(633, 363);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(380, 20, 231, 261));
        groupBox->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 140, 171, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 171, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 220, 171, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 20, 231, 111));
        label_4->setAcceptDrops(false);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAutoFillBackground(false);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 160, 181, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 200, 161, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 240, 161, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 271, 101));
        btnsubir = new QPushButton(groupBox_2);
        btnsubir->setObjectName(QStringLiteral("btnsubir"));
        btnsubir->setGeometry(QRect(90, 40, 80, 22));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 160, 271, 121));
        btnelegir = new QPushButton(groupBox_3);
        btnelegir->setObjectName(QStringLiteral("btnelegir"));
        btnelegir->setGeometry(QRect(90, 90, 80, 22));
        btncerrar = new QPushButton(centralWidget);
        btncerrar->setObjectName(QStringLiteral("btncerrar"));
        btncerrar->setGeometry(QRect(290, 290, 80, 22));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(btncerrar, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fixture torneo de futbol.", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Creditos.", 0));
        label->setText(QApplication::translate("MainWindow", "Daniel Herrera.", 0));
        label_2->setText(QApplication::translate("MainWindow", "Jhopsan Nu\303\261ez.", 0));
        label_3->setText(QApplication::translate("MainWindow", "Maria Jose Lay.", 0));
        label_4->setText(QApplication::translate("MainWindow", "Esta aplicacion a sido desarrollada por estudiantes de ingenier\303\255a civil en computacion menci\303\263n en informatica de la universidad tecnologica metropolitana.", 0));
        label_5->setText(QApplication::translate("MainWindow", "daniel.herreram@utem.cl", 0));
        label_6->setText(QApplication::translate("MainWindow", "jhopsan.nunezl@utem.cl", 0));
        label_7->setText(QApplication::translate("MainWindow", "maria.layl@utem.cl", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Eliga archivo \"csv\" a ser procesado :", 0));
        btnsubir->setText(QApplication::translate("MainWindow", "Subir", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Eliga donde guardara el archivo :", 0));
        btnelegir->setText(QApplication::translate("MainWindow", "Elegir", 0));
        btncerrar->setText(QApplication::translate("MainWindow", "Cerrar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

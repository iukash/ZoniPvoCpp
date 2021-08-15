/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxSelectAlg;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonDP;
    QGroupBox *groupBoxDP;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButtonMC;
    QGroupBox *groupBoxMC;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_7;
    QRadioButton *radioButtonTD;
    QPushButton *pushButtonStart;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBoxTechInfo;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(887, 649);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBoxSelectAlg = new QGroupBox(centralwidget);
        groupBoxSelectAlg->setObjectName(QString::fromUtf8("groupBoxSelectAlg"));
        verticalLayout_4 = new QVBoxLayout(groupBoxSelectAlg);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButtonDP = new QRadioButton(groupBoxSelectAlg);
        radioButtonDP->setObjectName(QString::fromUtf8("radioButtonDP"));
        radioButtonDP->setChecked(true);
        radioButtonDP->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButtonDP);

        groupBoxDP = new QGroupBox(groupBoxSelectAlg);
        groupBoxDP->setObjectName(QString::fromUtf8("groupBoxDP"));
        verticalLayout_6 = new QVBoxLayout(groupBoxDP);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        radioButton_4 = new QRadioButton(groupBoxDP);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setChecked(true);

        verticalLayout_6->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBoxDP);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        verticalLayout_6->addWidget(radioButton_5);


        verticalLayout_3->addWidget(groupBoxDP);

        radioButtonMC = new QRadioButton(groupBoxSelectAlg);
        radioButtonMC->setObjectName(QString::fromUtf8("radioButtonMC"));
        radioButtonMC->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButtonMC);

        groupBoxMC = new QGroupBox(groupBoxSelectAlg);
        groupBoxMC->setObjectName(QString::fromUtf8("groupBoxMC"));
        verticalLayout_7 = new QVBoxLayout(groupBoxMC);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        radioButton_6 = new QRadioButton(groupBoxMC);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setChecked(true);

        verticalLayout_7->addWidget(radioButton_6);

        radioButton_8 = new QRadioButton(groupBoxMC);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        verticalLayout_7->addWidget(radioButton_8);

        radioButton_7 = new QRadioButton(groupBoxMC);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        verticalLayout_7->addWidget(radioButton_7);


        verticalLayout_3->addWidget(groupBoxMC);

        radioButtonTD = new QRadioButton(groupBoxSelectAlg);
        radioButtonTD->setObjectName(QString::fromUtf8("radioButtonTD"));
        radioButtonTD->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButtonTD);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBoxSelectAlg);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        verticalLayout->addWidget(pushButtonStart);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        groupBoxTechInfo = new QGroupBox(centralwidget);
        groupBoxTechInfo->setObjectName(QString::fromUtf8("groupBoxTechInfo"));
        verticalLayout_5 = new QVBoxLayout(groupBoxTechInfo);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(groupBoxTechInfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_3 = new QLineEdit(groupBoxTechInfo);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(groupBoxTechInfo);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        verticalLayout_5->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBoxTechInfo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout_11->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_11);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 887, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(radioButtonMC, SIGNAL(toggled(bool)), groupBoxMC, SLOT(setEnabled(bool)));
        QObject::connect(radioButtonDP, SIGNAL(toggled(bool)), groupBoxDP, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxSelectAlg->setTitle(QApplication::translate("MainWindow", "Select Algoritms", nullptr));
        radioButtonDP->setText(QApplication::translate("MainWindow", "dynamic programming", nullptr));
        groupBoxDP->setTitle(QString());
        radioButton_4->setText(QApplication::translate("MainWindow", "iteration policy", nullptr));
        radioButton_5->setText(QApplication::translate("MainWindow", "iteration state", nullptr));
        radioButtonMC->setText(QApplication::translate("MainWindow", "method Monte-Carlo", nullptr));
        groupBoxMC->setTitle(QString());
        radioButton_6->setText(QApplication::translate("MainWindow", "with issled starts", nullptr));
        radioButton_8->setText(QApplication::translate("MainWindow", "without starts one policy", nullptr));
        radioButton_7->setText(QApplication::translate("MainWindow", "without starts many policy", nullptr));
        radioButtonTD->setText(QApplication::translate("MainWindow", "method TD", nullptr));
        pushButtonStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        groupBoxTechInfo->setTitle(QApplication::translate("MainWindow", "Technical information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

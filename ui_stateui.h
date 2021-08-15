/********************************************************************************
** Form generated from reading UI file 'stateui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEUI_H
#define UI_STATEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateUi
{
public:

    void setupUi(QWidget *StateUi)
    {
        if (StateUi->objectName().isEmpty())
            StateUi->setObjectName(QString::fromUtf8("StateUi"));
        StateUi->resize(50, 50);
        StateUi->setMinimumSize(QSize(50, 50));

        retranslateUi(StateUi);

        QMetaObject::connectSlotsByName(StateUi);
    } // setupUi

    void retranslateUi(QWidget *StateUi)
    {
        StateUi->setWindowTitle(QApplication::translate("StateUi", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StateUi: public Ui_StateUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEUI_H

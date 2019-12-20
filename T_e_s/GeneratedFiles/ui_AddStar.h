/********************************************************************************
** Form generated from reading UI file 'AddStar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTAR_H
#define UI_ADDSTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddStar
{
public:
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AddStar)
    {
        if (AddStar->objectName().isEmpty())
            AddStar->setObjectName(QString::fromUtf8("AddStar"));
        AddStar->resize(300, 80);
        pushButton_ok = new QPushButton(AddStar);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(110, 50, 80, 25));
        lineEdit = new QLineEdit(AddStar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(15, 10, 270, 30));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);

        retranslateUi(AddStar);

        QMetaObject::connectSlotsByName(AddStar);
    } // setupUi

    void retranslateUi(QDialog *AddStar)
    {
        AddStar->setWindowTitle(QApplication::translate("AddStar", "AddStar", nullptr));
        pushButton_ok->setText(QApplication::translate("AddStar", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStar: public Ui_AddStar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTAR_H

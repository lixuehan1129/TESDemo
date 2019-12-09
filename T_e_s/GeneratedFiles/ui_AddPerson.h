/********************************************************************************
** Form generated from reading UI file 'AddPerson.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSON_H
#define UI_ADDPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPerson
{
public:
    QPushButton *pushButton_sure;
    QLabel *label_personId;
    QLineEdit *lineEdit_personId;
    QPushButton *pushButton_cancel;
    QLabel *label_2;
    QLabel *label_personName;
    QLabel *label_personAge;
    QLabel *label_personSex;
    QLabel *label_personWeight;
    QLabel *label_personHeight;
    QLabel *label_personBand;
    QLineEdit *lineEdit_personName;
    QLineEdit *lineEdit_personAge;
    QLineEdit *lineEdit_personWeight;
    QLineEdit *lineEdit_personHeight;
    QRadioButton *radioButton_man;
    QRadioButton *radioButton_woman;
    QComboBox *comboBox_ecg;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QWidget *AddPerson)
    {
        if (AddPerson->objectName().isEmpty())
            AddPerson->setObjectName(QString::fromUtf8("AddPerson"));
        AddPerson->resize(600, 350);
        pushButton_sure = new QPushButton(AddPerson);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));
        pushButton_sure->setGeometry(QRect(180, 280, 90, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(13);
        pushButton_sure->setFont(font);
        label_personId = new QLabel(AddPerson);
        label_personId->setObjectName(QString::fromUtf8("label_personId"));
        label_personId->setGeometry(QRect(50, 90, 81, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        label_personId->setFont(font1);
        label_personId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_personId = new QLineEdit(AddPerson);
        lineEdit_personId->setObjectName(QString::fromUtf8("lineEdit_personId"));
        lineEdit_personId->setGeometry(QRect(140, 90, 141, 25));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_personId->setFont(font2);
        lineEdit_personId->setAlignment(Qt::AlignCenter);
        pushButton_cancel = new QPushButton(AddPerson);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(330, 280, 90, 26));
        pushButton_cancel->setFont(font);
        label_2 = new QLabel(AddPerson);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 10, 140, 50));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);
        label_personName = new QLabel(AddPerson);
        label_personName->setObjectName(QString::fromUtf8("label_personName"));
        label_personName->setGeometry(QRect(50, 130, 81, 25));
        label_personName->setFont(font1);
        label_personName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_personAge = new QLabel(AddPerson);
        label_personAge->setObjectName(QString::fromUtf8("label_personAge"));
        label_personAge->setGeometry(QRect(50, 170, 81, 25));
        label_personAge->setFont(font1);
        label_personAge->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_personSex = new QLabel(AddPerson);
        label_personSex->setObjectName(QString::fromUtf8("label_personSex"));
        label_personSex->setGeometry(QRect(50, 210, 81, 25));
        label_personSex->setFont(font1);
        label_personSex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_personWeight = new QLabel(AddPerson);
        label_personWeight->setObjectName(QString::fromUtf8("label_personWeight"));
        label_personWeight->setGeometry(QRect(300, 90, 81, 25));
        label_personWeight->setFont(font1);
        label_personWeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_personHeight = new QLabel(AddPerson);
        label_personHeight->setObjectName(QString::fromUtf8("label_personHeight"));
        label_personHeight->setGeometry(QRect(300, 130, 81, 25));
        label_personHeight->setFont(font1);
        label_personHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_personBand = new QLabel(AddPerson);
        label_personBand->setObjectName(QString::fromUtf8("label_personBand"));
        label_personBand->setGeometry(QRect(300, 170, 81, 25));
        label_personBand->setFont(font1);
        label_personBand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_personName = new QLineEdit(AddPerson);
        lineEdit_personName->setObjectName(QString::fromUtf8("lineEdit_personName"));
        lineEdit_personName->setGeometry(QRect(140, 130, 141, 25));
        lineEdit_personName->setFont(font2);
        lineEdit_personName->setAlignment(Qt::AlignCenter);
        lineEdit_personAge = new QLineEdit(AddPerson);
        lineEdit_personAge->setObjectName(QString::fromUtf8("lineEdit_personAge"));
        lineEdit_personAge->setGeometry(QRect(140, 170, 141, 25));
        lineEdit_personAge->setFont(font2);
        lineEdit_personAge->setAlignment(Qt::AlignCenter);
        lineEdit_personWeight = new QLineEdit(AddPerson);
        lineEdit_personWeight->setObjectName(QString::fromUtf8("lineEdit_personWeight"));
        lineEdit_personWeight->setGeometry(QRect(390, 90, 91, 25));
        lineEdit_personWeight->setFont(font2);
        lineEdit_personWeight->setAlignment(Qt::AlignCenter);
        lineEdit_personHeight = new QLineEdit(AddPerson);
        lineEdit_personHeight->setObjectName(QString::fromUtf8("lineEdit_personHeight"));
        lineEdit_personHeight->setGeometry(QRect(390, 130, 91, 25));
        lineEdit_personHeight->setFont(font2);
        lineEdit_personHeight->setAlignment(Qt::AlignCenter);
        radioButton_man = new QRadioButton(AddPerson);
        radioButton_man->setObjectName(QString::fromUtf8("radioButton_man"));
        radioButton_man->setGeometry(QRect(160, 210, 60, 25));
        QFont font4;
        font4.setPointSize(14);
        radioButton_man->setFont(font4);
        radioButton_woman = new QRadioButton(AddPerson);
        radioButton_woman->setObjectName(QString::fromUtf8("radioButton_woman"));
        radioButton_woman->setGeometry(QRect(225, 210, 60, 25));
        radioButton_woman->setFont(font4);
        comboBox_ecg = new QComboBox(AddPerson);
        comboBox_ecg->setObjectName(QString::fromUtf8("comboBox_ecg"));
        comboBox_ecg->setGeometry(QRect(390, 170, 141, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        comboBox_ecg->setFont(font5);
        label = new QLabel(AddPerson);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(475, 90, 50, 25));
        label->setFont(font4);
        label_3 = new QLabel(AddPerson);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(475, 130, 50, 25));
        label_3->setFont(font4);
        pushButton_sure->raise();
        label_personId->raise();
        lineEdit_personId->raise();
        pushButton_cancel->raise();
        label_2->raise();
        label_personName->raise();
        label_personAge->raise();
        label_personSex->raise();
        label_personWeight->raise();
        label_personHeight->raise();
        label_personBand->raise();
        lineEdit_personName->raise();
        lineEdit_personAge->raise();
        radioButton_man->raise();
        radioButton_woman->raise();
        comboBox_ecg->raise();
        label->raise();
        lineEdit_personWeight->raise();
        label_3->raise();
        lineEdit_personHeight->raise();

        retranslateUi(AddPerson);

        QMetaObject::connectSlotsByName(AddPerson);
    } // setupUi

    void retranslateUi(QWidget *AddPerson)
    {
        AddPerson->setWindowTitle(QApplication::translate("AddPerson", "AddPerson", nullptr));
        pushButton_sure->setText(QApplication::translate("AddPerson", "\347\241\256\345\256\232", nullptr));
        label_personId->setText(QApplication::translate("AddPerson", "\347\274\226  \345\217\267", nullptr));
        pushButton_cancel->setText(QApplication::translate("AddPerson", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("AddPerson", "\346\263\250\345\206\214\346\210\220\345\221\230", nullptr));
        label_personName->setText(QApplication::translate("AddPerson", "\345\247\223  \345\220\215", nullptr));
        label_personAge->setText(QApplication::translate("AddPerson", "\345\271\264  \351\276\204", nullptr));
        label_personSex->setText(QApplication::translate("AddPerson", "\346\200\247  \345\210\253", nullptr));
        label_personWeight->setText(QApplication::translate("AddPerson", "\344\275\223  \351\207\215", nullptr));
        label_personHeight->setText(QApplication::translate("AddPerson", "\350\272\253  \351\253\230", nullptr));
        label_personBand->setText(QApplication::translate("AddPerson", "\347\273\221  \345\256\232", nullptr));
        lineEdit_personWeight->setText(QString());
        radioButton_man->setText(QApplication::translate("AddPerson", "\347\224\267", nullptr));
        radioButton_woman->setText(QApplication::translate("AddPerson", "\345\245\263", nullptr));
        label->setText(QApplication::translate("AddPerson", "\357\274\210Kg\357\274\211", nullptr));
        label_3->setText(QApplication::translate("AddPerson", "\357\274\210cm\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPerson: public Ui_AddPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSON_H

/********************************************************************************
** Form generated from reading UI file 'PersonBody.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONBODY_H
#define UI_PERSONBODY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonBody
{
public:
    QLabel *label_head;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_name;
    QLabel *label_sex;
    QLabel *label_age;
    QLabel *label_height;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_weight;
    QLabel *label_9;
    QLabel *label_status;
    QLabel *label_4;

    void setupUi(QWidget *PersonBody)
    {
        if (PersonBody->objectName().isEmpty())
            PersonBody->setObjectName(QString::fromUtf8("PersonBody"));
        PersonBody->setWindowModality(Qt::NonModal);
        PersonBody->resize(1100, 120);
        PersonBody->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        label_head = new QLabel(PersonBody);
        label_head->setObjectName(QString::fromUtf8("label_head"));
        label_head->setGeometry(QRect(40, 20, 70, 70));
        label = new QLabel(PersonBody);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 15, 51, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(PersonBody);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 45, 51, 20));
        label_2->setFont(font);
        label_3 = new QLabel(PersonBody);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 75, 51, 20));
        label_3->setFont(font);
        label_name = new QLabel(PersonBody);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(220, 15, 60, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        label_name->setFont(font1);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_sex = new QLabel(PersonBody);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setGeometry(QRect(220, 45, 60, 20));
        label_sex->setFont(font1);
        label_sex->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_age = new QLabel(PersonBody);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setGeometry(QRect(220, 75, 60, 20));
        label_age->setFont(font1);
        label_age->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_height = new QLabel(PersonBody);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        label_height->setGeometry(QRect(410, 45, 60, 20));
        label_height->setFont(font1);
        label_height->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_8 = new QLabel(PersonBody);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 15, 51, 20));
        label_8->setFont(font);
        label_10 = new QLabel(PersonBody);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(350, 45, 51, 20));
        label_10->setFont(font);
        label_weight = new QLabel(PersonBody);
        label_weight->setObjectName(QString::fromUtf8("label_weight"));
        label_weight->setGeometry(QRect(410, 15, 61, 25));
        label_weight->setFont(font1);
        label_weight->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_9 = new QLabel(PersonBody);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(530, 30, 90, 20));
        label_9->setFont(font);
        label_status = new QLabel(PersonBody);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(630, 15, 400, 90));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        label_status->setFont(font2);
        label_status->setStyleSheet(QString::fromUtf8("color: rgb(148, 148, 148);"));
        label_status->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_status->setWordWrap(true);
        label_status->setMargin(4);
        label_4 = new QLabel(PersonBody);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 115, 1080, 1));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);"));

        retranslateUi(PersonBody);

        QMetaObject::connectSlotsByName(PersonBody);
    } // setupUi

    void retranslateUi(QWidget *PersonBody)
    {
        PersonBody->setWindowTitle(QApplication::translate("PersonBody", "PersonBody", nullptr));
        label_head->setText(QString());
        label->setText(QApplication::translate("PersonBody", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("PersonBody", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PersonBody", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_name->setText(QString());
        label_sex->setText(QString());
        label_age->setText(QString());
        label_height->setText(QString());
        label_8->setText(QApplication::translate("PersonBody", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_10->setText(QApplication::translate("PersonBody", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_weight->setText(QString());
        label_9->setText(QApplication::translate("PersonBody", "\350\256\255\347\273\203\346\203\205\345\206\265\357\274\232", nullptr));
        label_status->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonBody: public Ui_PersonBody {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONBODY_H

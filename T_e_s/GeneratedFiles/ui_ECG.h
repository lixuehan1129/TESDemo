/********************************************************************************
** Form generated from reading UI file 'ECG.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECG_H
#define UI_ECG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_ECG
{
public:
    QWidget *ECG_widget;
    QChartView *chartView;
    QLabel *ECG_num;
    QLabel *label;
    QLabel *ECG_name;
    QWidget *ECG_widget1;
    QLabel *ECG_ecg;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *ECG_widget2;
    QLabel *ECG_breath;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *ECG)
    {
        if (ECG->objectName().isEmpty())
            ECG->setObjectName(QString::fromUtf8("ECG"));
        ECG->resize(540, 220);
        ECG_widget = new QWidget(ECG);
        ECG_widget->setObjectName(QString::fromUtf8("ECG_widget"));
        ECG_widget->setGeometry(QRect(0, 0, 540, 220));
        ECG_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        chartView = new QChartView(ECG_widget);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setGeometry(QRect(0, 30, 455, 190));
        ECG_num = new QLabel(ECG_widget);
        ECG_num->setObjectName(QString::fromUtf8("ECG_num"));
        ECG_num->setGeometry(QRect(70, 10, 121, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(15);
        ECG_num->setFont(font);
        label = new QLabel(ECG_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 60, 25));
        label->setFont(font);
        ECG_name = new QLabel(ECG_widget);
        ECG_name->setObjectName(QString::fromUtf8("ECG_name"));
        ECG_name->setGeometry(QRect(400, 10, 120, 25));
        ECG_name->setFont(font);
        ECG_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ECG_widget1 = new QWidget(ECG_widget);
        ECG_widget1->setObjectName(QString::fromUtf8("ECG_widget1"));
        ECG_widget1->setGeometry(QRect(455, 40, 70, 80));
        ECG_widget1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ECG_ecg = new QLabel(ECG_widget1);
        ECG_ecg->setObjectName(QString::fromUtf8("ECG_ecg"));
        ECG_ecg->setGeometry(QRect(10, 0, 50, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        ECG_ecg->setFont(font1);
        ECG_ecg->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(ECG_widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 42, 50, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(ECG_widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 50, 18));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        ECG_widget2 = new QWidget(ECG_widget);
        ECG_widget2->setObjectName(QString::fromUtf8("ECG_widget2"));
        ECG_widget2->setGeometry(QRect(455, 130, 70, 80));
        ECG_widget2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ECG_breath = new QLabel(ECG_widget2);
        ECG_breath->setObjectName(QString::fromUtf8("ECG_breath"));
        ECG_breath->setGeometry(QRect(10, 0, 50, 50));
        ECG_breath->setFont(font1);
        ECG_breath->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(ECG_widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 42, 50, 20));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(ECG_widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 50, 18));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignCenter);
        ECG_widget1->raise();
        ECG_widget2->raise();
        chartView->raise();
        ECG_num->raise();
        label->raise();
        ECG_name->raise();

        retranslateUi(ECG);

        QMetaObject::connectSlotsByName(ECG);
    } // setupUi

    void retranslateUi(QWidget *ECG)
    {
        ECG->setWindowTitle(QApplication::translate("ECG", "ECG", nullptr));
        ECG_num->setText(QApplication::translate("ECG", "NO.001", nullptr));
        label->setText(QApplication::translate("ECG", "\347\274\226\345\217\267\357\274\232", nullptr));
        ECG_name->setText(QApplication::translate("ECG", "\346\235\216\345\255\246\347\277\260", nullptr));
        ECG_ecg->setText(QApplication::translate("ECG", "86", nullptr));
        label_3->setText(QApplication::translate("ECG", "\346\240\207\345\207\206", nullptr));
        label_4->setText(QApplication::translate("ECG", "50 - 80", nullptr));
        ECG_breath->setText(QApplication::translate("ECG", "86", nullptr));
        label_6->setText(QApplication::translate("ECG", "\346\240\207\345\207\206", nullptr));
        label_7->setText(QApplication::translate("ECG", "50 - 80", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ECG: public Ui_ECG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECG_H

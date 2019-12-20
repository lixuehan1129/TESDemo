/********************************************************************************
** Form generated from reading UI file 'Replay.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_Replay
{
public:
    QLabel *label_27;
    QLabel *label;
    QLabel *label_name;
    QLabel *label_3;
    QLabel *label_pro;
    QLabel *label_time;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_score;
    QLabel *label_video1;
    QLabel *label_9;
    QLabel *label_video2;
    QLabel *label_10;
    QLabel *label_video3;
    QLabel *label_11;
    QLabel *label_12;
    QChartView *chartView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QLabel *label_pos;
    QLabel *label_14;
    QLabel *label_total;
    QSlider *slider;
    QPushButton *pushButton_on;
    QPushButton *pushButton_star;
    QLabel *label_remark;

    void setupUi(QWidget *Replay)
    {
        if (Replay->objectName().isEmpty())
            Replay->setObjectName(QString::fromUtf8("Replay"));
        Replay->resize(1030, 800);
        Replay->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        label_27 = new QLabel(Replay);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(385, 0, 260, 40));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_27->setFont(font);
        label_27->setLayoutDirection(Qt::LeftToRight);
        label_27->setAlignment(Qt::AlignCenter);
        label = new QLabel(Replay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 50, 60, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label_name = new QLabel(Replay);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(220, 50, 80, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(15);
        label_name->setFont(font2);
        label_3 = new QLabel(Replay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 80, 60, 25));
        label_3->setFont(font1);
        label_pro = new QLabel(Replay);
        label_pro->setObjectName(QString::fromUtf8("label_pro"));
        label_pro->setGeometry(QRect(220, 80, 100, 25));
        label_pro->setFont(font2);
        label_time = new QLabel(Replay);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(260, 110, 150, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(12);
        label_time->setFont(font3);
        label_6 = new QLabel(Replay);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 110, 101, 25));
        label_6->setFont(font1);
        label_7 = new QLabel(Replay);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(700, 50, 60, 25));
        label_7->setFont(font1);
        label_score = new QLabel(Replay);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(770, 40, 90, 90));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(40);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_score->setFont(font4);
        label_score->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_score->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_video1 = new QLabel(Replay);
        label_video1->setObjectName(QString::fromUtf8("label_video1"));
        label_video1->setGeometry(QRect(20, 180, 320, 180));
        label_video1->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Replay);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(150, 155, 60, 20));
        label_9->setAlignment(Qt::AlignCenter);
        label_video2 = new QLabel(Replay);
        label_video2->setObjectName(QString::fromUtf8("label_video2"));
        label_video2->setGeometry(QRect(360, 180, 320, 180));
        label_video2->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Replay);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(490, 155, 60, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_video3 = new QLabel(Replay);
        label_video3->setObjectName(QString::fromUtf8("label_video3"));
        label_video3->setGeometry(QRect(700, 180, 320, 180));
        label_video3->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Replay);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(830, 155, 60, 20));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(Replay);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(485, 380, 60, 20));
        label_12->setAlignment(Qt::AlignCenter);
        chartView = new QChartView(Replay);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setGeometry(QRect(15, 400, 1000, 190));
        layoutWidget = new QWidget(Replay);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(840, 610, 171, 20));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_2->addWidget(label_13);

        label_pos = new QLabel(layoutWidget);
        label_pos->setObjectName(QString::fromUtf8("label_pos"));
        label_pos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_pos);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_2->addWidget(label_14);

        label_total = new QLabel(layoutWidget);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        horizontalLayout_2->addWidget(label_total);

        slider = new QSlider(Replay);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(20, 630, 990, 20));
        slider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"        width: 6px;\n"
"        background: rgb(0, 160, 230);\n"
"        border-radius: 5px;\n"
"}"));
        slider->setOrientation(Qt::Horizontal);
        pushButton_on = new QPushButton(Replay);
        pushButton_on->setObjectName(QString::fromUtf8("pushButton_on"));
        pushButton_on->setGeometry(QRect(15, 700, 80, 30));
        QFont font5;
        font5.setPointSize(12);
        pushButton_on->setFont(font5);
        pushButton_star = new QPushButton(Replay);
        pushButton_star->setObjectName(QString::fromUtf8("pushButton_star"));
        pushButton_star->setGeometry(QRect(130, 700, 80, 30));
        pushButton_star->setFont(font5);
        label_remark = new QLabel(Replay);
        label_remark->setObjectName(QString::fromUtf8("label_remark"));
        label_remark->setGeometry(QRect(330, 700, 300, 90));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        label_remark->setFont(font6);
        label_remark->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_remark->setWordWrap(true);

        retranslateUi(Replay);

        QMetaObject::connectSlotsByName(Replay);
    } // setupUi

    void retranslateUi(QWidget *Replay)
    {
        Replay->setWindowTitle(QApplication::translate("Replay", "Replay", nullptr));
        label_27->setText(QApplication::translate("Replay", "\344\270\252\344\272\272\350\256\255\347\273\203\347\273\206\350\212\202", nullptr));
        label->setText(QApplication::translate("Replay", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_name->setText(QApplication::translate("Replay", "\346\235\216\345\255\246\347\277\260", nullptr));
        label_3->setText(QApplication::translate("Replay", "\347\247\221\347\233\256\357\274\232", nullptr));
        label_pro->setText(QApplication::translate("Replay", "\351\253\230\346\212\254\350\205\277\350\267\221", nullptr));
        label_time->setText(QApplication::translate("Replay", "2019.12.12-12\357\274\23200", nullptr));
        label_6->setText(QApplication::translate("Replay", "\350\256\255\347\273\203\346\227\266\351\227\264\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Replay", "\345\276\227\345\210\206\357\274\232", nullptr));
        label_score->setText(QApplication::translate("Replay", "85", nullptr));
        label_video1->setText(QString());
        label_9->setText(QApplication::translate("Replay", "\347\224\273\351\235\242\344\270\200", nullptr));
        label_video2->setText(QString());
        label_10->setText(QApplication::translate("Replay", "\347\224\273\351\235\242\344\272\214", nullptr));
        label_video3->setText(QString());
        label_11->setText(QApplication::translate("Replay", "\347\224\273\351\235\242\344\270\211", nullptr));
        label_12->setText(QApplication::translate("Replay", "\345\277\203\347\216\207", nullptr));
        label_13->setText(QApplication::translate("Replay", "\346\227\266\351\227\264:", nullptr));
        label_pos->setText(QApplication::translate("Replay", "0:00:00", nullptr));
        label_14->setText(QApplication::translate("Replay", "/", nullptr));
        label_total->setText(QApplication::translate("Replay", "0:00:00", nullptr));
        pushButton_on->setText(QApplication::translate("Replay", "\345\274\200\345\247\213", nullptr));
        pushButton_star->setText(QApplication::translate("Replay", "\346\240\207\350\256\260", nullptr));
        label_remark->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Replay: public Ui_Replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H

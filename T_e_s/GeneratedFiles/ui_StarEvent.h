/********************************************************************************
** Form generated from reading UI file 'StarEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAREVENT_H
#define UI_STAREVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarEvent
{
public:
    QPushButton *pushButton_sure;
    QPushButton *pushButton_cancel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_add;

    void setupUi(QDialog *StarEvent)
    {
        if (StarEvent->objectName().isEmpty())
            StarEvent->setObjectName(QString::fromUtf8("StarEvent"));
        StarEvent->resize(400, 300);
        pushButton_sure = new QPushButton(StarEvent);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));
        pushButton_sure->setGeometry(QRect(190, 260, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        pushButton_sure->setFont(font);
        pushButton_cancel = new QPushButton(StarEvent);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(290, 260, 75, 23));
        pushButton_cancel->setFont(font);
        gridLayoutWidget = new QWidget(StarEvent);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(29, 9, 341, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_add = new QPushButton(StarEvent);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(30, 260, 75, 23));
        pushButton_add->setFont(font);

        retranslateUi(StarEvent);

        QMetaObject::connectSlotsByName(StarEvent);
    } // setupUi

    void retranslateUi(QDialog *StarEvent)
    {
        StarEvent->setWindowTitle(QApplication::translate("StarEvent", "StarEvent", nullptr));
        pushButton_sure->setText(QApplication::translate("StarEvent", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("StarEvent", "\345\217\226\346\266\210", nullptr));
        pushButton_add->setText(QApplication::translate("StarEvent", "\346\267\273\345\212\240\346\214\207\346\240\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StarEvent: public Ui_StarEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAREVENT_H

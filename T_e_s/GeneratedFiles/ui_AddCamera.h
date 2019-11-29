/********************************************************************************
** Form generated from reading UI file 'AddCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCAMERA_H
#define UI_ADDCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCamera
{
public:
    QLineEdit *lineEdit_pw;
    QPushButton *pushButton_sure;
    QLabel *label_port;
    QLabel *label_pw;
    QLineEdit *lineEdit_port;
    QLabel *label_name;
    QLineEdit *lineEdit_user;
    QPushButton *pushButton_cancel;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_ip;
    QLabel *label_user;
    QLabel *label_ip;

    void setupUi(QWidget *AddCamera)
    {
        if (AddCamera->objectName().isEmpty())
            AddCamera->setObjectName(QString::fromUtf8("AddCamera"));
        AddCamera->resize(355, 320);
        lineEdit_pw = new QLineEdit(AddCamera);
        lineEdit_pw->setObjectName(QString::fromUtf8("lineEdit_pw"));
        lineEdit_pw->setGeometry(QRect(150, 150, 141, 25));
        pushButton_sure = new QPushButton(AddCamera);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));
        pushButton_sure->setGeometry(QRect(90, 250, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        pushButton_sure->setFont(font);
        label_port = new QLabel(AddCamera);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(50, 190, 81, 25));
        label_port->setFont(font);
        label_port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_pw = new QLabel(AddCamera);
        label_pw->setObjectName(QString::fromUtf8("label_pw"));
        label_pw->setGeometry(QRect(50, 150, 81, 25));
        label_pw->setFont(font);
        label_pw->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_port = new QLineEdit(AddCamera);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(150, 190, 141, 25));
        label_name = new QLabel(AddCamera);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(50, 30, 81, 25));
        label_name->setFont(font);
        label_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_user = new QLineEdit(AddCamera);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(150, 110, 141, 25));
        pushButton_cancel = new QPushButton(AddCamera);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 250, 75, 23));
        pushButton_cancel->setFont(font);
        lineEdit_name = new QLineEdit(AddCamera);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(150, 30, 141, 25));
        lineEdit_ip = new QLineEdit(AddCamera);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(150, 70, 141, 25));
        label_user = new QLabel(AddCamera);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(50, 110, 81, 25));
        label_user->setFont(font);
        label_user->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ip = new QLabel(AddCamera);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(50, 70, 81, 25));
        label_ip->setFont(font);
        label_ip->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(AddCamera);

        QMetaObject::connectSlotsByName(AddCamera);
    } // setupUi

    void retranslateUi(QWidget *AddCamera)
    {
        AddCamera->setWindowTitle(QApplication::translate("AddCamera", "AddCamera", nullptr));
        pushButton_sure->setText(QApplication::translate("AddCamera", "\347\241\256\345\256\232", nullptr));
        label_port->setText(QApplication::translate("AddCamera", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_pw->setText(QApplication::translate("AddCamera", "\345\257\206  \347\240\201", nullptr));
        label_name->setText(QApplication::translate("AddCamera", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        pushButton_cancel->setText(QApplication::translate("AddCamera", "\345\217\226\346\266\210", nullptr));
        label_user->setText(QApplication::translate("AddCamera", "\350\264\246  \345\217\267", nullptr));
        label_ip->setText(QApplication::translate("AddCamera", "IP  \345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCamera: public Ui_AddCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCAMERA_H

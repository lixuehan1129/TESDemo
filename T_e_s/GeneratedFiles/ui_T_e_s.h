/********************************************************************************
** Form generated from reading UI file 'T_e_s.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_E_S_H
#define UI_T_E_S_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T_e_sClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *widget_title;
    QLabel *label_name;
    QLabel *label_icon;
    QListWidget *listWidget_enter;
    QPushButton *pushButton_close;
    QPushButton *pushButton_min;
    QPushButton *pushButton_set;
    QLabel *label;
    QPushButton *pushButton_add;
    QWidget *widget_bottom;
    QLabel *label_detail;
    QLabel *label_detail_2;
    QLabel *label_detail_time;
    QLabel *label_detail_5;
    QStackedWidget *stackedWidget;
    QWidget *page_one;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_phy;
    QPushButton *pushButton_res;
    QPushButton *pushButton_device;
    QPushButton *pushButton_data;
    QPushButton *pushButton_reg;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *page_two;
    QTabWidget *tabWidget;
    QWidget *tab_person;
    QListWidget *listWidget_personBody;
    QWidget *tab_phy;
    QWidget *tab_res;
    QWidget *page_three;
    QWidget *page_four;
    QLabel *label_video1;
    QLabel *label_video2;
    QLabel *label_3;
    QLabel *label_15;
    QWidget *widget_4_left;
    QLabel *label_4_title;
    QPushButton *pushButton_begin;
    QLabel *label_16;
    QLabel *label_17;
    QComboBox *comboBox_video1;
    QComboBox *comboBox_video2;
    QLabel *label_18;
    QLabel *label_19;
    QListWidget *listWidget_test_staff;
    QLabel *label_4_left;
    QListWidget *listWidget_xinlv;
    QLabel *label_20;
    QWidget *page_five;
    QWidget *page_six;
    QFrame *line_top;

    void setupUi(QMainWindow *T_e_sClass)
    {
        if (T_e_sClass->objectName().isEmpty())
            T_e_sClass->setObjectName(QString::fromUtf8("T_e_sClass"));
        T_e_sClass->resize(1210, 730);
        centralWidget = new QWidget(T_e_sClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1210, 730));
        widget_title = new QWidget(widget);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setGeometry(QRect(5, 5, 1200, 79));
        label_name = new QLabel(widget_title);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(70, 20, 170, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_name->setFont(font);
        label_name->setLayoutDirection(Qt::LeftToRight);
        label_name->setTextFormat(Qt::AutoText);
        label_icon = new QLabel(widget_title);
        label_icon->setObjectName(QString::fromUtf8("label_icon"));
        label_icon->setGeometry(QRect(20, 20, 40, 40));
        label_icon->setText(QString::fromUtf8(""));
        label_icon->setPixmap(QPixmap(QString::fromUtf8("Resources/icon.png")));
        label_icon->setScaledContents(true);
        listWidget_enter = new QListWidget(widget_title);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_enter);
        __qlistwidgetitem->setFont(font1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_enter);
        __qlistwidgetitem1->setFont(font2);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_enter);
        __qlistwidgetitem2->setFont(font1);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget_enter);
        __qlistwidgetitem3->setFont(font1);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget_enter);
        __qlistwidgetitem4->setFont(font1);
        listWidget_enter->setObjectName(QString::fromUtf8("listWidget_enter"));
        listWidget_enter->setGeometry(QRect(270, 22, 500, 40));
        QFont font3;
        font3.setPointSize(10);
        listWidget_enter->setFont(font3);
        listWidget_enter->setAcceptDrops(true);
        listWidget_enter->setLayoutDirection(Qt::LeftToRight);
        listWidget_enter->setAutoFillBackground(false);
        listWidget_enter->setFrameShape(QFrame::NoFrame);
        listWidget_enter->setFrameShadow(QFrame::Sunken);
        listWidget_enter->setDragEnabled(false);
        listWidget_enter->setFlow(QListView::LeftToRight);
        listWidget_enter->setResizeMode(QListView::Fixed);
        listWidget_enter->setGridSize(QSize(100, 0));
        pushButton_close = new QPushButton(widget_title);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(1170, 33, 12, 12));
        pushButton_close->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_close->setIconSize(QSize(10, 10));
        pushButton_min = new QPushButton(widget_title);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(1140, 33, 13, 13));
        pushButton_min->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_min->setIconSize(QSize(10, 10));
        pushButton_set = new QPushButton(widget_title);
        pushButton_set->setObjectName(QString::fromUtf8("pushButton_set"));
        pushButton_set->setGeometry(QRect(1080, 28, 25, 25));
        pushButton_set->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_set->setIconSize(QSize(20, 20));
        label = new QLabel(widget_title);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1120, 28, 10, 23));
        label->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        label->setMidLineWidth(0);
        label->setPixmap(QPixmap(QString::fromUtf8("Resources/ic_ge.png")));
        label->setScaledContents(true);
        pushButton_add = new QPushButton(widget_title);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(1040, 28, 25, 25));
        pushButton_add->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_add->setIconSize(QSize(20, 20));
        widget_bottom = new QWidget(widget);
        widget_bottom->setObjectName(QString::fromUtf8("widget_bottom"));
        widget_bottom->setGeometry(QRect(5, 695, 1200, 30));
        label_detail = new QLabel(widget_bottom);
        label_detail->setObjectName(QString::fromUtf8("label_detail"));
        label_detail->setGeometry(QRect(20, 6, 231, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font4.setPointSize(12);
        label_detail->setFont(font4);
        label_detail_2 = new QLabel(widget_bottom);
        label_detail_2->setObjectName(QString::fromUtf8("label_detail_2"));
        label_detail_2->setGeometry(QRect(240, 6, 401, 20));
        label_detail_2->setFont(font4);
        label_detail_time = new QLabel(widget_bottom);
        label_detail_time->setObjectName(QString::fromUtf8("label_detail_time"));
        label_detail_time->setGeometry(QRect(920, 6, 271, 20));
        label_detail_time->setFont(font4);
        label_detail_5 = new QLabel(widget_bottom);
        label_detail_5->setObjectName(QString::fromUtf8("label_detail_5"));
        label_detail_5->setGeometry(QRect(840, 6, 85, 20));
        label_detail_5->setFont(font4);
        label_detail->raise();
        label_detail_2->raise();
        label_detail_5->raise();
        label_detail_time->raise();
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(5, 85, 1200, 610));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page_one = new QWidget();
        page_one->setObjectName(QString::fromUtf8("page_one"));
        label_2 = new QLabel(page_one);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(525, 85, 150, 50));
        QFont font5;
        font5.setPointSize(26);
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(page_one);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 130, 400, 50));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Algerian"));
        font6.setPointSize(14);
        label_4->setFont(font6);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_phy = new QPushButton(page_one);
        pushButton_phy->setObjectName(QString::fromUtf8("pushButton_phy"));
        pushButton_phy->setGeometry(QRect(150, 250, 100, 100));
        pushButton_phy->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_phy->setIconSize(QSize(100, 100));
        pushButton_res = new QPushButton(page_one);
        pushButton_res->setObjectName(QString::fromUtf8("pushButton_res"));
        pushButton_res->setGeometry(QRect(350, 250, 100, 100));
        pushButton_res->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_res->setIconSize(QSize(100, 100));
        pushButton_device = new QPushButton(page_one);
        pushButton_device->setObjectName(QString::fromUtf8("pushButton_device"));
        pushButton_device->setGeometry(QRect(550, 250, 100, 100));
        pushButton_device->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_device->setIconSize(QSize(100, 100));
        pushButton_data = new QPushButton(page_one);
        pushButton_data->setObjectName(QString::fromUtf8("pushButton_data"));
        pushButton_data->setGeometry(QRect(750, 250, 100, 100));
        pushButton_data->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_data->setIconSize(QSize(100, 100));
        pushButton_reg = new QPushButton(page_one);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setGeometry(QRect(950, 250, 100, 100));
        pushButton_reg->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        pushButton_reg->setIconSize(QSize(100, 100));
        label_5 = new QLabel(page_one);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 360, 100, 21));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Algerian"));
        font7.setPointSize(12);
        label_5->setFont(font7);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_one);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(125, 380, 150, 25));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Algerian"));
        font8.setPointSize(10);
        label_6->setFont(font8);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_one);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(325, 380, 150, 25));
        label_7->setFont(font8);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(page_one);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 360, 100, 21));
        label_8->setFont(font7);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(page_one);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(525, 380, 150, 25));
        label_9->setFont(font8);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(page_one);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(550, 360, 100, 21));
        label_10->setFont(font7);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(page_one);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(725, 380, 150, 25));
        label_11->setFont(font8);
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(page_one);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(750, 360, 100, 21));
        label_12->setFont(font7);
        label_12->setLayoutDirection(Qt::LeftToRight);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(page_one);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(925, 380, 150, 25));
        label_13->setFont(font8);
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(page_one);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(950, 360, 100, 21));
        label_14->setFont(font7);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_14->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_one);
        label_4->raise();
        label_2->raise();
        pushButton_reg->raise();
        pushButton_data->raise();
        label_6->raise();
        label_5->raise();
        pushButton_phy->raise();
        label_7->raise();
        label_8->raise();
        pushButton_res->raise();
        label_9->raise();
        label_10->raise();
        pushButton_device->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        page_two = new QWidget();
        page_two->setObjectName(QString::fromUtf8("page_two"));
        page_two->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        tabWidget = new QTabWidget(page_two);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1200, 610));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font9.setPointSize(12);
        tabWidget->setFont(font9);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        tabWidget->setTabPosition(QTabWidget::West);
        tab_person = new QWidget();
        tab_person->setObjectName(QString::fromUtf8("tab_person"));
        tab_person->setFont(font9);
        tab_person->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        listWidget_personBody = new QListWidget(tab_person);
        listWidget_personBody->setObjectName(QString::fromUtf8("listWidget_personBody"));
        listWidget_personBody->setGeometry(QRect(0, 0, 1170, 608));
        listWidget_personBody->setStyleSheet(QString::fromUtf8("border-color: transparent;"));
        listWidget_personBody->setGridSize(QSize(0, 120));
        tabWidget->addTab(tab_person, QString());
        tab_phy = new QWidget();
        tab_phy->setObjectName(QString::fromUtf8("tab_phy"));
        tabWidget->addTab(tab_phy, QString());
        tab_res = new QWidget();
        tab_res->setObjectName(QString::fromUtf8("tab_res"));
        tabWidget->addTab(tab_res, QString());
        stackedWidget->addWidget(page_two);
        page_three = new QWidget();
        page_three->setObjectName(QString::fromUtf8("page_three"));
        stackedWidget->addWidget(page_three);
        page_four = new QWidget();
        page_four->setObjectName(QString::fromUtf8("page_four"));
        label_video1 = new QLabel(page_four);
        label_video1->setObjectName(QString::fromUtf8("label_video1"));
        label_video1->setGeometry(QRect(190, 30, 450, 270));
        label_video1->setAlignment(Qt::AlignCenter);
        label_video2 = new QLabel(page_four);
        label_video2->setObjectName(QString::fromUtf8("label_video2"));
        label_video2->setGeometry(QRect(190, 330, 450, 270));
        label_video2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_four);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 5, 60, 20));
        label_15 = new QLabel(page_four);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(200, 305, 60, 20));
        widget_4_left = new QWidget(page_four);
        widget_4_left->setObjectName(QString::fromUtf8("widget_4_left"));
        widget_4_left->setGeometry(QRect(2, 5, 175, 595));
        label_4_title = new QLabel(widget_4_left);
        label_4_title->setObjectName(QString::fromUtf8("label_4_title"));
        label_4_title->setGeometry(QRect(19, 20, 137, 30));
        QFont font10;
        font10.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font10.setPointSize(15);
        font10.setBold(true);
        font10.setWeight(75);
        label_4_title->setFont(font10);
        label_4_title->setAlignment(Qt::AlignCenter);
        pushButton_begin = new QPushButton(widget_4_left);
        pushButton_begin->setObjectName(QString::fromUtf8("pushButton_begin"));
        pushButton_begin->setGeometry(QRect(25, 510, 125, 40));
        QFont font11;
        font11.setPointSize(13);
        pushButton_begin->setFont(font11);
        label_16 = new QLabel(widget_4_left);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(47, 80, 81, 21));
        QFont font12;
        font12.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font12.setPointSize(11);
        label_16->setFont(font12);
        label_17 = new QLabel(widget_4_left);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 120, 40, 20));
        comboBox_video1 = new QComboBox(widget_4_left);
        comboBox_video1->setObjectName(QString::fromUtf8("comboBox_video1"));
        comboBox_video1->setGeometry(QRect(70, 120, 91, 22));
        comboBox_video2 = new QComboBox(widget_4_left);
        comboBox_video2->setObjectName(QString::fromUtf8("comboBox_video2"));
        comboBox_video2->setGeometry(QRect(70, 160, 91, 22));
        label_18 = new QLabel(widget_4_left);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 160, 40, 20));
        label_19 = new QLabel(widget_4_left);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 220, 75, 21));
        label_19->setFont(font12);
        label_19->setAlignment(Qt::AlignCenter);
        listWidget_test_staff = new QListWidget(widget_4_left);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget_test_staff);
        __qlistwidgetitem5->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget_test_staff);
        __qlistwidgetitem6->setTextAlignment(Qt::AlignCenter);
        listWidget_test_staff->setObjectName(QString::fromUtf8("listWidget_test_staff"));
        listWidget_test_staff->setGeometry(QRect(30, 250, 115, 200));
        listWidget_test_staff->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_test_staff->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_test_staff->setIconSize(QSize(0, 0));
        listWidget_test_staff->setTextElideMode(Qt::ElideMiddle);
        listWidget_test_staff->setGridSize(QSize(0, 25));
        listWidget_test_staff->setItemAlignment(Qt::AlignCenter);
        label_4_left = new QLabel(widget_4_left);
        label_4_left->setObjectName(QString::fromUtf8("label_4_left"));
        label_4_left->setGeometry(QRect(0, 0, 175, 595));
        label_4_left->raise();
        label_4_title->raise();
        pushButton_begin->raise();
        label_16->raise();
        label_17->raise();
        comboBox_video1->raise();
        comboBox_video2->raise();
        label_18->raise();
        label_19->raise();
        listWidget_test_staff->raise();
        listWidget_xinlv = new QListWidget(page_four);
        listWidget_xinlv->setObjectName(QString::fromUtf8("listWidget_xinlv"));
        listWidget_xinlv->setGeometry(QRect(650, 30, 540, 570));
        label_20 = new QLabel(page_four);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(880, 5, 60, 20));
        stackedWidget->addWidget(page_four);
        label_3->raise();
        label_15->raise();
        label_video1->raise();
        label_video2->raise();
        widget_4_left->raise();
        listWidget_xinlv->raise();
        label_20->raise();
        page_five = new QWidget();
        page_five->setObjectName(QString::fromUtf8("page_five"));
        stackedWidget->addWidget(page_five);
        page_six = new QWidget();
        page_six->setObjectName(QString::fromUtf8("page_six"));
        stackedWidget->addWidget(page_six);
        line_top = new QFrame(widget);
        line_top->setObjectName(QString::fromUtf8("line_top"));
        line_top->setGeometry(QRect(5, 84, 1200, 2));
        line_top->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 216);"));
        line_top->setFrameShadow(QFrame::Sunken);
        line_top->setFrameShape(QFrame::HLine);
        T_e_sClass->setCentralWidget(centralWidget);

        retranslateUi(T_e_sClass);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(T_e_sClass);
    } // setupUi

    void retranslateUi(QMainWindow *T_e_sClass)
    {
        T_e_sClass->setWindowTitle(QApplication::translate("T_e_sClass", "T_e_s", nullptr));
        label_name->setText(QApplication::translate("T_e_sClass", "\347\273\274\345\220\210\350\257\204\344\274\260\347\263\273\347\273\237", nullptr));

        const bool __sortingEnabled = listWidget_enter->isSortingEnabled();
        listWidget_enter->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_enter->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("T_e_sClass", "\347\263\273\347\273\237\351\246\226\351\241\265", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_enter->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("T_e_sClass", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_enter->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("T_e_sClass", "\350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_enter->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("T_e_sClass", "\350\257\204\344\274\260\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_enter->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("T_e_sClass", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        listWidget_enter->setSortingEnabled(__sortingEnabled);

        pushButton_close->setText(QString());
        pushButton_min->setText(QString());
        pushButton_set->setText(QString());
        label->setText(QString());
        pushButton_add->setText(QString());
        label_detail->setText(QApplication::translate("T_e_sClass", "\346\254\242\350\277\216\344\275\277\347\224\250\347\273\274\345\220\210\350\257\204\344\274\260\347\263\273\347\273\237 V1.0", nullptr));
        label_detail_2->setText(QApplication::translate("T_e_sClass", "\346\212\200\346\234\257\346\224\257\346\214\201\357\274\232\345\214\227\344\272\254\347\247\221\346\212\200\345\244\247\345\255\246 XXXXXXXXX@ustb.edu.cn", nullptr));
        label_detail_time->setText(QString());
        label_detail_5->setText(QApplication::translate("T_e_sClass", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QApplication::translate("T_e_sClass", "\345\277\253\351\200\237\345\274\200\345\247\213", nullptr));
        label_4->setText(QApplication::translate("T_e_sClass", "\347\263\273\347\273\237\351\246\226\351\241\265\357\274\214\351\200\211\346\213\251\345\212\237\350\203\275\346\250\241\345\235\227\350\277\233\345\205\245\350\207\252\345\212\250\350\257\204\344\274\260", nullptr));
        pushButton_phy->setText(QString());
        pushButton_res->setText(QString());
        pushButton_device->setText(QString());
        pushButton_data->setText(QString());
        pushButton_reg->setText(QString());
        label_5->setText(QApplication::translate("T_e_sClass", "\344\275\223\350\203\275\347\264\240\350\264\250\350\257\204\344\274\260", nullptr));
        label_6->setText(QApplication::translate("T_e_sClass", "\350\277\233\345\205\245\347\264\240\350\264\250\350\257\204\344\273\267\346\250\241\346\213\237\346\234\272", nullptr));
        label_7->setText(QApplication::translate("T_e_sClass", "\350\277\233\345\205\245\346\274\224\347\273\203\345\237\271\350\256\255\350\257\204\344\274\260\347\263\273\347\273\237", nullptr));
        label_8->setText(QApplication::translate("T_e_sClass", "\345\272\224\346\200\245\345\237\271\350\256\255\350\257\204\344\274\260", nullptr));
        label_9->setText(QApplication::translate("T_e_sClass", "\346\237\245\347\234\213\346\210\226\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        label_10->setText(QApplication::translate("T_e_sClass", "\350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
        label_11->setText(QApplication::translate("T_e_sClass", "\346\237\245\350\257\242\344\272\272\345\221\230\344\277\241\346\201\257\345\222\214\345\220\204\351\241\271\350\256\260\345\275\225", nullptr));
        label_12->setText(QApplication::translate("T_e_sClass", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        label_13->setText(QApplication::translate("T_e_sClass", "\346\267\273\345\212\240\346\226\260\346\210\220\345\221\230 \347\273\221\345\256\232\350\256\276\345\244\207", nullptr));
        label_14->setText(QApplication::translate("T_e_sClass", "\344\272\272\345\221\230\346\263\250\345\206\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_person), QApplication::translate("T_e_sClass", "\344\272\272\345\221\230\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_phy), QApplication::translate("T_e_sClass", "\344\275\223\350\203\275\350\257\204\344\274\260\350\256\260\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_res), QApplication::translate("T_e_sClass", "\345\237\271\350\256\255\350\257\204\344\274\260\350\256\260\345\275\225", nullptr));
        label_video1->setText(QString());
        label_video2->setText(QString());
        label_3->setText(QApplication::translate("T_e_sClass", "\347\224\273\351\235\242\344\270\200", nullptr));
        label_15->setText(QApplication::translate("T_e_sClass", "\347\224\273\351\235\242\344\272\214", nullptr));
        label_4_title->setText(QApplication::translate("T_e_sClass", "\345\256\236\346\227\266\347\233\221\346\265\213", nullptr));
        pushButton_begin->setText(QApplication::translate("T_e_sClass", "\345\274\200\345\247\213", nullptr));
        label_16->setText(QApplication::translate("T_e_sClass", "\346\221\204\345\203\217\345\244\264\351\200\211\346\213\251", nullptr));
        label_17->setText(QApplication::translate("T_e_sClass", "\347\224\273\351\235\242\344\270\200", nullptr));
        label_18->setText(QApplication::translate("T_e_sClass", "\347\224\273\351\235\242\344\272\214", nullptr));
        label_19->setText(QApplication::translate("T_e_sClass", "\345\217\202\344\270\216\344\272\272\345\221\230", nullptr));

        const bool __sortingEnabled1 = listWidget_test_staff->isSortingEnabled();
        listWidget_test_staff->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = listWidget_test_staff->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("T_e_sClass", "\345\217\202\344\270\216\344\272\272\345\221\230\344\270\200", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_test_staff->item(1);
        ___qlistwidgetitem6->setText(QApplication::translate("T_e_sClass", "\345\217\202\344\270\216\344\272\272\345\221\230\344\272\214", nullptr));
        listWidget_test_staff->setSortingEnabled(__sortingEnabled1);

        label_4_left->setText(QString());
        label_20->setText(QApplication::translate("T_e_sClass", "\345\277\203\347\216\207\347\233\221\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_e_sClass: public Ui_T_e_sClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_E_S_H

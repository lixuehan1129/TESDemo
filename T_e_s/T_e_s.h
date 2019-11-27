#pragma once
#define NOMINMAX


#include <QtWidgets/QMainWindow>
#include "ui_T_e_s.h"
#include <QTimer>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <PersonBody.h>
#include "HK_camera.h"
#include <HKCamDriver.h>

#include <iostream>

using namespace std;


class T_e_s : public QMainWindow
{
	Q_OBJECT

public:
	T_e_s(QWidget *parent = Q_NULLPTR);
	~T_e_s();
	void initStatus();
	QTimer *myTimer;

	QMap<QListWidgetItem*, QListWidgetItem*> groupMap;   // 组容器 - key:项 value:组  
	void addListPerson();
	

public slots:
    void GetDateTime();//动态显示时间

private slots:
	void on_listWidget_enter_clicked();
	void on_pushButton_add_clicked();
	void on_pushButton_set_clicked();
	void on_pushButton_min_clicked();
	void on_pushButton_close_clicked();
	void on_pushButton_phy_clicked();
	void on_pushButton_res_clicked();
	void on_pushButton_device_clicked();
	void on_pushButton_data_clicked();
	void on_pushButton_reg_clicked();
	void on_pushButton_begin_clicked();
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void getFrame1();
	void getFrame2();
	


private:
	Ui::T_e_sClass ui;
	bool m_Drag;                //判断鼠标左键是否按下
	QPoint m_DragPosition;
	void setItemColor(int index);
	void paintEvent(QPaintEvent *event);
	void styleSheet();
	void buttonChange(int i);
	QString color1 = "#4182C3";
	QString color2 = "#17abe3";
	QString color3 = "#2a79bd";
	QTimer* timer;

	cv::VideoCapture cap1,cap2;


	QImage image;

	void HK();
	HKCamDriver m_CamDriver[2];
	cv::Mat video[2];

	
};

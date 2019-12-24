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
#include <AddCamera.h>
#include <AddPerson.h>
#include <ECG.h>
#include <iostream>
#include "DBHelper.h"
#include "direct.h"
#include "io.h"
#include "Replay.h"

using namespace std;

#define MAX_ECG 4

class T_e_s : public QMainWindow
{
	Q_OBJECT

public:
	T_e_s(QWidget *parent = Q_NULLPTR);
	~T_e_s();
	void initStatus();
	QTimer *myTimer;
	void addListPerson();

	QString color1 = "#4182C3";
	QString color2 = "#17abe3";
	QString color3 = "#2a79bd";
	
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
	void on_pushButton_addDevice_clicked();
	void on_pushButton_addEcg_clicked();
	void on_pushButton_begin_clicked();
	void on_comboBox_video1_currentIndexChanged(int index);
	void on_comboBox_video2_currentIndexChanged(int index);
	//void mouseReleaseEvent(QMouseEvent *event);
	//void mouseMoveEvent(QMouseEvent *event);
	//void mousePressEvent(QMouseEvent *event);
	void getFrame1();
	void getFrame2();

	void buttonEn();

	void GoTrainDetail();
	void on_pushButton_back_per2_clicked();

	void getDeviceData(Device device);

	//计时器
	void updateTime();

	//折线图
	void updateGetChart();
	void slotPointHoverd(const QPointF &point, bool state);
	void slotPointClicked(const QPointF &point);

	void getPerson(Person person);
	
signals:
	void updateChart();

	void replayGo(int pro, int x, int y);

private:
	Ui::T_e_sClass ui;
	bool m_Drag;                //判断鼠标左键是否按下
	QPoint m_DragPosition;
	void setItemColor(int index);
	void paintEvent(QPaintEvent *event);
	void styleSheet();
	void buttonChange(int i);
	void PersonEvent();
	QTimer* timer;

	cv::VideoCapture cap1,cap2;
	QImage image;

	void HK();
	HKCamDriver m_CamDriver[2];
	cv::Mat video[2];

	//录制
	//QString qStrTime;
	bool videoWriteOpen = false;
	VideoWriter outputVideo[2];

	QTimer *buttonTimer;


	ECG *ecg[MAX_ECG];
	void EcgSet(int item);
	DBHelper dBHelper;

	//摄像头
	QList<Device> devices;	
	void initDeviceData();
	int deviceRow = 0;

	QTimer* HKtimer; //显示视频
	//第一、二个选中的摄像头编号
	int firstDevice = 0, secondDevice = 1;
	bool initCombo();
	void changeCombox(Device device);

	//摄像头下拉框开启
	bool comboxOpen = false;

	//计时器
	QTimer* recordTimer;
	QTime* recordTime;
	void initRecordTime();

	//第二页第二部分
	void initTrain();
	//折线图
	QTimer* chartTimer;
	void initChart(int i);
	QChart* createLineChart() const;
	void TableStyle();

	//人员数据
	
	QList<Person> persons;
	

	

	
};

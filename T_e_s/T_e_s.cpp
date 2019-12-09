#include "T_e_s.h"
#include "QMessageBox"   //弹出窗口
#include "QGraphicsOpacityEffect"
#include "qpainter.h"
#include <QTime>
#include <QMouseEvent>
#include <qdebug.h>
//#include <vld.h>


#pragma execution_character_set("utf-8") 

/*
  from UI带师 刘子涵
*/
class CustomTabStyle : public QProxyStyle  //使用 QProxyStyle修改控件默认系统样式， 左侧选择栏
{
public:
	QSize sizeFromContents(ContentsType type, const QStyleOption *option,
		const QSize &size, const QWidget *widget) const
	{
		QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
		if (type == QStyle::CT_TabBarTab) {
			s.transpose();
			s.rwidth() = 140; // 设置每个tabBar中item的大小
			s.rheight() = 44;
		}
		return s;
	}
	void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
	{
		if (element == CE_TabBarTabLabel) {
			if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
				QRect allRect = tab->rect;

				if (tab->state & QStyle::State_Selected) {
					painter->save();
					painter->setPen("#87CEEB");
					painter->setBrush(QBrush(QColor("#87CEEB")
					));
					painter->drawRect(allRect.adjusted(6, 6, -6, -6));
					painter->restore();
				}
				QTextOption option;
				option.setAlignment(Qt::AlignCenter);
				if (tab->state & QStyle::State_Selected) {
					painter->save();
					painter->setPen(0xffffff);
					painter->restore();
				}
				else {
					painter->save();
					painter->setPen((0x778f98));
					painter->restore();
				}
				painter->drawText(allRect, tab->text, option);
				return;
			}
		}

		if (element == CE_TabBarTab) {
			QProxyStyle::drawControl(element, option, painter, widget);
		}
	}
};


T_e_s::T_e_s(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initStatus();
	dBHelper.createConnection();
	dBHelper.createTable();
}

T_e_s::~T_e_s()
{
	dBHelper.close();

}

void T_e_s::initStatus()
{

	styleSheet();

	//顶部导航栏


	//右侧按钮
	


	//中间功能界面 


	//第一页按钮


	//第二页
	//定义人员管理数据
	addListPerson();
	addListPerson();

	//第三页
	initDeviceData();

	//第四页
	//获取视频

	//创建存放视频文件的文件夹
	std::string prefix = "./VideoStore/";
	if (_access(prefix.c_str(), 0) == -1)	//如果文件夹不存在
		_mkdir(prefix.c_str());				//则创建
	
	EcgSet(0);
	EcgSet(1);


	//底部
	//显示日期时间
	QDateTime dateTime(QDateTime::currentDateTime());
	QString qStr = dateTime.toString("yyyy年MM月dd日 hh:mm:ss dddd");
	ui.label_detail_time->setText(qStr);
	myTimer = new QTimer(this);
	myTimer->start(1000);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(GetDateTime()));
	
}

//快速开始按钮时间
void T_e_s::on_pushButton_phy_clicked()
{
	setItemColor(3);
	ui.stackedWidget->setCurrentIndex(3);	
}
void T_e_s::on_pushButton_res_clicked()
{
	//setItemColor(3);
	//ui.stackedWidget->setCurrentIndex(3);
	QMessageBox::about(NULL, "提醒", "请打开事故应急演练评估");
}
void T_e_s::on_pushButton_device_clicked()
{
	setItemColor(2);
	ui.stackedWidget->setCurrentIndex(2);
}
void T_e_s::on_pushButton_data_clicked()
{
	setItemColor(1);
	ui.stackedWidget->setCurrentIndex(1);
}

//添加用户
void T_e_s::on_pushButton_reg_clicked()
{
	PersonEvent();
}

//添加用户
void T_e_s::on_pushButton_add_clicked()
{
	PersonEvent();
}


//系统设置，跳转页面six
void T_e_s::on_pushButton_set_clicked()
{
	ui.stackedWidget->setCurrentIndex(5);
}

//注册成员
void T_e_s::PersonEvent()
{
	AddPerson* addPerson = new AddPerson;
	addPerson->setWindowModality(Qt::ApplicationModal);
	addPerson->setWindowTitle(QObject::tr("输入设备信息"));
	addPerson->setWindowFlags(Qt::WindowStaysOnTopHint);

	addPerson->show();

}

//第三页

void T_e_s::initDeviceData()
{
	devices = dBHelper.getDevice();
	for (int i = 0; i < devices.size(); i++)
	{
		ui.tableWidget_addDevice->setItem(i, 0, new QTableWidgetItem(QString("%1").arg(i+1)));
		ui.tableWidget_addDevice->setItem(i, 1, new QTableWidgetItem(devices[i].cameraName));
		ui.tableWidget_addDevice->setItem(i, 2, new QTableWidgetItem(devices[i].cameraIp));
		ui.tableWidget_addDevice->setItem(i, 3, new QTableWidgetItem(devices[i].cameraPort));
		ui.tableWidget_addDevice->setItem(i, 4, new QTableWidgetItem(devices[i].cameraUser));
		ui.tableWidget_addDevice->setItem(i, 5, new QTableWidgetItem(devices[i].cameraPw));		
	}
	deviceRow = devices.size();
	ui.tableWidget_addDevice->show();

	//第四页,设置combox
	initCombo();
}

void T_e_s::on_pushButton_addDevice_clicked() {
	AddCamera* add = new AddCamera;
	add->setWindowModality(Qt::ApplicationModal);
	add->setWindowTitle(QObject::tr("输入设备信息"));
	add->setWindowFlags(Qt::WindowStaysOnTopHint);
	
	add->show();
	connect(add, SIGNAL(SendData(Device)), this, SLOT(getDeviceData(Device)));
}

void T_e_s::getDeviceData(Device device)
{
	devices << device;
	ui.tableWidget_addDevice->setItem(deviceRow, 0, new QTableWidgetItem(QString("%1").arg(deviceRow + 1)));
	ui.tableWidget_addDevice->setItem(deviceRow, 1, new QTableWidgetItem(device.cameraName));
	ui.tableWidget_addDevice->setItem(deviceRow, 2, new QTableWidgetItem(device.cameraIp));
	ui.tableWidget_addDevice->setItem(deviceRow, 3, new QTableWidgetItem(device.cameraPort));
	ui.tableWidget_addDevice->setItem(deviceRow, 4, new QTableWidgetItem(device.cameraUser));
	ui.tableWidget_addDevice->setItem(deviceRow, 5, new QTableWidgetItem(device.cameraPw));
	//qDebug() << device.cameraIp << deviceRow;
	ui.tableWidget_addDevice->show();
	deviceRow = devices.size();

	//initCombo();
	changeCombox(device);

}

void T_e_s::on_pushButton_addEcg_clicked() {

}

//第四页，开始
void T_e_s::on_pushButton_begin_clicked()
{
	ui.pushButton_begin->setEnabled(false);
	if (ui.pushButton_begin->text() == "开始")
	{
		ui.pushButton_begin->setText("停止");
		//ui.pushButton_begin->set
		buttonChange(2);

		ui.comboBox_video1->setEnabled(false);
		ui.comboBox_video2->setEnabled(false);

		videoWriteOpen = true;
		
		//文件名
		QDateTime dateTime(QDateTime::currentDateTime());
		QString qStr = dateTime.toString("yyyyMMddhhmmss");
		QString qStrTime1 = "./VideoStore/" + qStr + "_01.avi";
		QString qStrTime2 = "./VideoStore/" + qStr + "_02.avi";
		//m_CamDriver[0].saveData(qStrTime1);
		//m_CamDriver[1].saveData(qStrTime2);
		outputVideo[0].open(qStrTime1.toLatin1().data(), VideoWriter::fourcc('M', 'J', 'P', 'G'), 20.0, Size(640, 360));
		outputVideo[1].open(qStrTime2.toLatin1().data(), VideoWriter::fourcc('M', 'J', 'P', 'G'), 20.0, Size(640, 360));

		//ecg[0]->initData();
		//ecg[1]->initData();

		buttonTimer = new QTimer();
		buttonTimer->start(2000);
		connect(buttonTimer, SIGNAL(timeout()), this, SLOT(buttonEn()));
	}
	else
	{
		ui.pushButton_begin->setText("开始");
		buttonChange(1);

		ui.comboBox_video1->setEnabled(true);
		ui.comboBox_video2->setEnabled(true);

		videoWriteOpen = false;

		//m_CamDriver[0].stopData();
		//m_CamDriver[1].stopData();

		outputVideo[0].release();
		outputVideo[1].release();

		//ecg[0]->stopShow();
		//ecg[1]->stopShow();

		buttonTimer = new QTimer();
		buttonTimer->start(1500);
		connect(buttonTimer, SIGNAL(timeout()), this, SLOT(buttonEn()));
	}
}

void T_e_s::buttonEn()
{
	ui.pushButton_begin->setEnabled(true);
	buttonTimer->stop();
}


//第四页评估
bool T_e_s::initCombo()
{
	ui.comboBox_video1->clear();
	ui.comboBox_video2->clear();
	for (int i = 0; i < devices.size(); i++)
	{
		ui.comboBox_video1->addItem(devices[i].cameraIp);
		ui.comboBox_video2->addItem(devices[i].cameraIp);
	}
	HK();
	return true;

}

void T_e_s::HK()
{
	m_CamDriver[0].InitHKNetSDK();//
	m_CamDriver[0].SetScaleFactor(0.5f);
	//m_CamDriver[1].InitHKNetSDK();//
	//m_CamDriver[1].SetScaleFactor(0.5f);

	HKtimer = new QTimer(this);
	HKtimer->start(40);
	/*
	m_CamDriver[0].InitHKNetSDK();//
	m_CamDriver[0].SetScaleFactor(0.5f);
	m_CamDriver[0].InitCamera("192.168.1.101", "admin", "Zz123456");
	m_CamDriver[1].InitCamera("192.168.1.109", "admin", "Zz123456");

	QTimer* HKtimer = new QTimer(this);
	HKtimer->start(20);
	connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));
	connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));
	*/

	//qDebug() << "size" << devices.size();
	QVariant v(0);

	switch (devices.size())
	{
	case 0:
	{
		//没有摄像头
		ui.label_video1->setText("还没有连接设备");
		ui.label_video2->setText("还没有连接设备");
		break;
	}
	case 1:
	{
		//一个摄像头
		ui.comboBox_video1->setCurrentIndex(0);
		ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);

		
		//m_CamDriver[1].InitHKNetSDK();//
		//m_CamDriver[1].SetScaleFactor(0.5f);
		m_CamDriver[0].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
		m_CamDriver[1].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
	
		connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));

		ui.label_video2->setText("还没有连接设备");
		break;
	}
	default:
	{
		//2个及以上摄像头
		ui.comboBox_video1->setCurrentIndex(0);
		ui.comboBox_video2->setCurrentIndex(1);
		ui.comboBox_video1->setItemData(secondDevice, v, Qt::UserRole - 1);
		ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);
		//	ui.comboBox_video1->setItemData(secondDevice, Qt::lightGray, Qt::BackgroundColorRole);

		//m_CamDriver[0].InitHKNetSDK();//
		//m_CamDriver[0].SetScaleFactor(0.5f);
		//m_CamDriver[1].InitHKNetSDK();//
		//m_CamDriver[1].SetScaleFactor(0.5f);
		m_CamDriver[0].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
		m_CamDriver[1].InitCamera(devices[secondDevice].cameraIp.toLatin1().data(), devices[secondDevice].cameraUser.toLatin1().data(), devices[secondDevice].cameraPw.toLatin1().data());

		//HKtimer = new QTimer(this);
		//HKtimer->start(40);
		connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));
		connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));
		break;
	}
	}

	comboxOpen = true;
}

void T_e_s::changeCombox(Device device)
{
	ui.comboBox_video1->addItem(device.cameraIp);
	ui.comboBox_video2->addItem(device.cameraIp);
	QVariant v(0);
	switch (devices.size())
	{
	case 1:
	{
		//没有摄像头，增加一个
		ui.comboBox_video1->setCurrentIndex(0);
		//ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);
		ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);

		//m_CamDriver[0].InitHKNetSDK();//
		//m_CamDriver[0].SetScaleFactor(0.5f);
		//m_CamDriver[1].InitHKNetSDK();//
		//m_CamDriver[1].SetScaleFactor(0.5f);
		m_CamDriver[0].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
		m_CamDriver[1].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
		//HKtimer = new QTimer(this);
		//HKtimer->start(40);
		connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));

		ui.label_video2->setText("还没有连接设备");
		break;
	}
	case 2:
	{
		//有一个摄像头，后增加一个
		ui.comboBox_video2->setCurrentIndex(1);
		ui.comboBox_video1->setItemData(secondDevice, v, Qt::UserRole - 1);
		ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);

		if (m_CamDriver[1].ReleaseCamera())
		{
			m_CamDriver[1].InitCamera(devices[secondDevice].cameraIp.toLatin1().data(), devices[secondDevice].cameraUser.toLatin1().data(), devices[secondDevice].cameraPw.toLatin1().data());
			//QTimer* HKtimer = new QTimer(this);
			//HKtimer->start(40);
			//connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));
			HKtimer->stop();
			HKtimer = new QTimer(this);
			HKtimer->start(40);
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));
		}
		
		break;
	}
	default:
		break;
	}
}

//第四页，下拉选择
void T_e_s::on_comboBox_video1_currentIndexChanged(int index)
{
	if (comboxOpen)
	{
		QVariant v1(0);//不可选中
		QVariant v2(1 | 32);//可选中
		qDebug() << "1" << devices[index].cameraIp;

		if (m_CamDriver[0].ReleaseCamera())
		{

			m_CamDriver[0].InitCamera(devices[index].cameraIp.toLatin1().data(), devices[index].cameraUser.toLatin1().data(), devices[index].cameraPw.toLatin1().data());
			
			HKtimer->stop();
			HKtimer = new QTimer(this);
			HKtimer->start(40);
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));

			ui.comboBox_video2->setItemData(firstDevice, v2, Qt::UserRole - 1);
			firstDevice = index;
			ui.comboBox_video2->setItemData(firstDevice, v1, Qt::UserRole - 1);
		}
		
	}
	
}

void T_e_s::on_comboBox_video2_currentIndexChanged(int index)
{
	if (comboxOpen)
	{
		QVariant v1(0);//不可选中
		QVariant v2(1 | 32);//可选中
	//	qDebug() << "2" << index;
		qDebug() << "2" << devices[index].cameraIp;

		if (m_CamDriver[1].ReleaseCamera())
		{
			m_CamDriver[1].InitCamera(devices[index].cameraIp.toLatin1().data(), devices[index].cameraUser.toLatin1().data(), devices[index].cameraPw.toLatin1().data());
			
			//QTimer* HKtimer = new QTimer(this);
			//HKtimer->start(40);
			//connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));

			HKtimer->stop();
			HKtimer = new QTimer(this);
			HKtimer->start(40);
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));
			connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame2()));

			ui.comboBox_video1->setItemData(secondDevice, v2, Qt::UserRole - 1);
			secondDevice = index;
			ui.comboBox_video1->setItemData(secondDevice, v1, Qt::UserRole - 1);
		}

	}
	
}


//获取视频
//线程
void T_e_s::getFrame1()
{
	if (m_CamDriver[0].GetCamMat(video[0], NULL, 1.0f)) {
		if (video[0].empty())
		{
			ui.label_video1->setText("还没有连接设备");
		}
		else
		{
			//录制
			if (videoWriteOpen)
			{
				outputVideo[0].write(video[0]);
			}
			image = m_CamDriver[0].cvMat2QImage(video[0]);
			if (image.isNull())
			{
				ui.label_video1->setText("还没有连接设备");
				ui.label_video2->show();
			}
			else
			{
				ui.label_video1->setScaledContents(true);
				ui.label_video1->setPixmap(QPixmap::fromImage(image));
				ui.label_video1->show();
			}
		}
		
	}
}

void T_e_s::getFrame2()
{
	if (m_CamDriver[1].GetCamMat(video[1], NULL, 1.0f)) {
		if (video[1].empty())
		{
			ui.label_video2->setText("还没有连接设备");
		}
		else
		{
			//录制
			if (videoWriteOpen)
			{
				outputVideo[1].write(video[1]);
			}
			image = m_CamDriver[1].cvMat2QImage(video[1]);
			if (image.isNull())
			{
				ui.label_video2->setText("还没有连接设备");
				ui.label_video2->show();
			}
			else
			{
				ui.label_video2->setScaledContents(true);
				ui.label_video2->setPixmap(QPixmap::fromImage(image));
				ui.label_video2->show();
			}
		}
		
	}
}

//获取心率,初始化，还没有实质数据
void T_e_s::EcgSet(int item)
{
	ecg[item] = new ECG(this);
	QListWidgetItem *newItem = new QListWidgetItem(ui.listWidget_xinlv);
	newItem->setSizeHint(ecg[item]->size());
	//newItem->setText("dsadasda");
	ui.listWidget_xinlv->addItem(newItem);
	ui.listWidget_xinlv->setItemWidget(newItem, ecg[item]);

}


void T_e_s::addListPerson() {
	PersonBody *personBody = new PersonBody(this);
	PersonBodyBean *personBodyBean = new PersonBodyBean();
	personBodyBean->personHead = "./Resources/head.png";
	personBodyBean->personName = "李学翰";
	personBodyBean->personSex = "男";
	personBodyBean->personAge = "18";
	personBodyBean->personWeight = "65Kg";
	personBodyBean->personHeight = "170cm";
	personBodyBean->personStatus = "训练中，以能者为师，每一个训练项目都在班长的带领下选一个相对较熟练的人员负责指导训练，全体人员发扬不怕苦、不怕累的作风，克服工作多、训练时间少的困难。";
	personBody->setData(personBodyBean);

	QListWidgetItem *newItem = new QListWidgetItem(ui.listWidget_personBody);
	newItem->setSizeHint(personBody->size());
	//newItem->setText("dfd");
	ui.listWidget_personBody->addItem(newItem);

	ui.listWidget_personBody->setItemWidget(newItem,personBody);

}

//最小化
void T_e_s::on_pushButton_min_clicked()
{
	this->showMinimized();
}

//关闭
void T_e_s::on_pushButton_close_clicked()
{
	printf("Close\n");
	if (devices.size() > 0)
	{
		if (m_CamDriver[0].ReleaseCamera() && m_CamDriver[1].ReleaseCamera())
		{
			close();
		}
	}
	else
	{
		close();
	}	
}


void T_e_s::GetDateTime()
{
	QDateTime dateTime(QDateTime::currentDateTime());
	QString qStr = dateTime.toString("yyyy年MM月dd日 hh:mm:ss  dddd");
	ui.label_detail_time->setText(qStr);
}


//导航栏选中 跳转页面
void T_e_s::on_listWidget_enter_clicked()
{
	int currenRow = ui.listWidget_enter->currentRow();//当前单击选中ListWidget控件的行号（第几行）
													  //ui.listWidget_enter->item(currenRow)->setTextColor(QColor(30,144,255));
	setItemColor(currenRow);
	ui.stackedWidget->setCurrentIndex(currenRow);


}


void T_e_s::buttonChange(int i) 
{
	QStringList qssbtn;//按钮
	if (i == 1)
	{
		qssbtn.append(QString(
			"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
			"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
		).arg(color1).arg(color2).arg(color3));
	}
	else
	{
		qssbtn.append(QString(
			"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
			"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
		).arg("#CD2626").arg("#EE2C2C").arg("#CD2626"));
	}

	ui.pushButton_begin->setStyleSheet(qssbtn.join(""));
	
}
//设置格式
void T_e_s::styleSheet()
{
	//去掉窗口边框
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	//设置透明
	this->setAttribute(Qt::WA_TranslucentBackground);

	ui.widget->setStyleSheet("background-color:transparent");



	//顶部导航栏
	ui.widget_title->setStyleSheet("background-color:#EEF1F0");

	QListWidget *listWidget_enter = ui.listWidget_enter;
	listWidget_enter->setStyleSheet("background-color:transparent");
	listWidget_enter->setCurrentRow(0); //设置当前选择行默认为 0
	for (int i = 0; i < 5; i++) {
		QListWidgetItem* item = ui.listWidget_enter->item(i);
		item->setFlags(Qt::NoItemFlags);
		item->setFlags(Qt::ItemIsEnabled);
	}
	//默认第一页
	setItemColor(0);
	ui.stackedWidget->setCurrentIndex(0);


	//右侧按钮
	ui.pushButton_add->setToolTip(tr("注册新成员"));
	ui.pushButton_add->setStyleSheet("QPushButton{border-image: url(./Resources/ic_add_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_add_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_add_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_set->setToolTip(tr("设置"));
	ui.pushButton_set->setStyleSheet("QPushButton{border-image: url(./Resources/ic_set_b.png);width:25;height:25;background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_set_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_set_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_min->setToolTip(tr("最小化"));
	ui.pushButton_min->setStyleSheet("QPushButton{border-image: url(./Resources/ic_min_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_min_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_min_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_close->setToolTip(tr("退出"));
	ui.pushButton_close->setStyleSheet("QPushButton{border-image: url(./Resources/ic_close_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_close_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_close_b.png);background-repeat: no-repeat;background-position:center;border:none;}");



	//中间功能界面 
	//ui.stackedWidget->setStyleSheet("background-color:#FFFFFF"); //白色

	//第一页按钮快速
	ui.pushButton_phy->setStyleSheet("QPushButton{border-image: url(./Resources/icon2.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/icon2_1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/icon2.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_res->setStyleSheet("QPushButton{border-image: url(./Resources/icon3.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/icon3_1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/icon3.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_device->setStyleSheet("QPushButton{border-image: url(./Resources/icon1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/icon1_1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/icon1.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_data->setStyleSheet("QPushButton{border-image: url(./Resources/icon4.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/icon4_1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/icon4.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_reg->setStyleSheet("QPushButton{border-image: url(./Resources/icon5.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/icon5_1.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/icon5.png);background-repeat: no-repeat;background-position:center;border:none;}");


	//第二页
	ui.tabWidget->setTabPosition(QTabWidget::West);
	ui.tabWidget->tabBar()->setStyle(new CustomTabStyle);
	ui.tabWidget->setStyleSheet("QTabWidget::tab-bar{top:0px; }"
		"QTabWidget::pane{ \
            border-left: 1px solid #eeeeee;\
        }");
	ui.tabWidget->setCurrentIndex(0);

	//人员管理数据
	ui.listWidget_personBody->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
		"QListWidget::Item:hover{background:transparent; }"
		"QListWidget::item:selected{background:transparent; }"
		"QListWidget::item:selected:!active{border-width:0px; background:transparent; }"
		"QScrollBar{ width : 0; height : 0; }"
	);

	//第三页
	QStringList qssbtn;//按钮
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg(color1).arg(color2).arg(color3));


	ui.tabWidget_2->setTabPosition(QTabWidget::West);
	ui.tabWidget_2->tabBar()->setStyle(new CustomTabStyle);
	ui.tabWidget_2->setStyleSheet("QTabWidget::tab-bar{top:0px; }"
		"QTabWidget::pane{ \
            border-left: 1px solid #eeeeee;\
        }");
	ui.tabWidget_2->setCurrentIndex(0);

	ui.pushButton_addDevice->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addDevice_up->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addDevice_down->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addDevice_jump->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addEcg->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addEcg_up->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addEcg_down->setStyleSheet(qssbtn.join(""));
	ui.pushButton_addEcg_jump->setStyleSheet(qssbtn.join(""));

	ui.tableWidget_addDevice->setColumnCount(6);
	ui.tableWidget_addDevice->setRowCount(14);

	QStringList header;
	header << "编号" << tr("设备名") << "IP地址" << "端口号" << "用户名" << "密码";
	ui.tableWidget_addDevice->clear();
	ui.tableWidget_addDevice->setHorizontalHeaderLabels(header);
	ui.tableWidget_addDevice->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_addDevice->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidget_addDevice->setAlternatingRowColors(true);
	ui.tableWidget_addDevice->setStyleSheet("alternate-background-color:#FFFAF0;background:#B4EEB4;gridline-color:white");
	ui.tableWidget_addDevice->verticalHeader()->setHidden(true);
	ui.tableWidget_addDevice->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


	ui.tableWidget_addEcg->clear();
	ui.tableWidget_addEcg->setColumnCount(6);
	ui.tableWidget_addEcg->setRowCount(14);
	ui.tableWidget_addEcg->setHorizontalHeaderLabels(header);
	ui.tableWidget_addEcg->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_addEcg->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidget_addEcg->setAlternatingRowColors(true);
	ui.tableWidget_addEcg->setStyleSheet("alternate-background-color:#FFFAF0;background:#B4EEB4;gridline-color:white");
	ui.tableWidget_addEcg->verticalHeader()->setHidden(true);
	ui.tableWidget_addEcg->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui.spinBox_addDevice->setStyleSheet("QSpinBox{border: 0px solid #4182C3;border-width: 1px;}");
	ui.spinBox_addEcg->setStyleSheet("QSpinBox{border: 0px solid #4182C3;border-width: 1px;}");

	//第四页 评估
	ui.label_4_title->setStyleSheet(QString("color: %1").arg(color1));

	QStringList qss1;//选择
	qss1.append(QString(("QComboBox{"          //选择框  
		" border: 2px solid %1;;"
		" border-radius: 5px;"
		"padding: 1px 2px 1px 2px;"
		" min-width: 4em; "
	//	"min-height: 40px;"
		"}"
		"QComboBox QAbstractItemView::item {min-height: 25px;}" //下拉选项高度
		"QComboBox::down-arrow{border-image:url(./Resources/arrow_down_gray.png);}" //下拉箭头
		"QComboBox::drop-down {"
		"subcontrol-origin: padding;"
		" subcontrol-position: top right;"
		" width: 20px;"
		" border-left-width: 1px;"
		"border-left-color: darkgray;"
		"border-left-style: solid;"
		"border-top-right-radius: 3px;"
		" border-bottom-right-radius: 3px;"
	//	" }"
		" }"
		"QComboBox:focus{border: 2px solid #996666;}"
		)).arg("#555555"));
	ui.comboBox_video1->setView(new QListView());
	ui.comboBox_video1->setStyleSheet(qss1.join(""));
	ui.comboBox_video2->setView(new QListView());
	ui.comboBox_video2->setStyleSheet(qss1.join(""));

	ui.pushButton_begin->setStyleSheet(qssbtn.join(""));

	ui.listWidget_test_staff->setStyleSheet("QListWidget{border-radius: 5px;border: 2px solid #999999; padding:5px }"
		"QScrollBar{ width : 0; height:0; }"
	);

	ui.label_4_left->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_video1->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1; padding:2px;}").arg("#999999"));
	ui.label_video2->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1; padding:2px;}").arg("#999999"));

	ui.listWidget_xinlv->setStyleSheet("QListWidget{border-radius: 5px;border: 2px solid #999999; padding:2px }"
		"QScrollBar{ width : 0; height:0; }"
	//	"QListWidget::Item:hover{background:transparent; }"
	//	"QListWidget::item:selected{background:transparent; }"
	//	"QListWidget::item:selected:!active{border-width:0px; background:transparent; }"
	);

	

	//底部
	ui.widget_bottom->setStyleSheet("background-color:#EEF1F0");
}


//设置导航栏字体颜色背景
void T_e_s::setItemColor(int index)
{
	for (int i = 0; i < 5; i++) {
		QListWidgetItem* item = ui.listWidget_enter->item(i);
		if (i == index) {
			item->setTextColor(QColor(30, 144, 255));
		}
		else
		{
			item->setTextColor(QColor(0, 0, 0));
		}
	}

}

//界面拖动
//void T_e_s::mousePressEvent(QMouseEvent *event)
//{
//	if (event->button() == Qt::LeftButton) {
//		m_Drag = true;
//		m_DragPosition = event->globalPos() - this->pos();
//		event->accept();
//	}
//}
//
//void T_e_s::mouseMoveEvent(QMouseEvent *event)
//{
//	if (m_Drag && (event->buttons() && Qt::LeftButton)) {
//		move(event->globalPos() - m_DragPosition);
//		event->accept();
//	}
//}
//
//void T_e_s::mouseReleaseEvent(QMouseEvent *event)
//{
//	m_Drag = false;
//}

//边框阴影
void T_e_s::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
	QColor tem;
	tem.setRgb(47, 47, 47);
	painter.setPen(Qt::transparent);
	QRect rect = ui.widget->rect();
	rect.setWidth(rect.width() - 1);
	rect.setHeight(rect.height() - 1);
	painter.drawRoundedRect(rect, 10, 10);//绘制圆角
										  //绘制阴影
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(45, 45, 45)));
	QColor color(0, 0, 0, 50);
	for (int i = 0; i<10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(150 - sqrt(i) * 50);
		painter.setPen(color);
		painter.drawPath(path);
	}
	QWidget::paintEvent(event);
}





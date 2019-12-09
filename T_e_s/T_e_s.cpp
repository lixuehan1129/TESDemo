#include "T_e_s.h"
#include "QMessageBox"   //��������
#include "QGraphicsOpacityEffect"
#include "qpainter.h"
#include <QTime>
#include <QMouseEvent>
#include <qdebug.h>
//#include <vld.h>


#pragma execution_character_set("utf-8") 

/*
  from UI��ʦ ���Ӻ�
*/
class CustomTabStyle : public QProxyStyle  //ʹ�� QProxyStyle�޸Ŀؼ�Ĭ��ϵͳ��ʽ�� ���ѡ����
{
public:
	QSize sizeFromContents(ContentsType type, const QStyleOption *option,
		const QSize &size, const QWidget *widget) const
	{
		QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
		if (type == QStyle::CT_TabBarTab) {
			s.transpose();
			s.rwidth() = 140; // ����ÿ��tabBar��item�Ĵ�С
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

	//����������


	//�Ҳఴť
	


	//�м书�ܽ��� 


	//��һҳ��ť


	//�ڶ�ҳ
	//������Ա��������
	addListPerson();
	addListPerson();

	//����ҳ
	initDeviceData();

	//����ҳ
	//��ȡ��Ƶ

	//���������Ƶ�ļ����ļ���
	std::string prefix = "./VideoStore/";
	if (_access(prefix.c_str(), 0) == -1)	//����ļ��в�����
		_mkdir(prefix.c_str());				//�򴴽�
	
	EcgSet(0);
	EcgSet(1);


	//�ײ�
	//��ʾ����ʱ��
	QDateTime dateTime(QDateTime::currentDateTime());
	QString qStr = dateTime.toString("yyyy��MM��dd�� hh:mm:ss dddd");
	ui.label_detail_time->setText(qStr);
	myTimer = new QTimer(this);
	myTimer->start(1000);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(GetDateTime()));
	
}

//���ٿ�ʼ��ťʱ��
void T_e_s::on_pushButton_phy_clicked()
{
	setItemColor(3);
	ui.stackedWidget->setCurrentIndex(3);	
}
void T_e_s::on_pushButton_res_clicked()
{
	//setItemColor(3);
	//ui.stackedWidget->setCurrentIndex(3);
	QMessageBox::about(NULL, "����", "����¹�Ӧ����������");
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

//����û�
void T_e_s::on_pushButton_reg_clicked()
{
	PersonEvent();
}

//����û�
void T_e_s::on_pushButton_add_clicked()
{
	PersonEvent();
}


//ϵͳ���ã���תҳ��six
void T_e_s::on_pushButton_set_clicked()
{
	ui.stackedWidget->setCurrentIndex(5);
}

//ע���Ա
void T_e_s::PersonEvent()
{
	AddPerson* addPerson = new AddPerson;
	addPerson->setWindowModality(Qt::ApplicationModal);
	addPerson->setWindowTitle(QObject::tr("�����豸��Ϣ"));
	addPerson->setWindowFlags(Qt::WindowStaysOnTopHint);

	addPerson->show();

}

//����ҳ

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

	//����ҳ,����combox
	initCombo();
}

void T_e_s::on_pushButton_addDevice_clicked() {
	AddCamera* add = new AddCamera;
	add->setWindowModality(Qt::ApplicationModal);
	add->setWindowTitle(QObject::tr("�����豸��Ϣ"));
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

//����ҳ����ʼ
void T_e_s::on_pushButton_begin_clicked()
{
	ui.pushButton_begin->setEnabled(false);
	if (ui.pushButton_begin->text() == "��ʼ")
	{
		ui.pushButton_begin->setText("ֹͣ");
		//ui.pushButton_begin->set
		buttonChange(2);

		ui.comboBox_video1->setEnabled(false);
		ui.comboBox_video2->setEnabled(false);

		videoWriteOpen = true;
		
		//�ļ���
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
		ui.pushButton_begin->setText("��ʼ");
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


//����ҳ����
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
		//û������ͷ
		ui.label_video1->setText("��û�������豸");
		ui.label_video2->setText("��û�������豸");
		break;
	}
	case 1:
	{
		//һ������ͷ
		ui.comboBox_video1->setCurrentIndex(0);
		ui.comboBox_video2->setItemData(firstDevice, v, Qt::UserRole - 1);

		
		//m_CamDriver[1].InitHKNetSDK();//
		//m_CamDriver[1].SetScaleFactor(0.5f);
		m_CamDriver[0].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
		m_CamDriver[1].InitCamera(devices[firstDevice].cameraIp.toLatin1().data(), devices[firstDevice].cameraUser.toLatin1().data(), devices[firstDevice].cameraPw.toLatin1().data());
	
		connect(HKtimer, SIGNAL(timeout()), this, SLOT(getFrame1()));

		ui.label_video2->setText("��û�������豸");
		break;
	}
	default:
	{
		//2������������ͷ
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
		//û������ͷ������һ��
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

		ui.label_video2->setText("��û�������豸");
		break;
	}
	case 2:
	{
		//��һ������ͷ��������һ��
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

//����ҳ������ѡ��
void T_e_s::on_comboBox_video1_currentIndexChanged(int index)
{
	if (comboxOpen)
	{
		QVariant v1(0);//����ѡ��
		QVariant v2(1 | 32);//��ѡ��
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
		QVariant v1(0);//����ѡ��
		QVariant v2(1 | 32);//��ѡ��
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


//��ȡ��Ƶ
//�߳�
void T_e_s::getFrame1()
{
	if (m_CamDriver[0].GetCamMat(video[0], NULL, 1.0f)) {
		if (video[0].empty())
		{
			ui.label_video1->setText("��û�������豸");
		}
		else
		{
			//¼��
			if (videoWriteOpen)
			{
				outputVideo[0].write(video[0]);
			}
			image = m_CamDriver[0].cvMat2QImage(video[0]);
			if (image.isNull())
			{
				ui.label_video1->setText("��û�������豸");
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
			ui.label_video2->setText("��û�������豸");
		}
		else
		{
			//¼��
			if (videoWriteOpen)
			{
				outputVideo[1].write(video[1]);
			}
			image = m_CamDriver[1].cvMat2QImage(video[1]);
			if (image.isNull())
			{
				ui.label_video2->setText("��û�������豸");
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

//��ȡ����,��ʼ������û��ʵ������
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
	personBodyBean->personName = "��ѧ��";
	personBodyBean->personSex = "��";
	personBodyBean->personAge = "18";
	personBodyBean->personWeight = "65Kg";
	personBodyBean->personHeight = "170cm";
	personBodyBean->personStatus = "ѵ���У�������Ϊʦ��ÿһ��ѵ����Ŀ���ڰ೤�Ĵ�����ѡһ����Խ���������Ա����ָ��ѵ����ȫ����Ա���ﲻ�¿ࡢ�����۵����磬�˷������ࡢѵ��ʱ���ٵ����ѡ�";
	personBody->setData(personBodyBean);

	QListWidgetItem *newItem = new QListWidgetItem(ui.listWidget_personBody);
	newItem->setSizeHint(personBody->size());
	//newItem->setText("dfd");
	ui.listWidget_personBody->addItem(newItem);

	ui.listWidget_personBody->setItemWidget(newItem,personBody);

}

//��С��
void T_e_s::on_pushButton_min_clicked()
{
	this->showMinimized();
}

//�ر�
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
	QString qStr = dateTime.toString("yyyy��MM��dd�� hh:mm:ss  dddd");
	ui.label_detail_time->setText(qStr);
}


//������ѡ�� ��תҳ��
void T_e_s::on_listWidget_enter_clicked()
{
	int currenRow = ui.listWidget_enter->currentRow();//��ǰ����ѡ��ListWidget�ؼ����кţ��ڼ��У�
													  //ui.listWidget_enter->item(currenRow)->setTextColor(QColor(30,144,255));
	setItemColor(currenRow);
	ui.stackedWidget->setCurrentIndex(currenRow);


}


void T_e_s::buttonChange(int i) 
{
	QStringList qssbtn;//��ť
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
//���ø�ʽ
void T_e_s::styleSheet()
{
	//ȥ�����ڱ߿�
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	//����͸��
	this->setAttribute(Qt::WA_TranslucentBackground);

	ui.widget->setStyleSheet("background-color:transparent");



	//����������
	ui.widget_title->setStyleSheet("background-color:#EEF1F0");

	QListWidget *listWidget_enter = ui.listWidget_enter;
	listWidget_enter->setStyleSheet("background-color:transparent");
	listWidget_enter->setCurrentRow(0); //���õ�ǰѡ����Ĭ��Ϊ 0
	for (int i = 0; i < 5; i++) {
		QListWidgetItem* item = ui.listWidget_enter->item(i);
		item->setFlags(Qt::NoItemFlags);
		item->setFlags(Qt::ItemIsEnabled);
	}
	//Ĭ�ϵ�һҳ
	setItemColor(0);
	ui.stackedWidget->setCurrentIndex(0);


	//�Ҳఴť
	ui.pushButton_add->setToolTip(tr("ע���³�Ա"));
	ui.pushButton_add->setStyleSheet("QPushButton{border-image: url(./Resources/ic_add_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_add_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_add_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_set->setToolTip(tr("����"));
	ui.pushButton_set->setStyleSheet("QPushButton{border-image: url(./Resources/ic_set_b.png);width:25;height:25;background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_set_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_set_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_min->setToolTip(tr("��С��"));
	ui.pushButton_min->setStyleSheet("QPushButton{border-image: url(./Resources/ic_min_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_min_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_min_b.png);background-repeat: no-repeat;background-position:center;border:none;}");
	ui.pushButton_close->setToolTip(tr("�˳�"));
	ui.pushButton_close->setStyleSheet("QPushButton{border-image: url(./Resources/ic_close_b.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:hover{border-image: url(./Resources/ic_close_bl.png);background-repeat: no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image: url(./Resources/ic_close_b.png);background-repeat: no-repeat;background-position:center;border:none;}");



	//�м书�ܽ��� 
	//ui.stackedWidget->setStyleSheet("background-color:#FFFFFF"); //��ɫ

	//��һҳ��ť����
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


	//�ڶ�ҳ
	ui.tabWidget->setTabPosition(QTabWidget::West);
	ui.tabWidget->tabBar()->setStyle(new CustomTabStyle);
	ui.tabWidget->setStyleSheet("QTabWidget::tab-bar{top:0px; }"
		"QTabWidget::pane{ \
            border-left: 1px solid #eeeeee;\
        }");
	ui.tabWidget->setCurrentIndex(0);

	//��Ա��������
	ui.listWidget_personBody->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
		"QListWidget::Item:hover{background:transparent; }"
		"QListWidget::item:selected{background:transparent; }"
		"QListWidget::item:selected:!active{border-width:0px; background:transparent; }"
		"QScrollBar{ width : 0; height : 0; }"
	);

	//����ҳ
	QStringList qssbtn;//��ť
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
	header << "���" << tr("�豸��") << "IP��ַ" << "�˿ں�" << "�û���" << "����";
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

	//����ҳ ����
	ui.label_4_title->setStyleSheet(QString("color: %1").arg(color1));

	QStringList qss1;//ѡ��
	qss1.append(QString(("QComboBox{"          //ѡ���  
		" border: 2px solid %1;;"
		" border-radius: 5px;"
		"padding: 1px 2px 1px 2px;"
		" min-width: 4em; "
	//	"min-height: 40px;"
		"}"
		"QComboBox QAbstractItemView::item {min-height: 25px;}" //����ѡ��߶�
		"QComboBox::down-arrow{border-image:url(./Resources/arrow_down_gray.png);}" //������ͷ
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

	

	//�ײ�
	ui.widget_bottom->setStyleSheet("background-color:#EEF1F0");
}


//���õ�����������ɫ����
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

//�����϶�
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

//�߿���Ӱ
void T_e_s::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);  // �����;
	QColor tem;
	tem.setRgb(47, 47, 47);
	painter.setPen(Qt::transparent);
	QRect rect = ui.widget->rect();
	rect.setWidth(rect.width() - 1);
	rect.setHeight(rect.height() - 1);
	painter.drawRoundedRect(rect, 10, 10);//����Բ��
										  //������Ӱ
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





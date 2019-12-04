#include <AddCamera.h>

AddCamera::AddCamera(QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	styleSheet();
	

}

AddCamera::~AddCamera()
{

}


void AddCamera::on_pushButton_sure_clicked()
{
	device.cameraName = ui.lineEdit_name->text();
	device.cameraIp = ui.lineEdit_ip->text();
	device.cameraPort = ui.lineEdit_port->text();
	device.cameraUser = ui.lineEdit_user->text();
	device.cameraPw = ui.lineEdit_pw->text();

	//qDebug() << device.cameraName << device.cameraIp << device.cameraPort << device.cameraUser << device.cameraPw;

	if (device.cameraName.isEmpty() || device.cameraIp.isEmpty() || device.cameraPort.isEmpty() || device.cameraUser.isEmpty() || device.cameraPw.isEmpty())
	{
		QMessageBox::warning(this, tr("提示"), QString(tr("存在未输入信息")), QMessageBox::Yes);
	}
	else
	{
		if (!isIPAddressValid(device.cameraIp.toLatin1().data()))
		{
			QMessageBox::warning(this, tr("提示"), QString(tr("IP地址错误")), QMessageBox::Yes);
		}
		else
		{
			int Id = camDriver.RegistDevice(device.cameraIp.toLatin1().data(),device.cameraUser.toLatin1().data(),device.cameraPw.toLatin1().data(),device.cameraPort.toInt());
			if (Id != -1)
			{
			//	dBHelper.createConnection();
				if (dBHelper.insertDevice(device))
				{
					emit SendData(device);
					this->close();
				}
				else
				{
					QMessageBox::warning(this, tr("提示"), QString(tr("设备已存在")), QMessageBox::Yes);
				}
			}
			else
			{
				QMessageBox::warning(this, tr("提示"), QString(tr("设备连接失败，请检查内容是否正确")), QMessageBox::Yes);
			}
			
		}

	}

}

void AddCamera::on_pushButton_cancel_clicked()
{
	this->close();
}




bool AddCamera::isIPAddressValid(const char* pszIPAddr)
{
	if (!pszIPAddr) return false; //若pszIPAddr为空  
	char IP1[100], cIP[4];
	int len = strlen(pszIPAddr);
	int i = 0, j = len - 1;
	int k, m = 0, n = 0, num = 0;
	//去除首尾空格(取出从i-1到j+1之间的字符):  
	while (pszIPAddr[i++] == ' ');
	while (pszIPAddr[j--] == ' ');

	for (k = i - 1; k <= j + 1; k++)
	{
		IP1[m++] = *(pszIPAddr + k);
	}
	IP1[m] = '\0';

	char *p = IP1;

	while (*p != '\0')
	{
		if (*p == ' ' || *p<'0' || *p>'9') return false;
		cIP[n++] = *p; //保存每个子段的第一个字符，用于之后判断该子段是否为0开头  

		int sum = 0;  //sum为每一子段的数值，应在0到255之间  
		while (*p != '.'&&*p != '\0')
		{
			if (*p == ' ' || *p<'0' || *p>'9') return false;
			sum = sum * 10 + *p - 48;  //每一子段字符串转化为整数  
			p++;
		}
		if (*p == '.') {
			if ((*(p - 1) >= '0'&&*(p - 1) <= '9') && (*(p + 1) >= '0'&&*(p + 1) <= '9'))//判断"."前后是否有数字，若无，则为无效IP，如“1.1.127.”  
				num++;  //记录“.”出现的次数，不能大于3  
			else
				return false;
		};
		if ((sum > 255) || (sum > 0 && cIP[0] == '0') || num>3) return false;//若子段的值>255或为0开头的非0子段或“.”的数目>3，则为无效IP  

		if (*p != '\0') p++;
		n = 0;
	}
	if (num != 3) return false;
	return true;
}



void AddCamera::styleSheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);

	QStringList qss;//文本框显示
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));
	ui.lineEdit_name->setStyleSheet(qss.join(""));
	ui.lineEdit_name->setText("网络摄像机");
	ui.lineEdit_ip->setStyleSheet(qss.join(""));
	ui.lineEdit_ip->setText("192.168.1.1");
	ui.lineEdit_user->setStyleSheet(qss.join(""));
	ui.lineEdit_pw->setStyleSheet(qss.join(""));
	ui.lineEdit_pw->setEchoMode(QLineEdit::Password);
	ui.lineEdit_port->setStyleSheet(qss.join(""));
	ui.lineEdit_port->setText("8000");
	ui.lineEdit_port->setValidator(new QIntValidator(0, 100000, this));

	QStringList qssbtn;//按钮
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg("#4182C3").arg("#17abe3").arg("#2a79bd"));
	QFont font1;
	font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font1.setPointSize(10);
	font1.setBold(false);
	font1.setWeight(50);
	ui.pushButton_sure->setFont(font1);
	ui.pushButton_sure->setStyleSheet(qssbtn.join(""));
	ui.pushButton_cancel->setFont(font1);
	ui.pushButton_cancel->setStyleSheet(qssbtn.join(""));


}
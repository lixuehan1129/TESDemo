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

}

void AddCamera::on_pushButton_cancel_clicked()
{

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
	ui.lineEdit_name->setPlaceholderText("网络摄像机");
	ui.lineEdit_ip->setStyleSheet(qss.join(""));
	ui.lineEdit_ip->setPlaceholderText("192.168.1.1");
	ui.lineEdit_user->setStyleSheet(qss.join(""));
	ui.lineEdit_pw->setStyleSheet(qss.join(""));
	ui.lineEdit_pw->setEchoMode(QLineEdit::Password);
	ui.lineEdit_port->setStyleSheet(qss.join(""));
	ui.lineEdit_port->setPlaceholderText("8000");

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
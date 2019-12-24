#include <AddPerson.h>

AddPerson::AddPerson(QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	styleSheet();

	int count = dBHelper.getPersonCount();
	if (count > -1)
	{
		int newID = 100001 + count;
		ui.lineEdit_personId->setText(QString::number(newID));
		ui.lineEdit_personId->setReadOnly(true);
	}
	else
	{
		ui.lineEdit_personId->setText("��������");
		ui.lineEdit_personId->setReadOnly(true);
	}

	
}

AddPerson::~AddPerson()
{

}

void AddPerson::on_radioButton_man_toggled()
{
	if (ui.radioButton_man->isChecked())
	{
		personSex = 0;
		//qDebug() << personSex;
	}
	else
	{
		personSex = 1;
		//qDebug() << personSex;
	}

}


void AddPerson::on_pushButton_sure_clicked()
{
	person.personId = ui.lineEdit_personId->text();
	person.personName = ui.lineEdit_personName->text();
	person.personAge = ui.lineEdit_personAge->text().toInt();
	person.personSex = personSex;
	person.personWeight = ui.lineEdit_personWeight->text().toInt();
	person.personHeight = ui.lineEdit_personHeight->text().toInt();
	person.personBand = ui.comboBox_ecg->currentText();
	person.personBand = "�����豸";
	person.personPic = "";

	//qDebug() << person.personAge;
	if (person.personName.isEmpty() || person.personAge == 0 || person.personWeight == 0 || person.personHeight == 0)
	{
		QMessageBox::warning(this, tr("��ʾ"), QString(tr("����δ������Ϣ")), QMessageBox::Yes);
	}
	else
	{
		if (dBHelper.insertPerson(person))
		{
			this->close();
			emit SendData(person);
		}
		else
		{
			QMessageBox::warning(this, tr("��ʾ"), QString(tr("�����Ѵ���")), QMessageBox::Yes);
		}
	}
}

void AddPerson::on_pushButton_cancel_clicked()
{
	this->close();
}

void AddPerson::styleSheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);


	QStringList qss;//�ı�����ʾ
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));
	ui.lineEdit_personId->setStyleSheet(qss.join(""));
	ui.lineEdit_personName->setStyleSheet(qss.join(""));
	ui.lineEdit_personAge->setStyleSheet(qss.join(""));
	ui.lineEdit_personAge->setValidator(new QIntValidator(10, 80, this));
	ui.lineEdit_personWeight->setStyleSheet(qss.join(""));
	ui.lineEdit_personWeight->setValidator(new QIntValidator(40, 200, this));
	ui.lineEdit_personHeight->setStyleSheet(qss.join(""));
	ui.lineEdit_personHeight->setValidator(new QIntValidator(100, 200, this));
	//ui.lineEdit_port->setValidator(new QIntValidator(0, 100000, this));

	QStringList qssbtn;//��ť
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
	ui.comboBox_ecg->setView(new QListView());
	ui.comboBox_ecg->setStyleSheet(qss1.join(""));

	ui.radioButton_man->setChecked(true);
}
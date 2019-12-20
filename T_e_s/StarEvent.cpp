#include "StarEvent.h"

StarEvent::StarEvent(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	initStyle();
	initData();
}

StarEvent::~StarEvent()
{
}

void StarEvent::on_pushButton_sure_clicked()
{
	QString str;
	for (int i = 0; i < strL.size(); i++)
	{
		if (checkBox[i]->isChecked())
		{
			str = str + checkBox[i]->text() + "\n";
		}
	}
	if (str.isEmpty())
	{
		QMessageBox::warning(this, tr("提示"), QString(tr("未选中")), QMessageBox::tr("确定"));
	}
	else
	{
		emit returnCheck(str);
		this->close();
	}
	
}

void StarEvent::on_pushButton_cancel_clicked()
{
	this->close();
}

void StarEvent::on_pushButton_add_clicked()
{
	AddStar* addStar = new AddStar(this);
	addStar->setWindowModality(Qt::ApplicationModal);
	addStar->setWindowTitle("添加新指标");
	connect(addStar, SIGNAL(returnData(QString)), this, SLOT(getData(QString)));
	if (addStar->exec() == QDialog::Accepted) {
	}
	delete addStar;
}

void StarEvent::getData(QString str)
{
	

	int size = strL.size();
	if (size < MAXSIZE)
	{

		QFont font;
		font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font.setPointSize(10);

		strL.append(str);
		checkBox[size] = new QCheckBox(this);
		checkBox[size]->setText(str);
		checkBox[size]->setFont(font);

		ui.gridLayout->addWidget(checkBox[size], size / 3, size % 3, Qt::AlignLeft | Qt::AlignVCenter);
	}

}

void StarEvent::initData()
{
	strL << "动作不达标" << "位置错误" << "人员位置错误" << "不符指标" << "时间不匹配" << "其他错误" << "其他";

	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(10);
	for (int i = 0; i < strL.size(); i++)
	{
		checkBox[i] = new QCheckBox(this);
		checkBox[i]->setText(strL.at(i));
		checkBox[i]->setFont(font);
		//checkBox[i]->
		ui.gridLayout->addWidget(checkBox[i], i / 3, i % 3, Qt::AlignLeft | Qt::AlignVCenter);
	}
}



void StarEvent::initStyle()
{
	QStringList qssbtn;//按钮
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg("#4182C3").arg("#17abe3").arg("#2a79bd"));
	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(10);
	font.setBold(false);
	font.setWeight(50);
	ui.pushButton_sure->setFont(font);
	ui.pushButton_sure->setStyleSheet(qssbtn.join(""));
	ui.pushButton_cancel->setFont(font);
	ui.pushButton_cancel->setStyleSheet(qssbtn.join(""));
	ui.pushButton_add->setFont(font);
	ui.pushButton_add->setStyleSheet(qssbtn.join(""));
}
#include <AddStar.h>

AddStar::AddStar(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	initStyle();

}

AddStar::~AddStar()
{
}

void AddStar::on_pushButton_ok_clicked()
{
	if (ui.lineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, tr("提示"), QString(tr("未添加")), QMessageBox::tr("确定"));
	}
	else
	{
		emit returnData(ui.lineEdit->text());
		this->close();
	}
}

void AddStar::initStyle()
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

	ui.pushButton_ok->setFont(font);
	ui.pushButton_ok->setStyleSheet(qssbtn.join(""));
}
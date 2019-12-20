#include "Replay.h"

Replay::Replay(QWidget *parent) :
	QWidget(parent)
{
	ui.setupUi(this);
	stylesheet();
	setAttribute(Qt::WA_DeleteOnClose);
	pool.setMaxThreadCount(3);
}

Replay::~Replay()
{
	player->Stop();
	player->Release();
	pool.cancel(player);

	ecgHelper->Release();
	pool.cancel(ecgHelper);
}


void Replay::replayGet(int pro, int x, int y)
{

	qDebug() << pro << x << y;
	ui.label_score->setText(QString::number(y));

	QFile file1("./VideoStore/20191212140935_01.avi");
	QFile file2("./VideoStore/20191212140935_02.avi");
	if (!file1.open(QIODevice::ReadOnly) || !file2.open(QIODevice::ReadOnly))
	{
		return;
	}
	else {
		if (player == NULL) {
			//当没有视频播放时
			player = new VideoPlayer(ui.slider, ui.label_video1, ui.label_video2, ui.label_video3, ui.label_pos, ui.label_total, ui.pushButton_on);
			ECGx = player->play("./VideoStore/20191212140935_01.avi", "./VideoStore/20191212140935_02.avi", "./VideoStore/20191212140935_02.avi");
			//开启线程
		//	QThreadPool::globalInstance()->start(player);
			pool.start(player);
			if (ECGx)
			{
			//	qDebug() << ECGx;
				ecgHelper = new ECGHelper(ui.chartView, ECGx / 8);
				pool.start(ecgHelper);
			}
			setButton(ECGx);
		}
	}
}

void Replay::setButton(int range)
{
	buttonGroup = new QButtonGroup(this);
	for (int i = 0; i < strPosition.size(); i++)
	{
		QPushButton* button = new QPushButton(this);
		button->resize(25,25);
		float posX = (float)strPosition.at(i) / range * 990;
		int posXF = (int)posX;
		button->move(18 + posX, 650);
		button->setCheckable(true);
		button->setStyleSheet("QPushButton{border-image:url(./Resources/star1.png);background-repeat: no-repeat;background-position:center;border:none; }"
			"QPushButton:hover{border-image:url(./Resources/star2.png);background-repeat:no-repeat;background-position:center;border:none;}"
			"QPushButton:pressed{border-image:url(./Resources/star1.png);background-repeat:no-repeat;background-position:center;border:none;}");
		buttonGroup->addButton(button, i);
	}
	connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroup_clicked(int)));
	
}

void Replay::buttonGroup_clicked(int i)
{
	
	ui.slider->sliderMoved(strPosition.at(i));
//	player->Pase(strPosition.at(i));
	ui.label_remark->setText(strList.at(i));
	
}

//开始 暂停
void Replay::on_pushButton_on_clicked()
{
	player->PaseOrStart();
	ecgHelper->PaseOrStart();
}

void Replay::on_slider_sliderMoved(int position)
{

	player->Set_postion(position);
	ui.slider->setValue(position);
	/*ecgHelper->setPoint(ui.slider->value());

	if (strPosition.contains(position))
	{
		ui.label_remark->setText(strList.at(strPosition.indexOf(position)));
	}*/
}


void Replay::on_slider_valueChanged(int position)
{

	ecgHelper->setPoint(ui.slider->value());
	if (strPosition.contains(position))
	{
		ui.label_remark->setText(strList.at(strPosition.indexOf(position)));
	}
}

//标记
void Replay::on_pushButton_star_clicked()
{
	player->Pase();
	StarEvent* starEvent = new StarEvent(this);
	starEvent->setWindowModality(Qt::ApplicationModal);
	starEvent->setWindowTitle("标记");
	//starEvent->exec();

	connect(starEvent, SIGNAL(returnCheck(QString)), this, SLOT(getCheck(QString)));
	//ui.slider->value();
	if(starEvent->exec() == QDialog::Accepted) {
	}
	delete starEvent;
}

void Replay::getCheck(QString str)
{
	
	strPosition.append(ui.slider->value());
	strList.append(str);

	//setButton(ECGx);
	
	QPushButton* button = new QPushButton(this);
	button->resize(25, 25);
	float posX = (float)ui.slider->value() / ECGx * 990;
	int posXF = (int)posX;
	qDebug() << posXF;
	button->move(18 + posX, 650);
	button->setCheckable(true);
	button->setStyleSheet("QPushButton{border-image:url(./Resources/star1.png);background-repeat: no-repeat;background-position:center;border:none; }"
		"QPushButton:hover{border-image:url(./Resources/star2.png);background-repeat:no-repeat;background-position:center;border:none;}"
		"QPushButton:pressed{border-image:url(./Resources/star1.png);background-repeat:no-repeat;background-position:center;border:none;}");
	buttonGroup->addButton(button, strPosition.size() - 1);
	button->show();

	ui.label_remark->setText(str);
}


void Replay::stylesheet()
{
	ui.label_video1->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1; padding:2px;}").arg("#999999"));
	ui.label_video2->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1; padding:2px;}").arg("#999999"));
	ui.label_video3->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1; padding:2px;}").arg("#999999"));

	QStringList qssbtn;//按钮
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg("#4182C3").arg("#17abe3").arg("#2a79bd"));
	ui.pushButton_on->setStyleSheet(qssbtn.join(""));
	ui.pushButton_star->setStyleSheet(qssbtn.join(""));

	//int nMin = 0;
	//int nMax = 500;
	int nSingleStep = 16;
	//ui.slider->setMinimum(nMin);  // 最小值
	//ui.slider->setMaximum(nMax);  // 最大值
	ui.slider->setSingleStep(nSingleStep);  // 步长

	strPosition << 115 << 600 << 1220 << 1455 << 2030;
	strList << "1.位置不达标\n2.动作不达标" << "1.位置错误\n2.动作不达标" << "1.位置不达标\n2.动作错误" << "1.未按照指定要求\n2.动作不达标" << "1.位置不达标\n2.出错";


}

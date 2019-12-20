#include "videoplayer.h"

//初始化静态变量
//bool VideoPlayer::Is_Video_play = false;
VideoPlayer::VideoPlayer(QSlider *slider, QLabel *label_video1, QLabel *label_video2, QLabel *label_video3, QLabel *label_pos, QLabel *label_total, QPushButton *pushButton)
{
	//构造函数
	this->slider = slider;
	this->label_video1 = label_video1;
	this->label_video2 = label_video2;
	this->label_video3 = label_video3;
	this->label_pos = label_pos;
	this->label_total = label_total;
	this->pushButton = pushButton;

}


void VideoPlayer::show_img(Mat src1, QLabel *label1, Mat src2, QLabel *label2, Mat src3, QLabel *label3)
{

	//    在label上显示opencv图片
	cv::cvtColor(src1, src1, CV_BGR2RGB);
	QImage img1 = QImage((const unsigned char*)(src1.data), src1.cols, src1.rows,
		src1.cols*src1.channels(),
		QImage::Format_RGB888).scaled(label1->width(), label1->height());

	label1->clear();
	label1->setPixmap(QPixmap::fromImage(img1));

	cv::cvtColor(src2, src2, CV_BGR2RGB);
	QImage img2 = QImage((const unsigned char*)(src2.data), src2.cols, src2.rows,
		src2.cols*src2.channels(),
		QImage::Format_RGB888).scaled(label2->width(), label2->height());

	label2->clear();
	label2->setPixmap(QPixmap::fromImage(img2));

	cv::cvtColor(src3, src3, CV_BGR2RGB);
	QImage img3 = QImage((const unsigned char*)(src3.data), src3.cols, src3.rows,
		src3.cols*src3.channels(),
		QImage::Format_RGB888).scaled(label3->width(), label3->height());

	label3->clear();
	label3->setPixmap(QPixmap::fromImage(img3));
	//ui->processPushButton->setEnabled(true);

}
int VideoPlayer::play(QString path1, QString path2, QString path3) {
	Stop_Play = false;
	capture1.open(path1.toStdString());
	capture2.open(path2.toStdString());
	capture3.open(path3.toStdString());

	slider->setRange(0, capture1.get(7));
	
	this->label_total->setText(returnTime(capture1.get(7)));
	
	//      Is_Video_play==true;
	//      Stop_Play=false;
	if (capture1.read(frame1) && capture2.read(frame2) && capture3.read(frame3))
	{
		show_img(frame1, label_video1, frame2, label_video2, frame3, label_video3);
	}

	return capture1.get(7);
}
void VideoPlayer::Stop() {
	//停止播放
	Stop_Play = true;
	Is_Pase = true;
}

void VideoPlayer::Start() {
	//打开播放锁
	Stop_Play = false;
}

void VideoPlayer::PaseOrStart() {
	QStringList qssbtn;//按钮
	QString str = "开始";
	//暂停
	if (Is_Pase == true)
	{		
		
		qssbtn.append(QString(
			"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
			"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
		).arg("#CD2626").arg("#EE2C2C").arg("#CD2626"));

		str = "暂停";
		Is_Pase = false;
	}
	else {
		qssbtn.append(QString(
			"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
			"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
			"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
		).arg("#4182C3").arg("#17abe3").arg("#2a79bd"));

		str = "开始";

		Is_Pase = true;
	}

	pushButton->setText(str);
	pushButton->setStyleSheet(qssbtn.join(""));

}

void VideoPlayer::Pase() {
	Is_Pase = true;

	QStringList qssbtn;//按钮
	QString str = "开始";
	//暂停
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg("#4182C3").arg("#17abe3").arg("#2a79bd"));
	pushButton->setText(str);
	pushButton->setStyleSheet(qssbtn.join(""));

}

void VideoPlayer::Release() {
	//停止播放
	Is_Video_play = false;
}

double VideoPlayer::get_current_pos() {
	return (capture1.get(0));
}

void VideoPlayer::Set_postion(long po) {
	//根据frame进行设置位置
	this->pos = po;
}
void VideoPlayer::run() {

	//player的线程函数
	while (Is_Video_play) {
		//点击进度条响应 变化起始位置
		if (pos != -1) {
			capture1.set(1, pos);
			capture2.set(1, pos);
			capture3.set(1, pos);
			pos = -1;
			
		}
			
		//暂停响应
		if (!Is_Pase) {
			bool ret1 = capture1.read(frame1);
			bool ret2 = capture2.read(frame2);
			bool ret3 = capture3.read(frame3);
			
			if (!ret1 && !ret2 && !ret3) {
				continue;
			}
			if (Stop_Play) {
				break;
			}
			show_img(frame1, label_video1, frame2, label_video2, frame3, label_video3);

			long i = capture1.get(1);
			QMetaObject::invokeMethod(slider, "setValue", Qt::QueuedConnection, Q_ARG(int, i));
			QMetaObject::invokeMethod(label_pos, "setText", Qt::QueuedConnection, Q_ARG(QString, returnTime(i)));
			QTest::qSleep(speed);
			//_sleep(speed);
		}
	

	}
}

QString VideoPlayer::returnTime(int i)
{
	int sec = i / 16;
	int hour = sec / 3600;
	int min = (sec - (sec / 3600 * 3600)) / 60;
	int se = sec - (sec / 3600 * 3600) - (sec - (sec / 3600 * 3600)) / 60 * 60;
	QString time = QString("%1").arg(hour, 2, 10, QChar('0')) + ":" + QString("%1").arg(min, 2, 10, QChar('0')) + ":" + QString("%1").arg(se, 2, 10, QChar('0'));
	return time;
}

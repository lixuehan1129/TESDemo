#include <VideoThread.h>

VideoThread::VideoThread(QObject *parent)
	:QThread(parent)
{

}

void VideoThread::run()
{	
	timer = new QTimer();
	timer->start(60);
	connect(timer, SIGNAL(timeout()), this, SLOT(show_cam()));
	this->exec();
}

void VideoThread::show_cam()
{
	cap >> frame;
	if (frame.empty()) {
		QImage ima = QImage();
		emit return_QImage(ima);
	}
	else
	{
		cvtColor(frame, frame, CV_BGR2RGB);//opencv中的图片以BGR格式保存，Qt中是RGB，故先转换格式再将Mat转为QImage
		QImage  Qimg(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
		emit return_QImage(Qimg);
	}
	

}

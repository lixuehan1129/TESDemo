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
		cvtColor(frame, frame, CV_BGR2RGB);//opencv�е�ͼƬ��BGR��ʽ���棬Qt����RGB������ת����ʽ�ٽ�MatתΪQImage
		QImage  Qimg(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
		emit return_QImage(Qimg);
	}
	

}

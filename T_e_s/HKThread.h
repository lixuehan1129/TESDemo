#pragma once

#define THREAD_CAM_H

#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QImage>
#include <HK_camera.h>
//using namespace cv;
using namespace std;
class HKThread : public QThread
{
	Q_OBJECT
public:
	explicit HKThread(QObject *parent = 0);

	char *add;
	HKThread(char *url)
	{
		add = url;
	}

protected:
	void run();

private:
	QTimer *timer;
	HK_camera camera;
	QImage Qimge;


signals:
	void return_QImage1(QImage);//ͨ���źŽ����߳��вɼ���ͼƬ�������߳�

	public slots:
	void show_cam();
};



#pragma once

#define THREAD_CAM_H

#include <QThread>
#include <QTimer>
#include "opencv2/core/core.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>
#include <QImage>
//using namespace cv;
using namespace std;
class VideoThread : public QThread
{
	Q_OBJECT
public:
	explicit VideoThread(QObject *parent = 0);
	cv::VideoCapture cap;
	VideoThread(const char *url)
	{
		cap = cv::VideoCapture(url);
	}

protected:
	void run();

private:
	QTimer *timer;
	cv::Mat frame;
	QImage Qimg;
	

signals:
	void return_QImage(QImage);//通过信号将子线程中采集的图片传回主线程

public slots:
    void show_cam();
};



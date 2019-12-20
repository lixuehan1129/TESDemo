#pragma once

#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QThreadPool>
#include <QProgressBar>
#include <QThread>
#include <QDebug>
#include <string.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QSlider>
#include <opencv2/opencv.hpp>
#include <QLabel>
#include <QPushButton>
#include <QtTest/QtTest>

#pragma execution_character_set("utf-8") 

//#include <qtestsupport_widgets.h>
using namespace cv;

class VideoPlayer : public QRunnable
{
public:
	VideoPlayer(QSlider *slider, QLabel *label_video1, QLabel *label_video2, QLabel *label_video3, QLabel *label_pos, QLabel *label_total, QPushButton *pushButton);
	int play(QString path1, QString path2, QString path3);
	void run();
	void Stop();
	void Start();
	void Pase();
	void PaseOrStart();
	void Set_postion(long po);
	double get_current_pos();
	void Release();
	bool Is_Video_play = true;

private:
	QSlider* slider;
	QString Video_Path1;
	QString Video_Path2;
	QString Video_Path3;
	QLabel* label_video1;
	QLabel* label_video2;
	QLabel* label_video3;
	QLabel* label_pos;
	QLabel* label_total;
	QPushButton* pushButton;
	VideoCapture capture1 = NULL;
	VideoCapture capture2 = NULL;
	VideoCapture capture3 = NULL;
	void show_img(Mat src1, QLabel *label1, Mat src2, QLabel *label2, Mat src3, QLabel *label3);
	Mat frame1;
	Mat frame2;
	Mat frame3;
	bool Stop_Play = false;
	bool Is_Pase = true;
	int speed = 45;
	int pos = 1;
	QString returnTime(int sec);
};

#endif // VIDEO_PLAYER_H


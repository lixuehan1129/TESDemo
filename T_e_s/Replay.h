#pragma once

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <ui_Replay.h>
#include <QWidget>
#include <VideoPlayer.h>
#include <QFile>
#include <ECGHelper.h>
#include <StarEvent.h>

class Replay : public QWidget
{
	Q_OBJECT;
public:
	Replay(QWidget *parent = Q_NULLPTR);
	~Replay();
	VideoPlayer *player = NULL;
	ECGHelper *ecgHelper = NULL;
public slots:
     void replayGet(int pro, int x, int y);
	 void on_pushButton_on_clicked();
	 void on_pushButton_star_clicked();
	 void on_slider_sliderMoved(int position);
	 void on_slider_valueChanged(int position);
	 void buttonGroup_clicked(int i);
	 void getCheck(QString str);

	

private:
	Ui::Replay ui;

	void stylesheet();

	int ECGx;
	QThreadPool pool;

	void setButton(int range);
	QPushButton *button[15];
	QButtonGroup* buttonGroup;
	QList<int>  strPosition;
	QStringList strList;





};


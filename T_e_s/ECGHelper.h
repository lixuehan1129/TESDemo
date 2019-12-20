#pragma once

#include <QThreadPool>
#include <QThread>
#include <Helper.h>
#include <QValueAxis>
#include <qchart.h>
#include <QtTest/QtTest>
#include <QDebug>

class ECGHelper : public QRunnable
{
public:
	ECGHelper(QChartView* qChartView, int range);
	~ECGHelper();

	void run();
	void setPoint(int position);

	void PaseOrStart();
	void Release();

	bool Is_Point_play = true;


	

private:
	QChartView* qChartView;

	QChart *ecgWaveLineChart;
	QValueAxis *axisX_ECG;
	QValueAxis *axisY_ECG;
	QLineSeries *ecgSeries;
	QScatterSeries* series;
	int range;

	int originListSize;
	QStringList originList;
	int axis_x_counts = 0;

	void initEcgWaveLineChart();
	void readEcgData();

	bool Is_Pase = false;
	bool Stop_Play = false;
	int pos = 0;
};



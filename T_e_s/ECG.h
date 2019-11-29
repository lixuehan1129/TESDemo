#pragma once

#include <QtCharts>
QT_CHARTS_USE_NAMESPACE


#include <QWidget>
#include <qchart.h>
#include <ui_ECG.h>
#include <Helper.h>
#include <QValueAxis>

#pragma execution_character_set("utf-8") 

#define FIFO_BUFFER_SIZE 1200 // software buffer size (in bytes) 4s数据， 考虑buffer区域扩大为8s+区域
#define DRAW_ECG_INTERVAL 4
#define AXIS_X_MAX_COUNTS 600


class ECG : public QWidget
{
	Q_OBJECT;

public:
	ECG(QWidget *parent = Q_NULLPTR);
	~ECG();

	void initData();
	void stopShow();

signals:

private slots:
	void oneTimeOutReadFromFifoAction();
	void oneTimeOutWriteToFifoAction();

public slots:

private:
	Ui::ECG ui;

	void initEcgWaveLineChart();
	void initStyle();

	int originListSize;
	int originListIndex;
	int axis_x_counts;

	QChart *ecgWaveLineChart;
	QValueAxis *axisX_ECG;
	QValueAxis *axisY_ECG;
	QLineSeries *ecgSeries;//
	QStringList originList;

	QTimer *ecgWaveDrawTimer;
	QTimer *ecgWaveReadTimer;

	void readEcgData();

	void ecgDataFifoIn(qint16 inputData);
	qint16 ecgDataFifoOut();
	//QVector<QPointF> ecgPointBuffer;

	//******** fifo相关 ***********
	typedef struct {
		qint16  data_buf[FIFO_BUFFER_SIZE]; // FIFO buffer 16位有符号数
		quint16 i_first;                    // index of oldest data byte in buffer
		quint16 i_last;                     // index of newest data byte in buffer
		quint16 num_bytes;                  // number of bytes currently in buffer
	}sw_fifo_typedef;
	sw_fifo_typedef ecg_data_fifo = { { 0 }, 0, 0, 0 }; // declare a receive software buffer

														//------------- fifo中标志位的配置 ---------------
	quint8 fifo_not_empty_flag; // this flag is automatically set and cleared by the software buffer
	quint8 fifo_full_flag;      // this flag is automatically set and cleared by the software buffer
	quint8 fifo_ovf_flag;       // this flag is not automatically cleared by the software buffer

	QQueue <qint16> m_EcgShortQueue;

};

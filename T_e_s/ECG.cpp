#include "ECG.h"


//拿来主义
ECG::ECG(QWidget *parent) :
	QWidget(parent)
{
	ui.setupUi(this);
	initStyle();
	initEcgWaveLineChart();
	//initData();
}

ECG::~ECG()
{
	//ecgWaveReadTimer->stop();
}

void ECG::stopShow() {
	ecgWaveReadTimer->stop();
	ecgWaveDrawTimer->stop();
}

void ECG::initData()
{
	//Sleep(50);
	originListIndex = 0;
	axis_x_counts = 0;

	readEcgData();
	ecgSeries->clear();
	//提前添加完点，就不用考虑是否是第一次绘制，只用替换现有点的数据
	for (int i = 0; i < AXIS_X_MAX_COUNTS; i++)
	{
		//ecgPointBuffer.append(QPointF(i, 0));
		*ecgSeries << QPointF(i, 0);
	}

	//模拟TCP数据到来的定时器
	ecgWaveReadTimer = new QTimer(this);
	connect(ecgWaveReadTimer, SIGNAL(timeout()), this, SLOT(oneTimeOutWriteToFifoAction()));
	ecgWaveReadTimer->start(500);//500ms执行一次

								 //******绘制折线定时器***********
	ecgWaveDrawTimer = new QTimer(this);
	ecgWaveDrawTimer->setInterval(DRAW_ECG_INTERVAL);
	ecgWaveDrawTimer->setTimerType(Qt::PreciseTimer);//精确
	connect(ecgWaveDrawTimer, SIGNAL(timeout()), this, SLOT(oneTimeOutReadFromFifoAction()));
	ecgWaveDrawTimer->start();

}

//模拟500ms收到一个数据包 以后这部分就可以是TCP或者是串口接收到一次数据就加入一次缓存队列
void ECG::oneTimeOutWriteToFifoAction() {
	for (int i = originListIndex; i < (125 + originListIndex); i++)
	{
		qint16 tempInt16 = originList.at(i).toInt();
		m_EcgShortQueue.enqueue(tempInt16);
	}
	originListIndex += 125;
	//如果剩下的数据不足以支撑下一次数据读取
	if ((originListIndex + 125) >= originListSize)
	{
		ecgWaveReadTimer->stop();

	//	readEcgData();
	}
}

//********* 读取fifo中的数据，重复绘制数据 ****************
void ECG::oneTimeOutReadFromFifoAction() {//一直进行绘制，不会停止，除非手动停止
//	qDebug() << QString("fifo中剩余的数据个数%1").arg(m_EcgShortQueue.size());
	//环形队列如果内部没有数据的时候，fifoOut一直为0
	qint16 drawPoint = 0;
	if (axis_x_counts == AXIS_X_MAX_COUNTS)
	{
		axis_x_counts = 0;
	}
	if (m_EcgShortQueue.size() != 0)
	{
		drawPoint = m_EcgShortQueue.dequeue();
	}
	ecgSeries->replace(axis_x_counts, QPointF(axis_x_counts, drawPoint));//这种方式CPU消耗较小，相对于替换所有的PointBuffer，即下面的方法
	axis_x_counts++;

}

//**** 从文本框中读取ECG数据 ***
void ECG::readEcgData() {
	QFile resFile("./Resources/ecgData.csv");
	resFile.open(QIODevice::ReadOnly);
	QTextStream * out = new QTextStream(&resFile);
	QString origin = out->readAll();
	originList.clear();
	originList = origin.split(",");
	originListSize = originList.count();
	//	qDebug() << QString("数据大小%1").arg(originListSize);
}

void ECG::initEcgWaveLineChart() {
	axisY_ECG = new QValueAxis();
	axisX_ECG = new QValueAxis();
	ecgSeries = new QLineSeries();//这里也可以也考虑改为平滑曲线
	ecgWaveLineChart = new QChart();

	//添加曲线到chart中
	ecgWaveLineChart->addSeries(ecgSeries);

	//设置坐标轴显示范围
	axisY_ECG->setRange(-350, 1200);
	axisX_ECG->setRange(0, AXIS_X_MAX_COUNTS);
	axisX_ECG->setTickCount(25);//横坐标30个数据点
	axisY_ECG->setTickCount(10);//纵坐标分为10块

								//设置坐标轴的颜色，粗细和设置网格显示
	axisX_ECG->setGridLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin)); //网格样式
	axisY_ECG->setGridLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));

	axisX_ECG->setLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));//坐标轴样式
	axisY_ECG->setLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));

	axisY_ECG->setGridLineVisible(true);//显示线框
	axisX_ECG->setGridLineVisible(true);

	axisX_ECG->setLabelsVisible(false);//不显示label具体数值
	axisY_ECG->setLabelsVisible(false);

	//把坐标轴添加到chart中，第二个参数是设置坐标轴的位置，
	//只有四个选项，下方：Qt::AlignBottom，左边：Qt::AlignLeft，右边：Qt::AlignRight，上方：Qt::AlignTop
	ecgWaveLineChart->addAxis(axisX_ECG, Qt::AlignBottom);
	ecgWaveLineChart->addAxis(axisY_ECG, Qt::AlignLeft);

	//把曲线关联到坐标轴
	ecgSeries->attachAxis(axisX_ECG);
	ecgSeries->attachAxis(axisY_ECG);
	ecgSeries->setColor(QColor(Qt::black));//设置线的颜色
    //ecgSeries->setUseOpenGL(true);//openGL加速  在我的电脑上如果采用加速，绘制速度反倒会变慢
	Helper::setLineChartMargins(ecgWaveLineChart, 1);//设置折线图边距

	ecgWaveLineChart->legend()->hide();//不显示注释
	ui.chartView->setChart(ecgWaveLineChart);//这里就可以把我们设置好的QrChart与QChartView进行绑定

}

void ECG::ecgDataFifoIn(qint16 inputData) {
	//////////////////////////////////////////////
	/* Explicitly clear the source of interrupt if necessary */

	if (ecg_data_fifo.num_bytes == FIFO_BUFFER_SIZE) {      // if the sw buffer is full
		fifo_ovf_flag = 1;                     // set the overflow flag

											   //TODO fifo_ovf_flag，这个标志影响是否还写入，或者是清空已有数据，然后重新谢写入？
	}
	else if (ecg_data_fifo.num_bytes < FIFO_BUFFER_SIZE) { // if there's room in the sw buffer

														   ///////////////////////////////////////////////////
														   /* read error/status reg here if desired         */
														   /* handle any hardware RX errors here if desired */
														   ///////////////////////////////////////////////////

														   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		ecg_data_fifo.data_buf[ecg_data_fifo.i_last] = inputData;/* enter pointer to UART rx hardware buffer here */ // store the received data as the newest data element in the sw buffer
																													 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		ecg_data_fifo.i_last++;                              // increment the index of the most recently added element
		ecg_data_fifo.num_bytes++;                           // increment the bytes counter

	}
	if (ecg_data_fifo.num_bytes == FIFO_BUFFER_SIZE) {      // if sw buffer just filled up
		fifo_full_flag = 1;
		//TODO fifo_ovf_flag，这个标志影响是否还写入，或者是清空已有数据，然后重新谢写入？
		// set the  FIFO full flag
	}
	if (ecg_data_fifo.i_last == FIFO_BUFFER_SIZE) {         // if the index has reached the end of the buffer,
		ecg_data_fifo.i_last = 0;                            // roll over the index counter
	}
	fifo_not_empty_flag = 1;                 // set received-data flag
} // end UART RX IRQ handler


  //如果在环形队列中没有数据，返回为0
qint16 ECG::ecgDataFifoOut() {
	//////////////////////////////////////////////

	/* Explicitly clear the source of interrupt if necessary */
	qint16 outputData = 0;
	if (ecg_data_fifo.num_bytes == FIFO_BUFFER_SIZE) { // if the sw buffer is full
		fifo_full_flag = 0;               // clear the buffer full flag because we are about to make room
	}

	if (ecg_data_fifo.num_bytes > 0) {                 // if data exists in the sw buffer

		outputData = ecg_data_fifo.data_buf[ecg_data_fifo.i_first]; // place oldest data element in the buffer

		ecg_data_fifo.i_first++;                        // increment the index of the oldest element
		ecg_data_fifo.num_bytes--;                      // decrement the bytes counter
	}
	if (ecg_data_fifo.i_first == FIFO_BUFFER_SIZE) {   // if the index has reached the end of the buffer,
		ecg_data_fifo.i_first = 0;                      // roll over the index counter
	}
	if (ecg_data_fifo.num_bytes == 0) {                // if no more data exists
		fifo_not_empty_flag = 0;          // clear flag
	}
	return outputData;
}

void ECG::initStyle()
{
	QString sty = "QWidget{background-color: #FFFFFF;border-radius: 5px;}";
	ui.ECG_widget->setStyleSheet("QWidget{background-color: #EDEDED;border-radius: 0px;}");
	ui.ECG_widget1->setStyleSheet(sty);
	ui.ECG_widget2->setStyleSheet(sty);
	//ui.label_3->setStyleSheet("color:");

}




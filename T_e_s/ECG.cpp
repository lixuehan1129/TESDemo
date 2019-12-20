#include "ECG.h"


//��������
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
	//��ǰ�����㣬�Ͳ��ÿ����Ƿ��ǵ�һ�λ��ƣ�ֻ���滻���е������
	for (int i = 0; i < AXIS_X_MAX_COUNTS; i++)
	{
		//ecgPointBuffer.append(QPointF(i, 0));
		*ecgSeries << QPointF(i, 0);
	}

	//ģ��TCP���ݵ����Ķ�ʱ��
	ecgWaveReadTimer = new QTimer(this);
	connect(ecgWaveReadTimer, SIGNAL(timeout()), this, SLOT(oneTimeOutWriteToFifoAction()));
	ecgWaveReadTimer->start(500);//500msִ��һ��

								 //******�������߶�ʱ��***********
	ecgWaveDrawTimer = new QTimer(this);
	ecgWaveDrawTimer->setInterval(DRAW_ECG_INTERVAL);
	ecgWaveDrawTimer->setTimerType(Qt::PreciseTimer);//��ȷ
	connect(ecgWaveDrawTimer, SIGNAL(timeout()), this, SLOT(oneTimeOutReadFromFifoAction()));
	ecgWaveDrawTimer->start();

}

//ģ��500ms�յ�һ�����ݰ� �Ժ��ⲿ�־Ϳ�����TCP�����Ǵ��ڽ��յ�һ�����ݾͼ���һ�λ������
void ECG::oneTimeOutWriteToFifoAction() {
	for (int i = originListIndex; i < (125 + originListIndex); i++)
	{
		qint16 tempInt16 = originList.at(i).toInt();
		m_EcgShortQueue.enqueue(tempInt16);
	}
	originListIndex += 125;
	//���ʣ�µ����ݲ�����֧����һ�����ݶ�ȡ
	if ((originListIndex + 125) >= originListSize)
	{
		ecgWaveReadTimer->stop();

	//	readEcgData();
	}
}

//********* ��ȡfifo�е����ݣ��ظ��������� ****************
void ECG::oneTimeOutReadFromFifoAction() {//һֱ���л��ƣ�����ֹͣ�������ֶ�ֹͣ
//	qDebug() << QString("fifo��ʣ������ݸ���%1").arg(m_EcgShortQueue.size());
	//���ζ�������ڲ�û�����ݵ�ʱ��fifoOutһֱΪ0
	qint16 drawPoint = 0;
	if (axis_x_counts == AXIS_X_MAX_COUNTS)
	{
		axis_x_counts = 0;
	}
	if (m_EcgShortQueue.size() != 0)
	{
		drawPoint = m_EcgShortQueue.dequeue();
	}
	ecgSeries->replace(axis_x_counts, QPointF(axis_x_counts, drawPoint));//���ַ�ʽCPU���Ľ�С��������滻���е�PointBuffer��������ķ���
	axis_x_counts++;

}

//**** ���ı����ж�ȡECG���� ***
void ECG::readEcgData() {
	QFile resFile("./Resources/ecgData.csv");
	resFile.open(QIODevice::ReadOnly);
	QTextStream * out = new QTextStream(&resFile);
	QString origin = out->readAll();
	originList.clear();
	originList = origin.split(",");
	originListSize = originList.count();
	//	qDebug() << QString("���ݴ�С%1").arg(originListSize);
}

void ECG::initEcgWaveLineChart() {
	axisY_ECG = new QValueAxis();
	axisX_ECG = new QValueAxis();
	ecgSeries = new QLineSeries();//����Ҳ����Ҳ���Ǹ�Ϊƽ������
	ecgWaveLineChart = new QChart();

	//������ߵ�chart��
	ecgWaveLineChart->addSeries(ecgSeries);

	//������������ʾ��Χ
	axisY_ECG->setRange(-350, 1200);
	axisX_ECG->setRange(0, AXIS_X_MAX_COUNTS);
	axisX_ECG->setTickCount(25);//������30�����ݵ�
	axisY_ECG->setTickCount(10);//�������Ϊ10��

								//�������������ɫ����ϸ������������ʾ
	axisX_ECG->setGridLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin)); //������ʽ
	axisY_ECG->setGridLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));

	axisX_ECG->setLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));//��������ʽ
	axisY_ECG->setLinePen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::SquareCap, Qt::RoundJoin));

	axisY_ECG->setGridLineVisible(true);//��ʾ�߿�
	axisX_ECG->setGridLineVisible(true);

	axisX_ECG->setLabelsVisible(false);//����ʾlabel������ֵ
	axisY_ECG->setLabelsVisible(false);

	//����������ӵ�chart�У��ڶ��������������������λ�ã�
	//ֻ���ĸ�ѡ��·���Qt::AlignBottom����ߣ�Qt::AlignLeft���ұߣ�Qt::AlignRight���Ϸ���Qt::AlignTop
	ecgWaveLineChart->addAxis(axisX_ECG, Qt::AlignBottom);
	ecgWaveLineChart->addAxis(axisY_ECG, Qt::AlignLeft);

	//�����߹�����������
	ecgSeries->attachAxis(axisX_ECG);
	ecgSeries->attachAxis(axisY_ECG);
	ecgSeries->setColor(QColor(Qt::black));//�����ߵ���ɫ
    //ecgSeries->setUseOpenGL(true);//openGL����  ���ҵĵ�����������ü��٣������ٶȷ��������
	Helper::setLineChartMargins(ecgWaveLineChart, 1);//��������ͼ�߾�

	ecgWaveLineChart->legend()->hide();//����ʾע��
	ui.chartView->setChart(ecgWaveLineChart);//����Ϳ��԰��������úõ�QrChart��QChartView���а�

}

void ECG::ecgDataFifoIn(qint16 inputData) {
	//////////////////////////////////////////////
	/* Explicitly clear the source of interrupt if necessary */

	if (ecg_data_fifo.num_bytes == FIFO_BUFFER_SIZE) {      // if the sw buffer is full
		fifo_ovf_flag = 1;                     // set the overflow flag

											   //TODO fifo_ovf_flag�������־Ӱ���Ƿ�д�룬����������������ݣ�Ȼ������лд�룿
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
		//TODO fifo_ovf_flag�������־Ӱ���Ƿ�д�룬����������������ݣ�Ȼ������лд�룿
		// set the  FIFO full flag
	}
	if (ecg_data_fifo.i_last == FIFO_BUFFER_SIZE) {         // if the index has reached the end of the buffer,
		ecg_data_fifo.i_last = 0;                            // roll over the index counter
	}
	fifo_not_empty_flag = 1;                 // set received-data flag
} // end UART RX IRQ handler


  //����ڻ��ζ�����û�����ݣ�����Ϊ0
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




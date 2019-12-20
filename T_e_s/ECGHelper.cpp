#include "ECGHelper.h"

ECGHelper::ECGHelper(QChartView* qChartView, int range)
{
	this->qChartView = qChartView;
	this->range = range;

	initEcgWaveLineChart();
	//readEcgData();
}

ECGHelper::~ECGHelper()
{
}

void ECGHelper::readEcgData() {
	QFile resFile("./VideoStore/ecgData.csv");
	resFile.open(QIODevice::ReadOnly);
	QTextStream * out = new QTextStream(&resFile);
	QString origin = out->readAll();
	originList.clear();
	originList = origin.split(",");
	originListSize = originList.count();
	//	qDebug() << QString("���ݴ�С%1").arg(originListSize);
}

void ECGHelper::PaseOrStart() {

	//��ͣ
	if (Is_Pase == true)
	{
		Is_Pase = false;
	}
	else {
		Is_Pase = true;
	}
}

void ECGHelper::Release() {
	//ֹͣ����
	Stop_Play = true;
	Is_Point_play = false;
}

void ECGHelper::setPoint(int position)
{
	this->pos = position / 8;

	/*if (x < originListSize)
	{
		qint16 tempInt16 = originList.at(x).toInt();
		qDebug() << tempInt16;
		series->append(QPointF(x, tempInt16));
	}*/

	/*series->clear();
	if (originListSize > 0)
	{
		series->append(QPointF(x,tempInt16));
	}*/
}

void ECGHelper::run()
{
	readEcgData();
	while (Is_Point_play)
	{
		if (Stop_Play)
		{
			break;
		}
		while (axis_x_counts < originListSize)
		{
			qint16 tempInt16 = originList.at(axis_x_counts).toInt();
			ecgSeries->append(QPointF(axis_x_counts, tempInt16));
			axis_x_counts++;
			QTest::qSleep(1);
			if (Stop_Play)
			{
				break;
			}
		}	
		if (Is_Pase)
		{
			if (pos < originListSize)
			{		
				series->clear();
				qint16 tempInt16 = originList.at(pos).toInt();
				series->append(QPointF(pos, tempInt16));
				//qDebug() << pos << originListSize << tempInt16;
				QTest::qSleep(500);
			}
			
		}
		

	}

	
}

void ECGHelper::initEcgWaveLineChart()
{
	axisY_ECG = new QValueAxis();
	axisX_ECG = new QValueAxis();
	ecgSeries = new QLineSeries();//����Ҳ����Ҳ���Ǹ�Ϊƽ������
	ecgWaveLineChart = new QChart();

	series = new QScatterSeries();
	series->setMarkerShape(QScatterSeries::MarkerShapeCircle);//Բ�εĵ�
	series->setBorderColor(QColor(Qt::blue));  //�߿���ɫ
	series->setBrush(QBrush(QColor(Qt::blue)));//������ɫ
	series->setMarkerSize(6);                     //���С

	//������ߵ�chart��
	ecgWaveLineChart->addSeries(ecgSeries);
	ecgWaveLineChart->addSeries(series);

	//������������ʾ��Χ
	axisY_ECG->setRange(-350, 1200);
	axisX_ECG->setRange(0, range);
	axisX_ECG->setTickCount(40);//������30�����ݵ�
	axisY_ECG->setTickCount(10);//�������Ϊ10��

	//axisY_ECG->setTickType(QValueAxis::TickType::TicksFixed);

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

	series->attachAxis(axisX_ECG);
	series->attachAxis(axisY_ECG);

	//�����߹�����������
	ecgSeries->attachAxis(axisX_ECG);
	ecgSeries->attachAxis(axisY_ECG);
	ecgSeries->setColor(QColor(Qt::black));//�����ߵ���ɫ
										   //ecgSeries->setUseOpenGL(true);//openGL����  ���ҵĵ�����������ü��٣������ٶȷ��������
	Helper::setLineChartMargins(ecgWaveLineChart, 1);//��������ͼ�߾�

	ecgWaveLineChart->legend()->hide();//����ʾע��
	qChartView->setChart(ecgWaveLineChart);//����Ϳ��԰��������úõ�QrChart��QChartView���а�
}


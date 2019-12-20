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
	//	qDebug() << QString("数据大小%1").arg(originListSize);
}

void ECGHelper::PaseOrStart() {

	//暂停
	if (Is_Pase == true)
	{
		Is_Pase = false;
	}
	else {
		Is_Pase = true;
	}
}

void ECGHelper::Release() {
	//停止播放
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
	ecgSeries = new QLineSeries();//这里也可以也考虑改为平滑曲线
	ecgWaveLineChart = new QChart();

	series = new QScatterSeries();
	series->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
	series->setBorderColor(QColor(Qt::blue));  //边框颜色
	series->setBrush(QBrush(QColor(Qt::blue)));//背景颜色
	series->setMarkerSize(6);                     //点大小

	//添加曲线到chart中
	ecgWaveLineChart->addSeries(ecgSeries);
	ecgWaveLineChart->addSeries(series);

	//设置坐标轴显示范围
	axisY_ECG->setRange(-350, 1200);
	axisX_ECG->setRange(0, range);
	axisX_ECG->setTickCount(40);//横坐标30个数据点
	axisY_ECG->setTickCount(10);//纵坐标分为10块

	//axisY_ECG->setTickType(QValueAxis::TickType::TicksFixed);

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

	series->attachAxis(axisX_ECG);
	series->attachAxis(axisY_ECG);

	//把曲线关联到坐标轴
	ecgSeries->attachAxis(axisX_ECG);
	ecgSeries->attachAxis(axisY_ECG);
	ecgSeries->setColor(QColor(Qt::black));//设置线的颜色
										   //ecgSeries->setUseOpenGL(true);//openGL加速  在我的电脑上如果采用加速，绘制速度反倒会变慢
	Helper::setLineChartMargins(ecgWaveLineChart, 1);//设置折线图边距

	ecgWaveLineChart->legend()->hide();//不显示注释
	qChartView->setChart(ecgWaveLineChart);//这里就可以把我们设置好的QrChart与QChartView进行绑定
}


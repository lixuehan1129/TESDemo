#include "MySlider.h"
#include <QMouseEvent>
#include <QDebug>

MySlider::MySlider(QWidget *parent) :QSlider(parent)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *ev)
{
	//��ȡ��ǰ���λ��
	int currentX = ev->pos().x();

	//��ȡ��ǰ�����λ��ռ����Slider�İٷֱ�
	double per = currentX *1.0 / this->width();

	//������õİٷֱȵõ���������
	int value = per*(this->maximum() - this->minimum()) + this->minimum();

	//qDebug() << value;

	//�趨������λ��
	this->setValue(value);

	//�������ƶ��¼����¼�Ҳ�õ���mousePressEvent,����仰��Ϊ�˲��������Ӱ�죬�ǵ�Slider��������Ӧ��������¼�
	QSlider::mousePressEvent(ev);
}

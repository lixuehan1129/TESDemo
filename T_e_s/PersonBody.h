#pragma once
#include <QWidget>
#include <QLabel>
#include <QEvent>  
#include <QPainter>
#include <QMetaType>
#include "ui_PersonBody.h"
#pragma execution_character_set("utf-8") 


//人员数据
typedef struct {
	//item传入数据
	QString personName;
	QString personSex;
	QString personAge;
	QString personWeight;
	QString personHeight;
	QString personStatus;
	QString personHead;
}PersonBodyBean;

Q_DECLARE_METATYPE(PersonBodyBean)


//自定义信息Item类 
class PersonBody : public QWidget
{
	Q_OBJECT

public:
	PersonBody(QWidget *parent = Q_NULLPTR);
	~PersonBody();

	void initUi();

	QLabel *label_head;
	QLabel *label_name;
	QLabel *label_sex;
	QLabel *label_age;
	QLabel *label_weight;
	QLabel *label_height;
	QLabel *label_status;
	QString headPath;
	bool eventFilter(QObject *obj, QEvent *event);//事件过滤器 
	void setData(PersonBodyBean *personBodyBean);

signals:

public slots:

private:
	Ui::PersonBody ui;

};


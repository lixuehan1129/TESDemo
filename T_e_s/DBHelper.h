#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "DataStruct.h"
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

#pragma execution_character_set("utf-8") 

class DBHelper
{
public:
	DBHelper();
	~DBHelper();
	QSqlDatabase createConnection();  //创建一个连接
	void createTable();       //创建数据库表
//	bool insert();            //出入数据
//	bool queryAll();          //查询所有信息
	void close();             //关闭数据库

	bool insertDevice(Device device); //插入摄像设备数据

	QList<Device> getDevice();

	//获取人员ID
	int getPersonCount();


private:

};
#endif


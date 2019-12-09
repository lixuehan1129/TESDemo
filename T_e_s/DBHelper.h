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
	QSqlDatabase createConnection();  //����һ������
	void createTable();       //�������ݿ��
//	bool insert();            //��������
//	bool queryAll();          //��ѯ������Ϣ
	void close();             //�ر����ݿ�

	bool insertDevice(Device device); //���������豸����

	QList<Device> getDevice();

	//��ȡ��ԱID
	int getPersonCount();


private:

};
#endif


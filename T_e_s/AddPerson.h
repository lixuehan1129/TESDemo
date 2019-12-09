#pragma once

#include <QWidget>
#include "ui_AddPerson.h"
#include "T_e_s.h"
#include "QMessageBox"
#include "DataStruct.h"
#include <QDebug>
#include <DBHelper.h>
#pragma execution_character_set("utf-8") 

using namespace std;

class AddPerson : public QWidget
{
	Q_OBJECT

public:
	AddPerson(QWidget *parent = Q_NULLPTR);
	~AddPerson();


private slots:
	void on_pushButton_sure_clicked();
	void on_pushButton_cancel_clicked();
	void on_radioButton_man_toggled();
	//void on_radioButton_woman_toggled();

signals:
	//void SendData(Device device);
private:
	Ui::AddPerson ui;
	Person person;
	DBHelper dBHelper;

	void styleSheet();
	int personSex = 0;//0ÄÐ£¬Ä¬ÈÏ


};
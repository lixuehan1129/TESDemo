#pragma once

#include <QWidget>
#include "ui_AddCamera.h"
#include "T_e_s.h"
#include "QMessageBox"
#include "DataStruct.h"
#include <QDebug>
#include <DBHelper.h>
#include "HKCamDriver.h"
#pragma execution_character_set("utf-8") 

using namespace std;

class AddCamera : public QWidget
{
	Q_OBJECT

public:
	AddCamera(QWidget *parent = Q_NULLPTR);
	~AddCamera();
	
private slots:
	void on_pushButton_sure_clicked();
	void on_pushButton_cancel_clicked();

signals:
	void SendData(Device device);
private:
	Ui::AddCamera ui;

	void styleSheet();

	Device device;
	bool isIPAddressValid(const char* pszIPAddr);
	DBHelper dBHelper;
	HKCamDriver camDriver;


};
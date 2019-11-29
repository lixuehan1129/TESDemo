#pragma once

#include <QWidget>
#include "ui_AddCamera.h"
#include "T_e_s.h"
#include "QMessageBox"
#pragma execution_character_set("utf-8") 

extern QString Team_name;
extern QString Team_from;
extern QString Team_number;
extern QString Team_boss;
extern QString Team_phone;
extern QString Team_rater;
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
	void BackTo();
private:
	Ui::AddCamera ui;

	void styleSheet();

};
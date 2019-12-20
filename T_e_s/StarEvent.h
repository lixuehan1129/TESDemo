#pragma once

#include "ui_StarEvent.h"
#include <QDialog>
#include <QCheckBox>
#include <QDebug>
#include "QMessageBox"
#include "AddStar.h"

#pragma execution_character_set("utf-8") 
#define MAXSIZE 100

class StarEvent : public QDialog
{
	Q_OBJECT;

public:
	StarEvent(QWidget *parent = Q_NULLPTR);
	~StarEvent();

public slots:
    void on_pushButton_sure_clicked();
	void on_pushButton_cancel_clicked();
	void on_pushButton_add_clicked();
	void getData(QString str);

signals:
	void returnCheck(QString str);

private:
	Ui::StarEvent ui;

	void initStyle();
	void initData();
	QStringList strL;
	QCheckBox* checkBox[MAXSIZE];

};



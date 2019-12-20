#pragma once

#include <ui_AddStar.h>
#include <QDialog>
#include "QMessageBox"

#pragma execution_character_set("utf-8") 

class AddStar : public QDialog
{
	Q_OBJECT;

public:
	AddStar(QWidget *parent = Q_NULLPTR);
	~AddStar();

public slots:
    void on_pushButton_ok_clicked();

signals:
	void returnData(QString str);

private:
	Ui::AddStar ui;

	void initStyle();
};



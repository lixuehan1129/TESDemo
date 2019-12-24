#pragma once

#include <QWidget>
#include <QMetaType>
#pragma execution_character_set("utf-8") 
typedef struct {
//	QString cameraId;
	QString cameraName;
	QString cameraIp;
	QString cameraPort;
	QString cameraUser;
	QString cameraPw;
}Device;

Q_DECLARE_METATYPE(Device)

//Person
typedef struct {
	QString personId;
	QString personName;
	int personAge;
	int personSex;
	int personWeight;
	int personHeight;
	QString personBand;
	QString personPic;
}Person;

Q_DECLARE_METATYPE(Person)



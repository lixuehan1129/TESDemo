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



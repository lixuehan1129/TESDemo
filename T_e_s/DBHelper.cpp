#include "DBHelper.h"


DBHelper::DBHelper()
{
}

DBHelper::~DBHelper()
{
	
}

QSqlDatabase DBHelper::createConnection()
{
	QSqlDatabase database;
	if (QSqlDatabase::contains("sqlite"))
	{
		database = QSqlDatabase::database("sqlite");
	}
	else
	{
		database = QSqlDatabase::addDatabase("QSQLITE", "sqlite");
		database.setDatabaseName("DataBase.db");
		if (!database.open())
		{
			printf("failed\n");
		}
	}
	return database;
}

//创建数据库表
void DBHelper::createTable()
{
	QSqlDatabase db = QSqlDatabase::database("sqlite"); //建立数据库连接
	QSqlQuery query(db);
	bool success = query.exec("CREATE TABLE IF NOT EXISTS camera(camera_id INTEGER PRIMARY KEY AUTOINCREMENT,camera_name VARCHAR NOT NULL,"
		"camera_ip VARCHAR NOT NULL UNIQUE,camera_port VARCHAR NOT NULL,camera_user VARCHAR NOT NULL,camera_pw VARCHAR NOT NULL)");
	if (success)
	{
		printf("create_success\n");
	}
	else
	{
		printf("create_failed\n");
	}

	db.close();

}

bool DBHelper::insertDevice(Device device)
{
	QSqlDatabase db = createConnection();
//	QSqlDatabase db = QSqlDatabase::database("sqlite"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("INSERT INTO camera (camera_name,camera_ip,camera_port,camera_user,camera_pw) VALUES(?, ?, ?, ?, ?)");
	query.bindValue(0, device.cameraName);
	query.bindValue(1, device.cameraIp);
	query.bindValue(2, device.cameraPort);
	query.bindValue(3, device.cameraUser);
	query.bindValue(4, device.cameraPw);  

	bool success=query.exec();
	db.close();
	if(!success)
    {
		QSqlError lastError = query.lastError();	
        return false;
	}
	else
	{
		return true;
	}
}

QList<Device> DBHelper::getDevice()
{
	QList<Device> devices;
	Device device;

	QSqlDatabase db = createConnection();
//	QSqlDatabase db = QSqlDatabase::database("sqlite"); //建立数据库连接
	QSqlQuery query(db);
	bool success = query.exec("SELECT camera_name,camera_ip,camera_port,camera_user,camera_pw FROM camera ORDER BY camera_id");
	if (success)
	{
		while (query.next())
		{
		//	device.cameraId = query.value(0).toString();
			device.cameraName = query.value(0).toString();
			device.cameraIp = query.value(1).toString();
			device.cameraPort = query.value(2).toString();
			device.cameraUser = query.value(3).toString();
			device.cameraPw = query.value(4).toString();
			devices << device;
		}
	}
	else
	{
		QSqlError lastError = query.lastError();
		qDebug() << lastError.driverText();
	}
	db.close();
	return devices;
	
}

void DBHelper::close()
{
	QSqlDatabase database = QSqlDatabase::database("sqlite");
	database.close();
}

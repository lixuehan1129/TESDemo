#include <HKThread.h>

using namespace std;

HKThread::HKThread(QObject *parent)
	:QThread(parent)
{

}

void HKThread::run()
{

	if (camera.Init())
	{
		if (camera.Login(add, "admin", "Zz123456", 8000))
		{
			camera.show();
			//timer = new QTimer();
			//timer->start(20);
			//connect(timer, SIGNAL(timeout()), this, SLOT(show_cam()));
		}
	}
	this->exec();

}

void HKThread::show_cam()
{
	//emit return_QImage1(camera.return_QImage());
	

}

#include <PersonBody.h>


PersonBody::PersonBody(QWidget *parent) :
	QWidget(parent)
{
	ui.setupUi(this);
	initUi();
}

PersonBody::~PersonBody()
{
}

void PersonBody::initUi()
{

	label_head = ui.label_head;
	label_name = ui.label_name;
	label_sex = ui.label_sex;
	label_age = ui.label_age;
	label_weight = ui.label_weight;
	label_height = ui.label_height;
	label_status = ui.label_status;

	//装载事件过滤器  
	label_head->installEventFilter(this);
	
}

void PersonBody::setData(PersonBodyBean *personBodyBean)
{
	headPath = personBodyBean->personHead;
	label_name->setText(personBodyBean->personName);
	label_sex->setText(personBodyBean->personSex);
	label_age->setText(personBodyBean->personAge);
	label_weight->setText(personBodyBean->personWeight);
	label_height->setText(personBodyBean->personHeight);
	QString string = personBodyBean->personStatus;
	QString str = label_status->fontMetrics().elidedText(string, Qt::ElideRight, 1000);
	label_status->setText(str);
}

//事件过滤器，主要是为了让图片能够全部填充在head里面  
bool PersonBody::eventFilter(QObject *obj, QEvent *event)
{
	if (obj  == label_head)
	{
		if (event->type() == QEvent::Paint)
		{
			QPainter painter(label_head);
			painter.drawPixmap(label_head->rect(), QPixmap(headPath));
		}
	}
	return QWidget::eventFilter(obj, event);
}






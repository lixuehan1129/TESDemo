#pragma once
#pragma execution_character_set("utf-8")

#ifndef MY_HELPER_H
#define MY_HELPER_H

#include <QObject>
#include <QListWidget>
#include <QSettings>
#include <QWidget>
#include <QDesktopWidget>
#include <QFile>
#include <QFileIconProvider>
#include <QTextCodec>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QTime>
#include <QDateTime>
#include <QDate>
#include <QCoreApplication>
#include <QFileDialog>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QCursor>
#include <QTimer>
//#include <QSound>
#include <QApplication>
#include <QStyleFactory>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QtWidgets/QTableWidget>
#include <QtCharts>
typedef uint16_t u16;
typedef uint8_t u8;

class Helper :public QObject
{
public:

	//����ȫ��Ϊplastique��ʽ
	static void SetPlastiqueStyle()
	{
		QApplication::setStyle(QStyleFactory::create("Plastique"));
		QApplication::setPalette(QApplication::style()->standardPalette());//�滻Ӧ�ó������ɫ���
	}

	//��ʾ��Ϣ�򣬽�ȷ����ť
	static void ShowMessageBoxInfo(QString info)
	{
		QMessageBox msg;
		msg.setStyleSheet("font:12pt '����'");
		msg.setWindowTitle(tr("��ʾ"));
		msg.setText(info);
		msg.setIcon(QMessageBox::Information);
		msg.addButton(tr("ȷ��"), QMessageBox::ActionRole);
		msg.exec();
	}

	//��ʾ����򣬽�ȷ����ť
	static void ShowMessageBoxError(QString info)
	{
		QMessageBox msg;
		msg.setStyleSheet("font:12pt '����'");
		msg.setWindowTitle(tr("����"));
		msg.setText(info);
		msg.setIcon(QMessageBox::Critical);
		msg.addButton(tr("ȷ��"), QMessageBox::ActionRole);
		msg.exec();
	}

	//��ʾѯ�ʿ�ȷ����ȡ����ť
	static int ShowMessageBoxQuesion(QString info)
	{
		QMessageBox msg;
		msg.setStyleSheet("font:12pt '����'");
		msg.setWindowTitle(tr("ѯ��"));
		msg.setText(info);
		msg.setIcon(QMessageBox::Question);
		msg.addButton(tr("ȷ��"), QMessageBox::ActionRole);
		msg.addButton(tr("ȡ��"), QMessageBox::RejectRole);

		return msg.exec();
	}

	//16�����ַ���ת�ֽ�����
	static QByteArray HexStrToByteArray(QString str)
	{
		QByteArray senddata;
		int hexdata, lowhexdata;
		int hexdatalen = 0;
		int len = str.length();
		senddata.resize(len / 2);
		char lstr, hstr;
		for (int i = 0; i < len; )
		{
			hstr = str[i].toLatin1();
			if (hstr == ' ')
			{
				i++;
				continue;
			}
			i++;
			if (i >= len)
				break;
			lstr = str[i].toLatin1();
			hexdata = ConvertHexChar(hstr);
			lowhexdata = ConvertHexChar(lstr);
			if ((hexdata == 16) || (lowhexdata == 16))
				break;
			else
				hexdata = hexdata * 16 + lowhexdata;
			i++;
			senddata[hexdatalen] = (char)hexdata;
			hexdatalen++;
		}
		senddata.resize(hexdatalen);
		return senddata;
	}

	static char ConvertHexChar(char ch)
	{
		if ((ch >= '0') && (ch <= '9'))
			return ch - 0x30;
		else if ((ch >= 'A') && (ch <= 'F'))
			return ch - 'A' + 10;
		else if ((ch >= 'a') && (ch <= 'f'))
			return ch - 'a' + 10;
		else return (-1);
	}

	//�ֽ�����ת16�����ַ���
	static QString ByteArrayToHexStr(QByteArray data)
	{
		QString temp = "";
		QString hex = data.toHex();
		for (int i = 0; i < hex.length(); i = i + 2)
		{
			temp += hex.mid(i, 2) + " ";
		}
		return temp.trimmed().toUpper();
	}

	//16�����ַ���ת10����
	static uchar StrHexToDecimal(QString strHex)
	{
		bool ok;
		return strHex.toInt(&ok, 16);
	}

	//10�����ַ���ת10����
	static uchar StrDecimalToDecimal(QString strDecimal)
	{
		bool ok;
		return strDecimal.toInt(&ok, 10);
	}

	//16�����ַ���ת2�����ַ���
	static QString StrHexToStrBin(QString strHex)
	{
		uchar decimal = StrHexToDecimal(strHex);
		QString bin = QString::number(decimal, 2);

		uchar len = bin.length();
		if (len < 8)
		{
			for (int i = 0; i < 8 - len; i++)
			{
				bin = "0" + bin;
			}
		}

		return bin;
	}

	//����У����
	static uchar GetCheckCode(uchar data[], uchar len)
	{
		uchar temp = 0;

		for (uchar i = 0; i < len; i++)
		{
			temp += data[i];
		}

		return temp % 256;
	}

	//��ʱ
	static void Sleep(int sec)
	{
		QTime dieTime = QTime::currentTime().addMSecs(sec);
		while (QTime::currentTime() < dieTime)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}

	//��ȡ��ǰ·��
	static QString GetCurrentPath()
	{
		return QString(QCoreApplication::applicationDirPath() + "/");
	}


	//��ȡ��ǰ����ʱ������
	static QString GetLongDateTime()
	{
		QDateTime time = QDateTime::currentDateTime();
		return time.toString("yyyy.MM.dd hh:mm:ss dddd");
	}

	//����ַ
	static void OpenUrlOrExe(QString url)
	{
		QDesktopServices::openUrl(QUrl(url));
	}

	//�ж��Ƿ�����
	static bool IsLeapYear(QString strDate)
	{
		int year = strDate.left(4).toInt();
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//���ұ���е���������ֻ��ʾƥ������������أ����ֶԱȲ���
	static void findTextInTableWidget(QTableWidget *sourceTable, QString &findText) {

		//��ȡ����������cell����
		int tempRowCount = sourceTable->rowCount();//����к�
		QList <QTableWidgetItem *> item = sourceTable->findItems(findText, Qt::MatchContains);

		for (int i = 0; i < tempRowCount; i++)
		{
			sourceTable->setRowHidden(i, true);//����������
		}

		if (!item.isEmpty())//*** ��Ϊ��**
		{
			for (int i = 0; i < item.count(); i++)
			{
				sourceTable->setRowHidden(item.at(i)->row(), false);//item.at(i).row()����к�
			}
		}

	}

	/*ModBus ����CRC��Ĳ���Ϊ��

	(1).Ԥ��16λ�Ĵ���ΪFFFFH���ƴ˼Ĵ���ΪCRC�Ĵ�����
	(2).�ѵ�һ��8λ������CRC�Ĵ����ĵ�λ����򣬰ѽ������CRC�Ĵ�����
	(3).�ѼĴ�������������һλ(����λ)����0����λ��������λ��
	(4).������λΪ0���ظ���3��(�ٴ���λ)������λΪ1��CRC�Ĵ��������ʽA001��1010 0000 0000 0001���������
	(5).�ظ�����3��4��ֱ������8�Σ���������8λ����ȫ�������˴���
	(6).�ظ�����2������5��������һ��8λ���ݵĴ���
	(7).���õ���CRC�Ĵ�����ΪCRC�롣(CRC�� = CRC_L +CRC_H)

	*/

	/*****************crcУ��**********************************************/

	//crc���ɺ���������crc�洢��Ԥ�ȶ��ڵ�������
	//���÷�ʽcrc16��ָ�����ݵ�ָ�룬��ҪУ������ݳ��ȣ�
	static u16 crc16(u8 *ptr, u8 len)
	{

		u16 wcrc = 0XFFFF; //Ԥ��16λcrc�Ĵ�������ֵȫ��Ϊ1

		u8 i = 0, j = 0; //�������

		for (i = 0; i < len; i++)
		{					//ѭ������ÿ������
			wcrc ^= *ptr++; //����λ������crc�Ĵ������.ָ���ַ���ӣ�ָ���¸�����

			for (j = 0; j < 8; j++)
			{ //ѭ���������ݵ�

				if (wcrc & 0X0001)
				{							   //�ж����Ƴ����ǲ���1�������1�������ʽ�������
					wcrc = wcrc >> 1 ^ 0XA001; //�Ƚ���������һλ��������Ķ���ʽ�������
				}
				else
				{				//�������1����ֱ���Ƴ�
					wcrc >>= 1; //ֱ���Ƴ�
				}
			}
		}

		return wcrc; //�߰�λ��ǰ���Ͱ�λ�ں�
	}

	static u8 *getCrcBuff(u8 *ptr, u8 len)
	{
		static u8 crcTemp[2];
		u16 wcrc = 0XFFFF; //Ԥ��16λcrc�Ĵ�������ֵȫ��Ϊ1

		u8 i = 0, j = 0; //�������

		for (i = 0; i < len; i++)
		{					//ѭ������ÿ������
			wcrc ^= *ptr++; //����λ������crc�Ĵ������.ָ���ַ���ӣ�ָ���¸�����

			for (j = 0; j < 8; j++)
			{ //ѭ���������ݵ�

				if (wcrc & 0X0001)
				{							   //�ж����Ƴ����ǲ���1�������1�������ʽ�������
					wcrc = wcrc >> 1 ^ 0XA001; //�Ƚ���������һλ��������Ķ���ʽ�������
				}
				else
				{				//�������1����ֱ���Ƴ�
					wcrc >>= 1; //ֱ���Ƴ�
				}
			}
		}
		crcTemp[0] = wcrc & 0x00FF;
		crcTemp[1] = (wcrc >> 8) & 0xFF;

		return crcTemp;
	}

	//
	static void changeTimeFromSecond(int *hour, int *minute, int *second) {

		*hour = *second / 3600;
		*minute = (*second - *hour * 3600) / 60;
		*second -= *hour * 3600 + *minute * 60;

	}

	//����chartView�ı�Ե���
	static void setLineChartMargins(QChart *chart, int margin) {
		QMargins m_Margin;
		m_Margin.setLeft(margin);
		m_Margin.setBottom(margin);
		m_Margin.setRight(margin);
		m_Margin.setTop(margin);

		chart->setMargins(m_Margin);
	}


};

class FormHelper :public QObject
{
public:

	//���������ʾ
	static void FormInCenter(QWidget *frm)
	{
		QDesktopWidget desktop;
		int screenX = desktop.availableGeometry().width();
		int screenY = desktop.availableGeometry().height();
		int wndX = frm->width();
		int wndY = frm->height();
		QPoint movePoint(screenX / 2 - wndX / 2, screenY / 2 - wndY / 2);
		frm->move(movePoint);
	}

	//����û����󻯰�ť
	static void FormNoMaxButton(QWidget *frm)
	{
		frm->setWindowFlags(Qt::WindowMinimizeButtonHint);
	}

	//����û����󻯺���С����ť
	static void FormOnlyCloseButton(QWidget *frm)
	{
		frm->setWindowFlags(Qt::WindowMinMaxButtonsHint);
		frm->setWindowFlags(Qt::WindowCloseButtonHint);
	}

	//���ô���͸����
	static void FormOpacity(QWidget *frm, double value)
	{
		frm->setWindowOpacity(value);
	}

	//���岻�ܸı��С
	static void FormNotResize(QWidget *frm)
	{
		frm->setFixedSize(frm->width(), frm->height());
	}

	//����ǰ����ʾ
	static void FormOnTop(QWidget *frm)
	{
		frm->setWindowFlags(Qt::WindowStaysOnTopHint);
	}

	//��������ʾ
	static void FormOnBottom(QWidget *frm)
	{
		frm->setWindowFlags(Qt::WindowStaysOnBottomHint);
	}

	//��ȡ�����С
	static QSize GetDesktopSize()
	{
		QDesktopWidget desktop;
		return QSize(desktop.availableGeometry().width(), desktop.availableGeometry().height());
	}

	//����ָ������Ϊplastique��ʽ
	static void SetPlastiqueStyle(QWidget *frm)
	{
		frm->setStyle(QStyleFactory::create("Plastique"));
	}

	static void SetCustomStyle(QWidget *frm)
	{
		QString myStyle1 = "QPushButton {";
		myStyle1.append("border: 2px solid #8f8f91; ");
		myStyle1.append("border-radius: 6px;");
		myStyle1.append("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); ");
		myStyle1.append("min-width: 80px;}");
		myStyle1.append("QPushButton:pressed {");
		myStyle1.append("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }");
		myStyle1.append("QPushButton:default  {");
		myStyle1.append("border-color: navy; /* ʹ�ð�ť��ʾ��ø���ͻ�� */}");

		QString myStyle2 = "QSlider::groove:horizontal {";
		myStyle2.append("border: 1px solid #999999;");
		myStyle2.append("height: 8px;");
		myStyle2.append("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);");
		myStyle2.append("margin: 2px 0;}");
		myStyle2.append("QSlider::handle:horizontal {");
		myStyle2.append("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);");
		myStyle2.append("border: 1px solid #5c5c5c;");
		myStyle2.append("width: 18px; margin: -2px 0;");
		myStyle2.append("border-radius: 3px;}");

		QString myStyle3 = "QGroupBox {";
		myStyle3.append("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  stop: 0 #E0E0E0, stop: 1 #FFFFFF);");
		myStyle3.append("border: 2px solid gray;");
		myStyle3.append("border-radius: 5px;");
		myStyle3.append("margin-top: 1ex;}");
		myStyle3.append("QGroupBox::title {");
		myStyle3.append("subcontrol-origin: margin; ");
		myStyle3.append("subcontrol-position: top center;");
		myStyle3.append("padding: 0 3px;}");

		frm->setStyleSheet(myStyle1 + myStyle2 + myStyle3);
	}

	//�ı���ʽ
	static bool InstallStyle(QWidget* window, QString styleFile)
	{
		QFile file(styleFile);
		QString strStyleSheet;
		if (!file.open(QIODevice::WriteOnly))
		{
			strStyleSheet = "";
		}
		else
		{
			strStyleSheet = file.readAll();
		}
		file.close();

		if (strStyleSheet.isEmpty())
		{
			return false;
		}
		window->setStyleSheet(strStyleSheet);
		return true;
	}
};


class FileHelper : public QObject
{
public:

	//��ȡѡ���ļ�
	static QString GetFileName(QString filter)
	{
		return QFileDialog::getOpenFileName(NULL, tr("ѡ���ļ�"), QCoreApplication::applicationDirPath(), filter);
	}

	//��ȡѡ���ļ�����
	static QStringList GetFileNames(QString filter)
	{
		return QFileDialog::getOpenFileNames(NULL, tr("ѡ���ļ�"), QCoreApplication::applicationDirPath(), filter);
	}

	//��ȡѡ���ļ����е��ļ�
	static QStringList GetFolderFileNames(QStringList filter)
	{
		QStringList fileList;
		QString strFolder = QFileDialog::getExistingDirectory();
		if (!strFolder.length() == 0)
		{
			QDir myFolder(strFolder);

			if (myFolder.exists())
			{
				fileList = myFolder.entryList(filter);
			}
		}
		return fileList;
	}

	//�ļ��Ƿ����
	static bool FileExists(QString strFile)
	{
		QFile tempFile(strFile);
		if (tempFile.exists())
		{
			return true;
		}
		return false;
	}

	//�ļ����Ƿ����
	static bool FolderExists(QString strFolder)
	{
		QDir tempFolder(strFolder);
		if (tempFolder.exists())
		{
			return true;
		}
		return false;
	}

	//�Ƴ��ļ�
	static bool RemoveFile(QString strFile)
	{
		return QFile::remove(strFile);
	}

	//�������ļ�
	static bool RenameFile(QString oldName, QString newName)
	{
		return QFile::rename(oldName, newName);
	}

	//��ȡ�ļ�Ŀ¼
	static QString GetBasePath(QString strFullPath)
	{
		QFileInfo fileInfo(strFullPath);
		return fileInfo.path();
	}

	//��ȡ��չ��
	static QString GetExtension(QString strFile)
	{
		QFileInfo fileInfo(strFile);
		return fileInfo.suffix();
	}

	//��ȡ�ļ�������
	static QString GetFolderName(QString strFullPath)
	{
		QString strPath(strFullPath);
		strPath.replace('\\', '/');
		int pos = strPath.lastIndexOf('/');
		return strPath.mid(pos + 1);
	}

	//�����ļ�
	static bool CopyFile(QString sourceFile, QString targetFile)
	{
		if (FileExists(targetFile))
		{
			int ret = QMessageBox::information(NULL, tr("��ʾ"), tr("�ļ��Ѿ����ڣ��Ƿ��滻��"), QMessageBox::Yes | QMessageBox::No);
			if (ret != QMessageBox::Yes)
			{
				return false;
			}
		}
		return QFile::copy(sourceFile, targetFile);
	}

	//�ж��Ƿ����ļ�
	static bool IsFile(QString strFile)
	{
		QFileInfo fileInfo(strFile);
		return fileInfo.isFile();
	}

	//�ж��Ƿ����ļ���
	static bool IsFolder(QString strFolder)
	{
		QFileInfo fileInfo(strFolder);
		return fileInfo.isDir();
	}

	//׷���ı�
	static bool AppendText(QString strFile, QString strContent)
	{
		QFile inFile(strFile);
		if (!inFile.open(QIODevice::Append | QIODevice::Text))
		{
			QMessageBox::information(NULL, tr("��ʾ"), tr("���ļ�����"));
			return false;
		}
		QTextStream inStream(&inFile);
		inStream << strContent;
		inFile.close();
		return true;
	}

	//�����ļ���
	static bool CreateFolder(QString strFolder)
	{
		QDir dir;
		return dir.mkdir(strFolder);
	}

	//�����ļ�
	static bool CreateFile(QString strFile)
	{
		QFile file(strFile);
		if (!file.open(QIODevice::WriteOnly))
		{
			return false;
		}
		file.close();
		return true;
	}

	//��ȡ�ļ�����
	static QString GetFileContent(QString strFile)
	{
		QFile file(strFile);
		QString txt;
		if (!file.open(QIODevice::WriteOnly))
		{
			txt = "";
		}
		else
		{
			txt = file.readAll();
		}
		file.close();
		return txt;
	}

};


#endif // MYHELPER_H
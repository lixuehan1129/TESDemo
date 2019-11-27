/*#include"HK_camera.h"
#include <iostream>

//ȫ�ֱ���
LONG g_nPort;
Mat g_BGRImage;
QImage image;

QImage cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image1(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image1.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}

//���ݽ���ص�������
//���ܣ���YV_12��ʽ����Ƶ������ת��Ϊ�ɹ�opencv�����BGR���͵�ͼƬ���ݣ���ʵʱ��ʾ��
void CALLBACK DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2)
{
	if (pFrameInfo->nType == T_YV12)
	{
		//std::cout << "the frame infomation is T_YV12" << std::endl;
		if (g_BGRImage.empty())
		{
			g_BGRImage.create(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC3);
		}
		Mat YUVImage(pFrameInfo->nHeight + pFrameInfo->nHeight / 2, pFrameInfo->nWidth, CV_8UC1, (unsigned char*)pBuf);

		cv::cvtColor(YUVImage, g_BGRImage, COLOR_YUV2BGR_YV12);

		imshow("RGBImage", g_BGRImage);
		waitKey(1);
		
	//	image = cvMat2QImage(g_BGRImage);

		YUVImage.~Mat();
	}

}

//ʵʱ��Ƶ�������ݻ�ȡ �ص�����
void CALLBACK g_RealDataCallBack_V30(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser)
{
	
	DWORD dRet = 0;
	BOOL inData = FALSE;

	switch (dwDataType)
	{
	case NET_DVR_SYSHEAD:
		if (!PlayM4_GetPort(&g_nPort))
		{
			break;
		}
		if (!PlayM4_OpenStream(g_nPort, pBuffer, dwBufSize, 1024 * 1024))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}

		//���ý���ص����� ֻ���벻��ʾ
	 	if (!PlayM4_SetDecCallBack(g_nPort,DecCBFun))
		{
	 		dRet = PlayM4_GetLastError(g_nPort);
		 	break;
		 }

		//���ý���ص����� ��������ʾ
		if (!PlayM4_SetDecCallBackEx(g_nPort, DecCBFun, NULL, NULL))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}

		//����Ƶ����
		if (!PlayM4_Play(g_nPort, NULL))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}

		//����Ƶ����, ��Ҫ�����Ǹ�����
		if (!PlayM4_PlaySound(g_nPort))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}
		break;

	case NET_DVR_STREAMDATA:
		inData = PlayM4_InputData(g_nPort, pBuffer, dwBufSize);
		while (!inData)
		{
			Sleep(10);
			inData = PlayM4_InputData(g_nPort, pBuffer, dwBufSize);
		}
		break;
	default:
		inData = PlayM4_InputData(g_nPort, pBuffer, dwBufSize);
		while (!inData)
		{
			Sleep(10);
			inData = PlayM4_InputData(g_nPort, pBuffer, dwBufSize);
		}
		break;
	}
}
//���캯��
HK_camera::HK_camera(void)
{

}
//��������
HK_camera::~HK_camera(void)
{
}
//��ʼ��������������ʼ��״̬���
bool HK_camera::Init()
{
	if (NET_DVR_Init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��¼��������������ͷid�Լ����������¼
bool HK_camera::Login(char* sDeviceAddress, char* sUserName, char* sPassword, WORD wPort)
{
	NET_DVR_USER_LOGIN_INFO pLoginInfo = { 0 };
	NET_DVR_DEVICEINFO_V40 lpDeviceInfo = { 0 };

	pLoginInfo.bUseAsynLogin = 0;     //ͬ����¼��ʽ
	strcpy_s(pLoginInfo.sDeviceAddress, sDeviceAddress);
	strcpy_s(pLoginInfo.sUserName, sUserName);
	strcpy_s(pLoginInfo.sPassword, sPassword);
	pLoginInfo.wPort = wPort;

	lUserID = NET_DVR_Login_V40(&pLoginInfo, &lpDeviceInfo);

	if (lUserID < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//��Ƶ����ʾ����
void HK_camera::show()
{
	//����Ԥ�������ûص�������
	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	struPlayInfo.hPlayWnd = NULL; //����Ϊ�գ��豸SDK������ֻȡ��
	struPlayInfo.lChannel = 1; //Channel number �豸ͨ��
	struPlayInfo.dwStreamType = 0;// �������ͣ�0-��������1-��������2-����3��3-����4, 4-����5,5-����6,7-����7,8-����8,9-����9,10-����10
	struPlayInfo.dwLinkMode = 0;// 0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-RTP/RTSP,5-RSTP/HTTP 
	struPlayInfo.bBlocked = 1; //0-������ȡ��, 1-����ȡ��, �������SDK�ڲ�connectʧ�ܽ�����5s�ĳ�ʱ���ܹ�����,���ʺ�����ѯȡ������.

	if (NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, g_RealDataCallBack_V30, NULL))
	{
	}
}

QImage HK_camera::return_QImage()
{

	if (g_BGRImage.empty())
	{
		return QImage();
	}
	else
	{
		//cv::cvtColor(g_BGRImage, g_BGRImage, CV_BGR2RGB);
		//QImage image(g_BGRImage.data, g_BGRImage.cols, g_BGRImage.rows, QImage::Format_RGB888);
		image = cvMat2QImage(g_BGRImage);
		return image;
	}
	
}

QImage HK_camera::cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image1(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image1.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}
*/



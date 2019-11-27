/*#include"HK_camera.h"
#include <iostream>

//全局变量
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

//数据解码回调函数，
//功能：将YV_12格式的视频数据流转码为可供opencv处理的BGR类型的图片数据，并实时显示。
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

//实时视频码流数据获取 回调函数
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

		//设置解码回调函数 只解码不显示
	 	if (!PlayM4_SetDecCallBack(g_nPort,DecCBFun))
		{
	 		dRet = PlayM4_GetLastError(g_nPort);
		 	break;
		 }

		//设置解码回调函数 解码且显示
		if (!PlayM4_SetDecCallBackEx(g_nPort, DecCBFun, NULL, NULL))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}

		//打开视频解码
		if (!PlayM4_Play(g_nPort, NULL))
		{
			dRet = PlayM4_GetLastError(g_nPort);
			break;
		}

		//打开音频解码, 需要码流是复合流
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
//构造函数
HK_camera::HK_camera(void)
{

}
//析构函数
HK_camera::~HK_camera(void)
{
}
//初始化函数，用作初始化状态检测
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

//登录函数，用作摄像头id以及密码输入登录
bool HK_camera::Login(char* sDeviceAddress, char* sUserName, char* sPassword, WORD wPort)
{
	NET_DVR_USER_LOGIN_INFO pLoginInfo = { 0 };
	NET_DVR_DEVICEINFO_V40 lpDeviceInfo = { 0 };

	pLoginInfo.bUseAsynLogin = 0;     //同步登录方式
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

//视频流显示函数
void HK_camera::show()
{
	//启动预览并设置回调数据流
	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	struPlayInfo.hPlayWnd = NULL; //窗口为空，设备SDK不解码只取流
	struPlayInfo.lChannel = 1; //Channel number 设备通道
	struPlayInfo.dwStreamType = 0;// 码流类型，0-主码流，1-子码流，2-码流3，3-码流4, 4-码流5,5-码流6,7-码流7,8-码流8,9-码流9,10-码流10
	struPlayInfo.dwLinkMode = 0;// 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP 
	struPlayInfo.bBlocked = 1; //0-非阻塞取流, 1-阻塞取流, 如果阻塞SDK内部connect失败将会有5s的超时才能够返回,不适合于轮询取流操作.

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



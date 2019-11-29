/**************************************************************************************
*  FileName   : HKCamDriver.cpp
*  Discrption : HCNetSDK Camera Driver. You can simply using this class by the
following way:

HKCamDriver m_HKCamDriver;
m_HKCamDriver.InitHKNetSDK();
m_HKCamDriver.InitCamera("xxx.xxx.xxx.xxx","usrname","psw");

This class support OpenCV. You can get IplImage form the CALLBACK
function DecCBFun.
But there remain have some problem need to be slove.
1. Software decode the video steam need too much CPU resource.
2. When we convert the yv12 to RGB, There need too much CPU
resource. If we use OpenCV, we can not avoid to convert the
yv12 to RGB.
3. CALLBACK function will be call every time, and we also get the
image data at the same time. There we have some multi-thread
problem to be solve.

*  Create     : 2017-7-10
*  Author     : Li Zhan, UESTC(University of Electronic Science and Technology of
China)
***************************************************************************************/

#include <windows.h>
#include "HKCamDriver.h"

HKCamDriver::HKCamDriver()
{
	/*  Create a mutex Lock when a object create */
}

HKCamDriver::~HKCamDriver() {
	
//	ReleaseCamera();
	ReleaseImage();
}

int HKCamDriver::ReleaseCamera(void)
{
	NET_DVR_Init();
	printf("stop, %ld\n", lUserID);

	if (!NET_DVR_StopRealPlay(lRealPlayHandle)) {
		printf("NET_DVR_StopRealPlay error! Error number: %d\n", NET_DVR_GetLastError());
		return 0;
	}

	NET_DVR_Logout(lUserID);
	NET_DVR_Cleanup();
	return 1;
}

int HKCamDriver::ReleaseImage()
{
	printf("release image");
	cvReleaseImage(pImg);
	cvReleaseImage(pImgYCrCb);
	return 1;
//	cvReleaseImage(&Ip);
}

void HKCamDriver::InitHKNetSDK(void)
{
	NET_DVR_Init();
	NET_DVR_SetConnectTime(200, 1);
	NET_DVR_SetReconnect(10000, true);

	for (int i = 0; i < MaxCameraNum; i++) {
		hMutex[i] = CreateMutex(NULL, FALSE, NULL);
		nPort[i] = -1;
		pImg[i] = NULL;
		pImgYCrCb[i] = NULL;
	}
	Scalefactor = 1.0f;

}

CamHandle HKCamDriver::InitCamera(char *sIP, char *UsrName, char *PsW, int Port)
{
	NET_DVR_DEVICEINFO_V30 struDeviceInfo;

	lUserID = NET_DVR_Login_V30(sIP, Port, UsrName, PsW, &struDeviceInfo);

//	printf("Login USERID, %ld\n", lUserID);

	if (lUserID < 0) {
		printf("Login error, %d\n", NET_DVR_GetLastError());
		NET_DVR_Cleanup();
		return -1;
	}

	NET_DVR_SetExceptionCallBack_V30(0, NULL, ExceptionCallBack, NULL);

	NET_DVR_CLIENTINFO ClientInfo;
	ClientInfo.lChannel = 1;                    /* Channel number Device channel number. */
	ClientInfo.hPlayWnd = NULL;                 /* Window is NULL                        */
	ClientInfo.lLinkMode = 0;                   /* Main Stream                           */
	ClientInfo.sMultiCastIP = NULL;

	lRealPlayHandle = NET_DVR_RealPlay_V30(lUserID, &ClientInfo, fRealDataCallBack, NULL, TRUE);

	if (lRealPlayHandle < 0)return 0;

	return lRealPlayHandle;
}

void CALLBACK  HKCamDriver::DecCBFun(long nPort, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, long nReserved1, long nReserved2)
{
	long lFrameType = pFrameInfo->nType;

	//printf("nport %ld\n", nPort);

	if (lFrameType == T_YV12)
	{
		
		WaitForSingleObject(hMutex[nPort], INFINITE);
		if (pImgYCrCb[nPort] == NULL) {
			pImgYCrCb[nPort] = cvCreateImage(cvSize(pFrameInfo->nWidth, pFrameInfo->nHeight), 8, 3);
		}
		if (pImg[nPort] == NULL) {
			pImg[nPort] = cvCreateImage(cvSize((int)(pFrameInfo->nWidth*Scalefactor), (int)(pFrameInfo->nHeight*Scalefactor)), 8, 3);
		}

		if (pBuf) {
			yv12toYUV(pImgYCrCb[nPort]->imageData, pBuf, pFrameInfo->nWidth,
				pFrameInfo->nHeight, pImgYCrCb[nPort]->widthStep);

			if (pImgYCrCb[nPort] && pImg[nPort])
			{

				cvResize(pImgYCrCb[nPort], pImg[nPort], CV_INTER_LINEAR);
				if (pImg[nPort])
				{
					cvCvtColor(pImg[nPort], pImg[nPort], CV_YCrCb2RGB);

					Ip = pImg[nPort];
					matIma[nPort] = cv::cvarrToMat(Ip);
				}

			}
		}

		
		
		
		ReleaseMutex(hMutex[nPort]);
	}
}

void CALLBACK  HKCamDriver::ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
	char tempbuf[256] = { 0 };
	switch (dwType)
	{
	case EXCEPTION_RECONNECT: 
		break;
	default:
		break;
	}
}

void HKCamDriver::yv12toYUV(char *outYuv, char *inYv12, int width, int height, int widthStep)
{
	int col, row;
	unsigned int Y, U, V;
	int tmp;
	int idx;
	for (row = 0; row<height; row++) {
		idx = row * widthStep;
		int rowptr = row*width;
		for (col = 0; col<width; col++) {
			tmp = (row / 2)*(width / 2) + (col / 2);
			Y = (unsigned int)inYv12[row*width + col];
			U = (unsigned int)inYv12[width*height + width*height / 4 + tmp];
			V = (unsigned int)inYv12[width*height + tmp];
			outYuv[idx + col * 3] = Y;
			outYuv[idx + col * 3 + 1] = U;
			outYuv[idx + col * 3 + 2] = V;
		}
	}
}
/*     Realtime Steam Callback           */
void CALLBACK HKCamDriver::fRealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser)
{
	DWORD dRet;
	DWORD CameraIndex = 0;

	CameraIndex = lRealHandle;
	//printf("lRealHandle = %ld\n", CameraIndex);
	switch (dwDataType)
	{
		/*  System Head    */
	case NET_DVR_SYSHEAD:
		if (!PlayM4_GetPort(&nPort[CameraIndex]))break;
		if (dwBufSize > 0) {
			if (!PlayM4_OpenStream(nPort[CameraIndex], pBuffer, dwBufSize, 1024 * 1024)) {
				dRet = PlayM4_GetLastError(nPort[CameraIndex]);
				break;
			}
			/* Setting the Decode function*/
			if (!PlayM4_SetDecCallBack(nPort[CameraIndex], DecCBFun)) {
				dRet = PlayM4_GetLastError(nPort[CameraIndex]);
				break;
			}
			if (!PlayM4_Play(nPort[CameraIndex], NULL)) {
				dRet = PlayM4_GetLastError(nPort[CameraIndex]);
				break;
			}
		}
		break;
		/* Code steam data    */
	case NET_DVR_STREAMDATA:
		if (dwBufSize > 0 && nPort[CameraIndex] != -1) {
			BOOL inData = PlayM4_InputData(nPort[CameraIndex], pBuffer, dwBufSize);
			while (!inData) {
				Sleep(10);
				inData = PlayM4_InputData(nPort[CameraIndex], pBuffer, dwBufSize);
			}
		}
		break;
	}
}

int HKCamDriver::GetCamMat(cv::Mat& Img, CamHandle handle, float factor)
{
	/*  Get the Port using handle    */
	int iPort = nPort[lRealPlayHandle];
	/*  Check the iPort is vaild     */
	if (iPort != -1) {
		WaitForSingleObject(hMutex[iPort], INFINITE);
		matIma[iPort].copyTo(Img);
		ReleaseMutex(hMutex[iPort]);	
		return 1;
	}
	/* If iPort is invaild, return
	empty                         */
	return 0;
}

QImage HKCamDriver::cvMat2QImage(const cv::Mat& mat)
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

void HKCamDriver::SetScaleFactor(float factor)
{
	Scalefactor = factor;
}


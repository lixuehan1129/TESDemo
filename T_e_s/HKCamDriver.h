#ifndef _HKCAMDRIVER_H_
#define _HKCAMDRIVER_H_


//#include "opencv2\opencv.hpp" 
#include "plaympeg4.h"  
#include "HCNetSDK.h" 
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>  

#include "QImage"


#define MaxCameraNum 6

typedef long CamHandle;  

static HANDLE hMutex[MaxCameraNum];

static long nPort[MaxCameraNum];

static IplImage* pImg[MaxCameraNum];
static IplImage* pImgYCrCb[MaxCameraNum];
static IplImage* Ip;
static cv::Mat matIma[MaxCameraNum];


static float Scalefactor;

class HKCamDriver {
public:

	HKCamDriver();

	~HKCamDriver();

	/*   Init the HKNetSDK, and the function only be using by
	once                                                  */
	void InitHKNetSDK(void);
	CamHandle InitCamera(char *sIP, char *UsrName, char *PsW, int Port = 8000);
	int ReleaseCamera(void);
	int ReleaseImage();
	int GetCamMat(cv::Mat &Img, CamHandle handle = NULL, float factor = 1.0f);
	QImage cvMat2QImage(const cv::Mat& mat);
	IplImage* GetCamImage(CamHandle handle, float factor = 1.0f);

	static void CALLBACK ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
	static void CALLBACK DecCBFun(long nPort, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, long nReserved1, long nReserved2);
	static void CALLBACK fRealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);

	static void SetScaleFactor(float factor);

	int RegistDevice(char *sIP, char *UsrName, char *PsW, int Port);

private:
	static void yv12toYUV(char *outYuv, char *inYv12, int width, int height, int widthStep);
	LONG lRealPlayHandle;
	LONG lUserID;

	
};
#endif
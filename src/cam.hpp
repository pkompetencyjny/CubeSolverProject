#ifndef CAM
#define CAM
#include "opencv2/opencv.hpp"

using namespace cv;
int camOpen()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
	namedWindow("Camera input", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("Camera input", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}

#endif
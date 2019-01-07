#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
int camOpen(int* endCameraThread)
{
	Mat frame;
	int fps=0;
	int limit = 30;
	double scale_value = 0.8;
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
	namedWindow("Camera input", 1);
	do
	{
		do {
			cap >> frame; // get a new frame from camera
			imshow("Camera input", frame);
			if (waitKey(limit) >= 0) break;
			fps++;
		} while (fps != limit);
		fps = 0;
		resize(frame, frame, cv::Size(), scale_value, scale_value);
		imwrite("frame.jpg", frame);
	} while (*(endCameraThread)!=1);
	return 0;
}
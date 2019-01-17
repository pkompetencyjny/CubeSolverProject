#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
int camOpen(bool* endCameraThread)
{
	Mat frame;
	int fps=0;
	int limit = 30;
	double scale_value = 0.8;
	VideoCapture cap(0); 
	if (!cap.isOpened())  
		return -1;
	namedWindow("Camera input", 1);
	do
	{
		do {
			cap >> frame; 
			imshow("Camera input", frame);
			if (waitKey(limit) >= 0) break;
			fps++;
		} while (fps != limit);
		fps = 0;
		resize(frame, frame, cv::Size(), scale_value, scale_value);
		imwrite("frame.jpg", frame);
	} while (!(*(endCameraThread)));
	return 0;
}
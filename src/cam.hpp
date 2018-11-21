#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
int camOpen()
{
	Mat frame;
	int fps=0;
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
	namedWindow("Camera input", 1);
	for (;;)
	{
		do {
			cap >> frame; // get a new frame from camera
			imshow("Camera input", frame);
			if (waitKey(30) >= 0) break;
			fps++;
		} while (fps != 30);
		fps = 0;
		resize(frame, frame, cv::Size(), 0.5, 0.5); // <-Do sprawdzenia czy dzia³a. //PRZECIE¯ SPRAWDZA£EŒ
		imwrite("frame.jpg", frame);
	}
	return 0;
}
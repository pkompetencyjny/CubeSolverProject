#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include<opencv\cv.hpp>
using namespace cv;

int main()
{
	Mat bgr = imread("../images/cvtest.png");

	Mat hsv;
	cv::cvtColor(bgr, hsv, COLOR_BGR2HSV);

	Mat mask1, mask2;
	inRange(hsv, Scalar(0, 70, 50), Scalar(10, 255, 255), mask1);
	inRange(hsv, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);

	Mat mask = mask1 | mask2;
	imshow("Sors", bgr);
	imshow("Mask", mask);
	waitKey();

	return 0;
}
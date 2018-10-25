#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include<opencv\cv.hpp>
using namespace cv;
/*
int main()
{
	char name[] = "../images/cubereal2.jpg";
	IplImage* src = cvLoadImage(name, 1);
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* copy2 = cvCreateImage(cvGetSize(src), 8, 3);
	CvScalar s, c, test;
		int g = 0, r = 0, b = 0, y = 0, w = 0, o=0;
		for (int i = 0; i < (src->height); i++)
		{
			for (int j = 0; j < (src->width); j++)
			{
				s = cvGet2D(src, i, j);
				if (s.val[2]<40 && s.val[1]>130 && s.val[0]<60)
				{
					g++;
					c.val[2] = 0;
					c.val[1] = 255;
					c.val[0] = 0;
					cvSet2D(copy, i, j, c);
				}
				else  if ((s.val[2] > 185) && (s.val[1] < 95) && (s.val[0] < 80))
				{
					r++;
					c.val[2] = 255;
					c.val[1] = 0;
					c.val[0] = 0;
					cvSet2D(copy, i, j, c);
				}
				else if ((s.val[2] < 60) && (s.val[1] < 150) && (s.val[0] > 120))
				{
					b++;
					c.val[2] = 0;
					c.val[1] = 0;
					c.val[0] = 255;
					cvSet2D(copy, i, j, c);
				}
				else if ((s.val[2] > 200) && (s.val[1] > 200) && (s.val[0] < 100))
				{
					y++;
					c.val[2] = 255;
					c.val[1] = 255;
					c.val[0] = 0;
					cvSet2D(copy, i, j, c);
				}
				else if ((s.val[2] > 200) && (s.val[1] > 200) && (s.val[0] > 200))
				{
					w++;
					c.val[2] = 255;
					c.val[1] = 255;
					c.val[0] = 255;
					cvSet2D(copy, i, j, c);
				}
				else if ((s.val[2] > 230) && (s.val[1] > 100) && (s.val[0] < 90))
				{
					o++;
					c.val[2] = 255;
					c.val[1] = 162;
					c.val[0] = 74;
					cvSet2D(copy, i, j, c);
				}
				else {
					c.val[2] = 0;
					c.val[1] = 0;
					c.val[0] = 0;
					cvSet2D(copy, i, j, c);
				}

			}
		}
		std::cout<< "Green:" << g <<std::endl;
		std::cout<< "Red:" << r <<std::endl;
		std::cout << "Blue:" << b << std::endl;
		std::cout << "Yellow:" << y << std::endl;
		std::cout << "white:" << w << std::endl;
		std::cout << "orange:" << o << std::endl;

cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
cvShowImage("Input", src);
cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
cvShowImage("Output", copy);
waitKey();
cvReleaseImage(&src);
	return 0;
}
*/
int main()
{
	Mat cube = imread("../images/cubereal2.jpg", 0);
	Mat outerBox = Mat(cube.size(), CV_8UC1);
	GaussianBlur(cube, cube, Size(11, 11), 0);
	adaptiveThreshold(cube, outerBox, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 2);
	bitwise_not(outerBox, outerBox);
	Mat kernel = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);
	dilate(outerBox, outerBox, kernel);
	int count = 0;
	int max = -1;

	Point maxPt;

	for (int y = 0; y < outerBox.size().height; y++)
	{
		uchar *row = outerBox.ptr(y);
		for (int x = 0; x < outerBox.size().width; x++)
		{
			if (row[x] >= 128)
			{

				int area = floodFill(outerBox, Point(x, y), CV_RGB(0, 0, 64));

				if (area > max)
				{
					maxPt = Point(x, y);
					max = area;
				}
			}
		}

	}
	floodFill(outerBox, maxPt, CV_RGB(255, 255, 255));
	for (int y = 0; y < outerBox.size().height; y++)
	{
		uchar *row = outerBox.ptr(y);
		for (int x = 0; x < outerBox.size().width; x++)
		{
			if (row[x] == 64 && x != maxPt.x && y != maxPt.y)
			{
				int area = floodFill(outerBox, Point(x, y), CV_RGB(0, 0, 0));
			}
		}
	}
	erode(outerBox, outerBox, kernel);
	imshow("cube", outerBox);
	waitKey(0);
	return 0;
}
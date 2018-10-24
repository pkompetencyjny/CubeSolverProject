#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include<opencv\cv.hpp>
using namespace cv;

int main()
{
	char name[] = "../images/cubereal2.jpg";
	IplImage* src = cvLoadImage(name, 1);
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3);
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
		/*switch (liczba) {
		case 1:

			for (int i = 0; i < (src->height); i++)
			{
				for (int j = 0; j < (src->width); j++)
				{
					s = cvGet2D(src, i, j);
					if ((s.val[2] < 50) && (s.val[1] > 100) && (s.val[0] < 100))
					{
						c.val[2] = 0;
						c.val[1] = 255;
						c.val[0] = 0;
						cvSet2D(copy, i, j, c);
					}
					else
					{
						c.val[2] = 0; // Red
						c.val[1] = 0;// Green
						c.val[0] = 0;// Blue
						cvSet2D(copy, i, j, c);
					}
				}

			}

			std::cout << "Znaleziony kolor to zielony";
			cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
			cvShowImage("Output", copy);
			waitKey();
			cvReleaseImage(&src);
			break;

		case 2:

			for (int i = 0; i < (src->height); i++)
			{
				for (int j = 0; j < (src->width); j++)
				{
					s = cvGet2D(src, i, j);
					if ((s.val[2] > 180) && (s.val[1] < 100) && (s.val[0] < 80))
					{
						c.val[2] = 223;
						c.val[1] = 81;
						c.val[0] = 61;
						cvSet2D(copy, i, j, c);
					}
					else
					{
						c.val[2] = 0; // Red
						c.val[1] = 0;// Green
						c.val[0] = 0;// Blue
						cvSet2D(copy, i, j, c);
					}
				}

			}

			std::cout << "Znaleziony kolor to czerwony";
			cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
			cvShowImage("Output", copy);
			waitKey();
			cvReleaseImage(&src);
			break;

		case 3:

			for (int i = 0; i < (src->height); i++)
			{
				for (int j = 0; j < (src->width); j++)
				{
					s = cvGet2D(src, i, j);
					if ((s.val[2] < 60) && (s.val[1] < 150) && (s.val[0] > 120))
					{
						c.val[2] = 44;
						c.val[1] = 97;
						c.val[0] = 151;
						cvSet2D(copy, i, j, c);
					}
					else
					{
						c.val[2] = 0;
						c.val[1] = 0;
						c.val[0] = 0;
						cvSet2D(copy, i, j, c);
					}
				}

			}

			std::cout << "Znaleziony kolor to niebieski";
			cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
			cvShowImage("Output", copy);
			waitKey();
			cvReleaseImage(&src);
			break;

		case 4:

			for (int i = 0; i < (src->height); i++)
			{
				for (int j = 0; j < (src->width); j++)
				{
					s = cvGet2D(src, i, j);
					if ((s.val[2] > 200) && (s.val[1] > 200) && (s.val[0] < 100))
					{
						c.val[2] = 255;
						c.val[1] = 255;
						c.val[0] = 0;
						cvSet2D(copy, i, j, c);
					}
					else
					{
						c.val[2] = 0;
						c.val[1] = 0;
						c.val[0] = 0;
						cvSet2D(copy, i, j, c);
					}
				}

			}

			std::cout << "Znaleziony kolor to zolty";
			cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
			cvShowImage("Output", copy);
			waitKey();
			cvReleaseImage(&src);
			break;

		}*/
cvNamedWindow("Input", CV_WINDOW_KEEPRATIO);
cvShowImage("Input", src);
cvNamedWindow("Output", CV_WINDOW_KEEPRATIO);
cvShowImage("Output", copy);
waitKey();
cvReleaseImage(&src);
	return 0;
}
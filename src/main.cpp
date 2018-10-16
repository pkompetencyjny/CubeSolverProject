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
	CvScalar s, c;
	int liczba;
		std::cout << "Podaj liczbe";
		std::cin >> liczba;
		switch (liczba) {
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
						c.val[2] = 255; // Red
						c.val[1] = 255;// Green
						c.val[0] = 255;// Blue
						cvSet2D(copy, i, j, c);
					}
				}

			}


			std::cout << "Znaleziony kolor to zielony";
			cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
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
						c.val[2] = 223;//Set R to 0
						c.val[1] = 81;//Set G to 255
						c.val[0] = 61;//Set B to 0
						cvSet2D(copy, i, j, c);
					}
					else
					{
						c.val[2] = 255; // Red
						c.val[1] = 255;// Green
						c.val[0] = 255;// Blue
						cvSet2D(copy, i, j, c);
					}
				}

			}


			std::cout << "Znaleziony kolor to czerwony";
			cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
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
						c.val[2] = 255;
						c.val[1] = 255;
						c.val[0] = 255;
						cvSet2D(copy, i, j, c);
					}
				}

			}


			std::cout << "Znaleziony kolor to niebieski";
			cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
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
						c.val[2] = 255;
						c.val[1] = 255;
						c.val[0] = 255;
						cvSet2D(copy, i, j, c);
					}
				}

			}


			std::cout << "Znaleziony kolor to zolty";
			cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
			cvShowImage("Input", src);
			cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
			cvShowImage("Output", copy);
			waitKey();
			cvReleaseImage(&src);
			break;


		}


	return 0;
}
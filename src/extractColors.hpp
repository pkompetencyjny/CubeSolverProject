#pragma once
#include <opencv\cv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "maxind.hpp"

using namespace cv;

void extractColors(Mat croppedImage)
{
	GaussianBlur(croppedImage, croppedImage, Size(5, 5), 0);
	IplImage* src = cvCloneImage(&(IplImage)croppedImage);
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3);
	IplImage* hsvsrc = cvCreateImage(cvGetSize(src), 8, 3);
	cvCvtColor(src, hsvsrc, CV_BGR2HSV);

	int g = 0, r = 0, b = 0, y = 0, w = 0, o = 0;
	std::vector < int > kolor1(7, 0);
	std::vector < int > kolor2(7, 0);
	std::vector < int > kolor3(7, 0);
	std::vector < int > kolor4(7, 0);
	std::vector < int > kolor5(7, 0);
	std::vector < int > kolor6(7, 0);
	std::vector < int > kolor7(7, 0);
	std::vector < int > kolor8(7, 0);
	std::vector < int > kolor9(7, 0);

	IplImage* copy2 = cvCreateImage(Size(384, 384), 8, 3);

	IplImage* copy3 = cvCreateImage(cvGetSize(src), 8, 3);

	CvScalar s, c, test;


	for (int i = 0; i < (src->height); i++)
	{
		for (int j = 0; j < (src->width); j++)
		{
			s = cvGet2D(hsvsrc, i, j);
			if (s.val[0] > 35 && s.val[0] < 80 && s.val[1] > 92)
			{
				g++;
				c.val[2] = 0;
				c.val[1] = 255;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[1]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[1]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[1]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[1]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[1]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[1]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[1]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[1]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[1]++;
				}
			}
			else if (s.val[0] > 22 && s.val[0] < 34 && s.val[1] > 91)
			{
				y++;
				c.val[2] = 255;
				c.val[1] = 255;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[4]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[4]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[4]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[4]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[4]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[4]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[4]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[4]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[4]++;
				}
			}

			else if (s.val[0] > 8 && s.val[0] < 18 && s.val[1] > 92)
			{
				o++;
				c.val[2] = 255;
				c.val[1] = 162;
				c.val[0] = 74;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[6]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[6]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[6]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[6]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[6]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[6]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[6]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[6]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[6]++;
				}
			}
			else if ((s.val[0] >= 0 && s.val[0] < 8 && s.val[1] > 91) || (s.val[0] > 150 && s.val[0] < 180 && s.val[1] > 91))
			{
				r++;
				c.val[2] = 255;
				c.val[1] = 0;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[2]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[2]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[2]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[2]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[2]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[2]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[2]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[2]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[2]++;
				}
			}
			else if (s.val[0] > 80 && s.val[0] < 150 && s.val[1] > 92)
			{
				b++;
				c.val[2] = 0;
				c.val[1] = 0;
				c.val[0] = 255;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[3]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[3]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[3]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[3]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[3]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[3]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[3]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[3]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[3]++;
				}
			}
			else if (s.val[1] >= 0 && s.val[1] < 91 && s.val[2] > 100 && s.val[2] < 255)
			{
				w++;
				c.val[2] = 255;
				c.val[1] = 255;
				c.val[0] = 255;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor1[5]++;
				}
				if (i > 0 && i < (src->height) / 3 && j >(src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor2[5]++;
				}
				if (i > 0 && i < (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor3[5]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor4[5]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor5[5]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor6[5]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j < (src->width) / 3 && j >0)
				{
					kolor7[5]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > (src->width) / 3 && j < 2 * (src->width) / 3)
				{
					kolor8[5]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3 && j > 2 * (src->width) / 3 && j < (src->width))
				{
					kolor9[5]++;
				}
			}
			else {
				c.val[2] = 0;
				c.val[1] = 0;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
			}

		}
	}
	//Rysowanie wirtualnej kostki
	int kolor1_max = maxind(kolor1);
	int kolor2_max = maxind(kolor2);
	int kolor3_max = maxind(kolor3);
	int kolor4_max = maxind(kolor4);
	int kolor5_max = maxind(kolor5);
	int kolor6_max = maxind(kolor6);
	int kolor7_max = maxind(kolor7);
	int kolor8_max = maxind(kolor8);
	int kolor9_max = maxind(kolor9);

	if (kolor1_max == 1) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(0, 255, 0), -1); }
	else if (kolor1_max == 2) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 0, 0), -1); }
	else if (kolor1_max == 3) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(0, 0, 255), -1); }
	else if (kolor1_max == 4) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 255, 0), -1); }
	else if (kolor1_max == 5) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 255, 255), -1); }
	else if (kolor1_max == 6) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 162, 74), -1); }

	if (kolor2_max == 1) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(0, 255, 0), -1); }
	else if (kolor2_max == 2) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 0, 0), -1); }
	else if (kolor2_max == 3) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(0, 0, 255), -1); }
	else if (kolor2_max == 4) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 255, 0), -1); }
	else if (kolor2_max == 5) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 255, 255), -1); }
	else if (kolor2_max == 6) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 162, 74), -1); }

	if (kolor3_max == 1) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(0, 255, 0), -1); }
	else if (kolor3_max == 2) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 0, 0), -1); }
	else if (kolor3_max == 3) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(0, 0, 255), -1); }
	else if (kolor3_max == 4) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 255, 0), -1); }
	else if (kolor3_max == 5) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 255, 255), -1); }
	else if (kolor3_max == 6) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 162, 74), -1); }

	if (kolor4_max == 1) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(0, 255, 0), -1); }
	else if (kolor4_max == 2) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 0, 0), -1); }
	else if (kolor4_max == 3) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(0, 0, 255), -1); }
	else if (kolor4_max == 4) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 255, 0), -1); }
	else if (kolor4_max == 5) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 255, 255), -1); }
	else if (kolor4_max == 6) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 162, 74), -1); }

	if (kolor5_max == 1) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(0, 255, 0), -1); }
	else if (kolor5_max == 2) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 0, 0), -1); }
	else if (kolor5_max == 3) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(0, 0, 255), -1); }
	else if (kolor5_max == 4) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 255, 0), -1); }
	else if (kolor5_max == 5) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 255, 255), -1); }
	else if (kolor5_max == 6) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 162, 74), -1); }

	if (kolor6_max == 1) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(0, 255, 0), -1); }
	else if (kolor6_max == 2) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 0, 0), -1); }
	else if (kolor6_max == 3) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(0, 0, 255), -1); }
	else if (kolor6_max == 4) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 255, 0), -1); }
	else if (kolor6_max == 5) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 255, 255), -1); }
	else if (kolor6_max == 6) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 162, 74), -1); }

	if (kolor7_max == 1) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(0, 255, 0), -1); }
	else if (kolor7_max == 2) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 0, 0), -1); }
	else if (kolor7_max == 3) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(0, 0, 255), -1); }
	else if (kolor7_max == 4) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 255, 0), -1); }
	else if (kolor7_max == 5) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 255, 255), -1); }
	else if (kolor7_max == 6) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 162, 74), -1); }

	if (kolor8_max == 1) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(0, 255, 0), -1); }
	else if (kolor8_max == 2) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 0, 0), -1); }
	else if (kolor8_max == 3) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(0, 0, 255), -1); }
	else if (kolor8_max == 4) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 255, 0), -1); }
	else if (kolor8_max == 5) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 255, 255), -1); }
	else if (kolor8_max == 6) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 162, 74), -1); }

	if (kolor9_max == 1) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(0, 255, 0), -1); }
	else if (kolor9_max == 2) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 0, 0), -1); }
	else if (kolor9_max == 3) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(0, 0, 255), -1); }
	else if (kolor9_max == 4) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 255, 0), -1); }
	else if (kolor9_max == 5) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 255, 255), -1); }
	else if (kolor9_max == 6) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 162, 74), -1); }

	cvNamedWindow("Output 2");
	cvShowImage("Output 2", copy2);

	cvReleaseImage(&src);
}

//TA FUNKCJA MA ZWRÓCIÆ char tab[9];
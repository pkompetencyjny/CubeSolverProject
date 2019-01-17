#include "ExtractColors.hpp"
#include "Utils.hpp"

using namespace cv;

ExtractColors::ExtractColors(Mat croppedImage)
{
	GaussianBlur(croppedImage, croppedImage, Size(5, 5), 0);
	src = cvCloneImage(&(IplImage)croppedImage);
	copy = cvCreateImage(cvGetSize(src), 8, 3);
	hsvsrc = cvCreateImage(cvGetSize(src), 8, 3);
	cvCvtColor(src, hsvsrc, CV_BGR2HSV);

	int g = 0, r = 0, b = 0, y = 0, w = 0, o = 0;
	color0 = std::vector < int >(7, 0);
	color1 = std::vector < int >(7, 0);
	color2 = std::vector < int >(7, 0);
	color3 = std::vector < int >(7, 0);
	color4 = std::vector < int >(7, 0);
	color5 = std::vector < int >(7, 0);
	color6 = std::vector < int >(7, 0);
	color7 = std::vector < int >(7, 0);
	color8 = std::vector < int >(7, 0);

	copy2 = cvCreateImage(Size(384, 384), 8, 3);

	copy3 = cvCreateImage(cvGetSize(src), 8, 3);

	CvScalar s, c, test;


	for (int i = 0; i < (src->height); i++)
	{
		for (int j = 0; j < (src->width); j++)
		{
			s = cvGet2D(hsvsrc, i, j);
			if (s.val[0] > 46 && s.val[0] < 99 && s.val[1] >= 50)
			{
				g++;
				c.val[2] = 0;
				c.val[1] = 255;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[1]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[1]++;
					else
						color2[1]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[1]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[1]++;
					else
						color5[1]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[1]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[1]++;
					else
						color8[1]++;
				}
			}
			else if (s.val[0] >= 22 && s.val[0] < 45 && s.val[1] >= 50)
			{
				y++;
				c.val[2] = 255;
				c.val[1] = 255;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[4]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[4]++;
					else
						color2[4]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[4]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[4]++;
					else
						color5[4]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[4]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[4]++;
					else
						color8[4]++;
				}
			}

			else if (s.val[0] >= 8 && s.val[0] < 22 && s.val[1] >= 50)
			{
				o++;
				c.val[2] = 255;
				c.val[1] = 162;
				c.val[0] = 74;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[6]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[6]++;
					else
						color2[6]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[6]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[6]++;
					else
						color5[6]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[6]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[6]++;
					else
						color8[6]++;
				}
			}
			else if ((s.val[0] >= 0 && s.val[0] <= 8 && s.val[1] >= 50) || (s.val[0] >= 151 && s.val[0] <= 180 && s.val[1] >= 50))
			{
				r++;
				c.val[2] = 255;
				c.val[1] = 0;
				c.val[0] = 0;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[2]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[2]++;
					else
						color2[2]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[2]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[2]++;
					else
						color5[2]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[2]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[2]++;
					else
						color8[2]++;
				}
			}
			else if (s.val[0] >= 99 && s.val[0] < 150 && s.val[1] >= 50)
			{
				b++;
				c.val[2] = 0;
				c.val[1] = 0;
				c.val[0] = 255;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[3]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[3]++;
					else 
						color2[3]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[3]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[3]++;
					else 
						color5[3]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[3]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[3]++;
					else
						color8[3]++;
				}
			}
			else if (s.val[1] >= 0 && s.val[1] < 50)
			{
				w++;
				c.val[2] = 255;
				c.val[1] = 255;
				c.val[0] = 255;
				cvSet2D(copy, i, j, c);
				if (i > 0 && i < (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color0[5]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color1[5]++;
					else 
						color2[5]++;
				}
				if (i < 2 * (src->height) / 3 && i >(src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color3[5]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color4[5]++;
					else
						color5[5]++;
				}
				if (i < (src->height) && i > 2 * (src->height) / 3) {
					if (j < (src->width) / 3 && j >0)
						color6[5]++;
					else if (j > (src->width) / 3 && j < 2 * (src->width) / 3)
						color7[5]++;
					else
						color8[5]++;
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
}
	std::vector <char> ExtractColors::stateOfCube() {
	Utils utils = Utils();
	static char cube_element[9];
	int color[9];
	color[0] = utils.Maxind(color0);
	color[1] = utils.Maxind(color1);
	color[2] = utils.Maxind(color2);
	color[3] = utils.Maxind(color3);
	color[4] = utils.Maxind(color4);
	color[5] = utils.Maxind(color5);
	color[6] = utils.Maxind(color6);
	color[7] = utils.Maxind(color7);
	color[8] = utils.Maxind(color8);

	if (color[0] == 1) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(0, 255, 0), -1);  cube_element[0] = 'g'; }
	else if (color[0] == 2) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 0, 0), -1);  cube_element[0] = 'r'; }
	else if (color[0] == 3) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(0, 0, 255), -1);  cube_element[0] = 'b'; }
	else if (color[0] == 4) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 255, 0), -1);  cube_element[0] = 'y'; }
	else if (color[0] == 5) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 255, 255), -1); cube_element[0] = 'w'; }
	else if (color[0] == 6) { cvRectangle(copy2, Point(0, 0), Point(128, 128), CV_RGB(255, 162, 74), -1); cube_element[0] = 'o'; };

	if (color[1] == 1) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(0, 255, 0), -1); cube_element[1] = 'g'; }
	else if (color[1] == 2) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 0, 0), -1); cube_element[1] = 'r'; }
	else if (color[1] == 3) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(0, 0, 255), -1); cube_element[1] = 'b'; }
	else if (color[1] == 4) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 255, 0), -1); cube_element[1] = 'y'; }
	else if (color[1] == 5) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 255, 255), -1); cube_element[1] = 'w'; }
	else if (color[1] == 6) { cvRectangle(copy2, Point(128, 0), Point(256, 128), CV_RGB(255, 162, 74), -1); cube_element[1] = 'o'; }

	if (color[2] == 1) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(0, 255, 0), -1); cube_element[2] = 'g'; }
	else if (color[2] == 2) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 0, 0), -1); cube_element[2] = 'r'; }
	else if (color[2] == 3) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(0, 0, 255), -1); cube_element[2] = 'b'; }
	else if (color[2] == 4) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 255, 0), -1); cube_element[2] = 'y'; }
	else if (color[2] == 5) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 255, 255), -1); cube_element[2] = 'w'; }
	else if (color[2] == 6) { cvRectangle(copy2, Point(256, 0), Point(384, 128), CV_RGB(255, 162, 74), -1); cube_element[2] = 'o'; }

	if (color[3] == 1) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(0, 255, 0), -1); cube_element[3] = 'g'; }
	else if (color[3] == 2) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 0, 0), -1); cube_element[3] = 'r'; }
	else if (color[3] == 3) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(0, 0, 255), -1); cube_element[3] = 'b'; }
	else if (color[3] == 4) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 255, 0), -1); cube_element[3] = 'y'; }
	else if (color[3] == 5) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 255, 255), -1); cube_element[3] = 'w'; }
	else if (color[3] == 6) { cvRectangle(copy2, Point(0, 128), Point(128, 256), CV_RGB(255, 162, 74), -1); cube_element[3] = 'o'; }

	if (color[4] == 1) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(0, 255, 0), -1); cube_element[4] = 'g'; }
	else if (color[4] == 2) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 0, 0), -1); cube_element[4] = 'r'; }
	else if (color[4] == 3) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(0, 0, 255), -1); cube_element[4] = 'b'; }
	else if (color[4] == 4) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 255, 0), -1); cube_element[4] = 'y'; }
	else if (color[4] == 5) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 255, 255), -1); cube_element[4] = 'w'; }
	else if (color[4] == 6) { cvRectangle(copy2, Point(128, 128), Point(256, 256), CV_RGB(255, 162, 74), -1); cube_element[4] = 'o'; }

	if (color[5] == 1) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(0, 255, 0), -1); cube_element[5] = 'g'; }
	else if (color[5] == 2) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 0, 0), -1); cube_element[5] = 'r'; }
	else if (color[5] == 3) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(0, 0, 255), -1); cube_element[5] = 'b'; }
	else if (color[5] == 4) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 255, 0), -1); cube_element[5] = 'y'; }
	else if (color[5] == 5) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 255, 255), -1); cube_element[5] = 'w'; }
	else if (color[5] == 6) { cvRectangle(copy2, Point(256, 128), Point(384, 256), CV_RGB(255, 162, 74), -1); cube_element[5] = 'o'; }

	if (color[6] == 1) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(0, 255, 0), -1); cube_element[6] = 'g'; }
	else if (color[6] == 2) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 0, 0), -1); cube_element[6] = 'r'; }
	else if (color[6] == 3) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(0, 0, 255), -1); cube_element[6] = 'b'; }
	else if (color[6] == 4) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 255, 0), -1); cube_element[6] = 'y'; }
	else if (color[6] == 5) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 255, 255), -1); cube_element[6] = 'w'; }
	else if (color[6] == 6) { cvRectangle(copy2, Point(0, 256), Point(128, 384), CV_RGB(255, 162, 74), -1); cube_element[6] = 'o'; }

	if (color[7] == 1) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(0, 255, 0), -1); cube_element[7] = 'g'; }
	else if (color[7] == 2) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 0, 0), -1); cube_element[7] = 'r'; }
	else if (color[7] == 3) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(0, 0, 255), -1); cube_element[7] = 'b'; }
	else if (color[7] == 4) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 255, 0), -1); cube_element[7] = 'y'; }
	else if (color[7] == 5) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 255, 255), -1); cube_element[7] = 'w'; }
	else if (color[7] == 6) { cvRectangle(copy2, Point(128, 256), Point(256, 384), CV_RGB(255, 162, 74), -1); cube_element[7] = 'o'; }

	if (color[8] == 1) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(0, 255, 0), -1); cube_element[8] = 'g'; }
	else if (color[8] == 2) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 0, 0), -1); cube_element[8] = 'r'; }
	else if (color[8] == 3) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(0, 0, 255), -1); cube_element[8] = 'b'; }
	else if (color[8] == 4) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 255, 0), -1); cube_element[8] = 'y'; }
	else if (color[8] == 5) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 255, 255), -1); cube_element[8] = 'w'; }
	else if (color[8] == 6) { cvRectangle(copy2, Point(256, 256), Point(384, 384), CV_RGB(255, 162, 74), -1); cube_element[8] = 'o'; }
	
	cvNamedWindow("Output 2");
	cvShowImage("Output 2", copy2);
	waitKey(1000);
	cvReleaseImage(&src);
	std::vector<char> cube_element_vector(cube_element, cube_element + sizeof cube_element / sizeof cube_element[0]);
	return cube_element_vector;
}

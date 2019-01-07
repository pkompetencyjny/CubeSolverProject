#pragma once
#include <opencv\cv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>

using namespace cv;

class extractColors 
{
private:
	IplImage* src;
	IplImage* copy;
	IplImage* hsvsrc;
	IplImage* copy2;
	IplImage* copy3;

	std::vector < int >color0, color1, color2, color3, color4, color5, color6, color7, color8;
public:
	extractColors(Mat croppedImage);
	std::vector <char> stateOfCube();

};
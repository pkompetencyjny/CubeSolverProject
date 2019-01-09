#define CVUI_IMPLEMENTATION
#include "cvui.h"
#include <iostream>
#include <thread>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "cam.hpp"
#include "vision.hpp"
#include "CubeSolver.hpp"
#include <cstdlib>
#include <opencv2/opencv.hpp>

#define WINDOW_NAME "CubeSolver"

int main(int argc, const char *argv[])
{
	cv::Mat frame = cv::Mat(100, 220, CV_8UC3);
	int count = 0;
	cvui::init(WINDOW_NAME);

	while (true) {
		frame = cv::Scalar(49, 52, 49);

		cvui::printf(frame, 20, 20, 0.4, 0xffffff, "Czy stan kostki sie zgadza?");
		if (cvui::button(frame, 40, 50, "Tak")) {		
			count++;
		}
		if (cvui::button(frame, 100, 50, "Nie!")) {
			count++;
		}

		cvui::imshow(WINDOW_NAME, frame);
		if (cv::waitKey(20) == 27) {
			break;
		}
	}
	return 0;
}
/*int main()
{
	int endCameraThread = 0;
	std::thread camThread(&camOpen,&endCameraThread);
	std::vector<char> cube_face[6];
	int count_of_faces = 6;
	int count_of_elements = 9;
	char yesNo='n';
	std::system("CLS");
	std::cout << "Wcisnij enter aby rozpoczac..." << std::endl;
	if (std::getchar())
	{
		for (int i = 0; i < count_of_faces; i++)
		{
			do {
				cube_face[i] = vision();
				for(int j=0;j<count_of_elements;j++) std::cout << cube_face[i][j];
				std::cout << "Czy stan sciany nr:"<<i+1<<" sie zgadza?(t/n)" << std::endl;
				std::cin >> yesNo;
			} while (yesNo != 't');
			yesNo = 'n';
		}
		endCameraThread = 1;
		CubeSolver cube = CubeSolver(cube_face);
		cube.solution();
		return 0;
	}
}*/
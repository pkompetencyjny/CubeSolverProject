#include <iostream>
#include <thread>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "cam.hpp"
#include "vision.hpp"
#include "CubeSolver.hpp"
#include <cstdlib>


int main()
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
}

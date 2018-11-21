#include <iostream>
#include <thread>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "cam.hpp"
#include "vision.hpp"
#include "CubeSolver.cpp"
#include <cstdlib>

int main()
{
	std::thread camThread(&camOpen);
	char * stanKostki[6][9];
	int j = 0;
	char takNie='n';
	std::system("CLS");
	std::cout << "Wcisnij enter aby rozpoczac..." << std::endl;
	if (std::getchar())
	{
		for (int i = 0; i < 6; i++)
		{
			do {
				stanKostki[i][j] = vision();
				std::cout << "Czy stan sciany nr:"<<i+1<<" sie zgadza?(t/n)" << std::endl;
				std::cin >> takNie;
			} while (takNie != 't');
			j += 9;
			takNie = 'n';
		}
		CubeSolver cube = CubeSolver(stanKostki);
		cube.solution();
		return 0;
	}
}

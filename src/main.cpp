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
	std::vector<char> stanKostki[6];
	int j = 0;
	char takNie='n';
	std::system("CLS");
	std::cout << "Wcisnij enter aby rozpoczac..." << std::endl;
	if (std::getchar())
	{
		for (int i = 0; i < 6; i++)
		{
			do {
				stanKostki[i] = vision();
				for(j=0;j<9;j++) std::cout << stanKostki[i][j];
				std::cout << "Czy stan sciany nr:"<<i+1<<" sie zgadza?(t/n)" << std::endl;
				std::cin >> takNie;
			} while (takNie != 't');
			takNie = 'n';
		}
		CubeSolver cube = CubeSolver(stanKostki);
		cube.solution();
		return 0;
	}
}

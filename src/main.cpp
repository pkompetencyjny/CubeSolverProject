#include <iostream>
#include <thread>
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
	int takNie;
	std::system("CLS");
	if (std::getchar())
	{
		for (int i = 0; i < 6; i++)
		{
			do {
				stanKostki[i][j] = vision();
				std::cout << "Czy stan kostki siê zgadza?" << std::endl;
				std::cin >> takNie;
			} while (takNie == 1/* czy jakiœ inny true*/);
			//}
			j += 9;
		}
		CubeSolver cube = CubeSolver(stanKostki);
		cube.solution();
		return 0;
	}
}

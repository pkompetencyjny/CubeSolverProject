#include <iostream>
#include <thread>
#include "cam.hpp"
#include "vision.hpp"
#include "CubeSolver.cpp"

int main()
{
	//kamera
	std::thread camThread(&camOpen);
	camThread.join();
	char * stanKostki[6][9];
	int j = 0;
	int takNie;
	if (getchar() == 1) //warunek jakiœ
	{
		for (int i = 0; i < 6; i++)
		{
			do {
				stanKostki[i][j] = vision(); //musi byæ odpalone 6 razy. char vision[9]
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

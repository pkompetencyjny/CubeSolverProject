#include <iostream>
#include <thread>
#include "cam.hpp"
#include "vision.hpp"

int main()
{
	//kamera
	std::thread camThread(&camOpen);
	camThread.join();
	/*char stanKostki[6][9];
	if (getchar() == 1) //warunek jakiœ
	{
		for (int i = 0; i < 6; i++)
		{
			do {

				stanKostki[i] = vision(); //musi byæ odpalone 6 razy. char vision[9]
				std::cout << "Czy stan kostki siê zgadza?" << endl;
				std::cin >> takNie;
			} while (takNie == 1 czy jakiœ inny true);
		}
	}
	CubeSolver(stanKostki);
	*/
	return 0;
}
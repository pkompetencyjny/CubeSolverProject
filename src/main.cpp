#include <iostream>
#include <thread>
#include "cam.hpp"
#include "vision.hpp"


int main()
{
	std::thread camThread(&camOpen);
	getchar();
	std::thread visionThread(&vision);
	camThread.join();
	return 0;
}
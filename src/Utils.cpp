#include "Utils.hpp"

Utils::Utils()
{
}

int Utils::Maxind(std::vector<int> v)
{
	int maxind = 0, max = 0, i = 0;
	for (i = 0; i < 7; i++)
	{
		if (v[i] > max)
		{
			max = v[i];
			maxind = i;
		}
	}
	return maxind;
}

double Utils::toRadians(int angle)
{
	return CV_PI * angle / 180;
}


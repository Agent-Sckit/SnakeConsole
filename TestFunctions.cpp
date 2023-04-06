#include "TestFunctions.h"

void PrintCharList()
{
	char characterSample{};
	for (int i{}; i < 255; i++)
	{
		characterSample = i;
		std::cout << i << " " << characterSample << std::endl;
	}
}
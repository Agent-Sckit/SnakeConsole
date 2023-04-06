#include "Pixel.h"
#include <iostream>

Pixel::Pixel(char character) : pixel{ character }
{
	std::cout << "Pixel Constructor 1 Called" << std::endl;
}

Pixel::Pixel()
{
	std::cout << "Default Pixel Constructor Called" << std::endl;
}

char Pixel::GetPixel()
{
	return pixel;
}

Pixel::~Pixel()
{
	std::cout << "Pixel Destructor Called" << std::endl;
}
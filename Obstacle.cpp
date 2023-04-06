#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle() : Pixel{static_cast<char>(219)}
{
	std::cout << "Obstacle Character: " << pixel << std::endl;
}

Obstacle::~Obstacle()
{
	std::cout << "Obstacle Destructor Called" << std::endl;
}

void Obstacle::SpawnPixel()
{
	std::cout << "Spawning Pixel Object";
	Pixel PixelObject;
}
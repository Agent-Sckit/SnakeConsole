#include <iostream>
#include "Game.h"
#include "SnakeConsoleFunctions.h"
#include "Obstacle.h"
#include "Pixel.h"


int main()
{
	Game gameObject;
	gameObject.Init();
	gameObject.Run();
	
	std::cin.get();
	return 0;
}
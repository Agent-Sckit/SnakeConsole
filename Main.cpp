#include "TestFunctions.h"
#include "Game.h"
#include "SnakeConsoleFunctions.h"
#include "Obstacle.h"
#include "Pixel.h"


int main()
{
	PrintCharList();

	Game gameObject;
	gameObject.Init();
	gameObject.Run();
	
	return 0;
}
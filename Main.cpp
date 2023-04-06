#include <iostream>
#include "Game.h"
#include "SnakeConsoleFunctions.h"
#include "Obstacle.h"
#include "Pixel.h"


int main()
{
	char characterSample{};
	for (int i{}; i < 255; i++)
	{
		characterSample = i;
		std::cout << i << " " << characterSample << std::endl;
	}
	
	Game gameObject;
	gameObject.Init();
	gameObject.Run();
	
	
	
	//while (true)
	//{
	//	if (std::chrono::steady_clock::now() - endTime > std::chrono::seconds(1))
	//	{
	//		std::cout << "A Second have passed" << std::endl;
	//		//std::cout << "Duration Tick: " << two_sec.count() << std::endl;
	//		std::cout << "Frame count per seconds: " << frameCount << std::endl;
	//		endTime = std::chrono::steady_clock::now();
	//		frameCount = 0;
	//	}
	//	frameCount++;
	//	std::cout << "A Second have passed" << std::endl;
	//	system("cls");
	//}
	return 0;
}
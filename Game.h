#pragma once
#include <vector>
#include <chrono>

#include "Pixel.h"
#include "SnakeBody.h"
#include "Obstacle.h"


#define screen_width	30
#define screen_height	20


class Game
{
public:
	Game() = default;
	void Init();
	void Run();
	std::vector<SnakeBody*> snakeBodies;

private:
	Pixel* pixels[screen_width][screen_height]{};
	Pixel* emptyPixel{ new Pixel };
	Obstacle* obstaclePixel{ new Obstacle };
	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();

	//Gameplay Loop Functions
	void inputCheck();
	void update();
	void print();
	
	//Initialization Functions
	void generateLevel();
	void generateSnakeBody();
	bool canUpdate();

	//Gameplay Functions
	bool evaluateNewSnakeHeadPosition(Position pos);
};
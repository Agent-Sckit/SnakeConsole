#pragma once
#include <vector>
#include <chrono>
#include <cstdlib>

#include "Pixel.h"
#include "SnakeBody.h"
#include "Obstacle.h"
#include "Food.h"


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
	//Game Parameters
	bool canInput {true};
	bool isNotGameOver {true};
	int score {};
	int const screenWidth = screen_width;
	int const screenHeight = screen_height;
	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();

	//Game Objects
	Pixel* pixels[screen_width][screen_height]{};
	Pixel* emptyPixel{ new Pixel };
	Obstacle* obstaclePixel{ new Obstacle };
	Food* apple{ new Food };
			
	//Initialization Functions
	void generateLevel();
	void generateSnakeBody();
	bool canUpdate();

	//Gameplay Loop Functions
	void inputCheck();
	void update();
	void print();

	//Gameplay Functions
	bool evaluateNewSnakeHeadPosition(Position pos, bool& increaseSnakeLength);
	void changeFoodPosition(Food* food);	
};
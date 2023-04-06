#include<iostream>
#include <chrono>
#include <conio.h>
#include "Game.h"
#include "SnakeConsoleFunctions.h"




void Game::Init()
{
	consoleInit();
	generateLevel();
	generateSnakeBody();
	changeFoodPosition(apple);
}

void Game::Run()
{
	while (isNotGameOver)
	{
		inputCheck();
		if (canUpdate())
		{
			update();
			print();
		}
	}
	std::cout << "Gameover! Your Score is: " << score << "\n";
	return;
}

void Game::inputCheck()
{
	if (_kbhit() && canInput)
	{
		switch (_getch())
		{
		case 'w': case'W':
			snakeBodies[0]->snakeMovement.setYVelocity(-1);
			break;
		case 'a': case'A':
			snakeBodies[0]->snakeMovement.setXVelocity(-1);
			break;
		case 's': case'S':
			snakeBodies[0]->snakeMovement.setYVelocity(1);
			break;
		case 'd': case'D':
			snakeBodies[0]->snakeMovement.setXVelocity(1);
			break;
		default:
			break;
		}

		canInput = false;
	}
}

void Game::update()
{
	bool updateStatus{true};
	if (snakeBodies[0]->isMoving())
	{
		bool increaseSnakeLength{false};
		for (int i{ 0 }; i < size(snakeBodies); i++)
		{
			if (i == size(snakeBodies) - 1)
			{
				if (increaseSnakeLength)
				{
					snakeBodies.push_back(new SnakeBody(snakeBodies[i]->position.x, snakeBodies[i]->position.y));
					pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = snakeBodies[size(snakeBodies)-1];
					snakeBodies[size(snakeBodies) - 1]->targetPosition = snakeBodies[size(snakeBodies) - 2]->position;
					increaseSnakeLength = false;
					
				}
				else
				{
					pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = emptyPixel;
				}
			}
			if (i != 0)
			{
				snakeBodies[i]->position = snakeBodies[i]->targetPosition;
				pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = snakeBodies[i];
				snakeBodies[i]->targetPosition = snakeBodies[i - 1]->position;
			}

			else
			{
				snakeBodies[i]->move();
				isNotGameOver = evaluateNewSnakeHeadPosition(snakeBodies[i]->position, increaseSnakeLength);
			}
		}		
	}
}

void Game::print()
{
	using namespace std;
		
	system("cls");
	for (int i{ 0 }; i < screen_height; i++)
	{
		for (int j{ 0 }; j < screen_width; j++)
		{
			if (pixels[j][i]->GetPixel() != '\0')
			{
				cout << pixels[j][i]->GetPixel();
			}
		}
		cout << "\n";
	}
	cout << "Score: " << score << "\n";

	canInput = true;
}

void Game::generateLevel()
{
	for (int i{ 0 }; i < screen_height; i++)
	{
		for (int j{ 0 }; j < screen_width; j++)
		{
			if (i == 0 || i == screen_height - 1 || j == 0 || j == screen_width - 1)
			{
				pixels[j][i] = obstaclePixel;
			}

			else
			{
				pixels[j][i] = emptyPixel;
			}
		}
	}
}

void Game::generateSnakeBody()
{
	int initialSnakeLength{ 3 };
	for (int i{}; i < initialSnakeLength; i++)
	{
		//0 index in snakeBodies means it is the snake head
		snakeBodies.push_back(new SnakeBody((screen_width/2)-i, screen_height/2));
	}

	for (int i{}; i < size(snakeBodies); i++)
	{
		pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = snakeBodies[i];
		if (i != 0)
		{
			snakeBodies[i]->targetPosition = snakeBodies[i - 1]->position;
		}
	}
}

bool Game::canUpdate()
{
	auto deltaTime = std::chrono::steady_clock::now() - lastTime;

	if (deltaTime > std::chrono::milliseconds(100))
	{
		lastTime = std::chrono::steady_clock::now();
		return true;
	}

	else
	{
		return false;
	}
}

bool Game::evaluateNewSnakeHeadPosition(Position pos, bool& increaseSnakeLength)
{
	if (dynamic_cast<Obstacle*>(pixels[pos.x][pos.y]) || dynamic_cast<SnakeBody*>(pixels[pos.x][pos.y]))
	{
		pixels[pos.x][pos.y] = snakeBodies[0];
		increaseSnakeLength = false;
		return false;
	}
	else if (dynamic_cast<Food*>(pixels[pos.x][pos.y]))
	{
		changeFoodPosition(dynamic_cast<Food*>(pixels[pos.x][pos.y]));
		score++;
		increaseSnakeLength = true;
		pixels[pos.x][pos.y] = snakeBodies[0];
		return true;
	}

	pixels[pos.x][pos.y] = snakeBodies[0];
	increaseSnakeLength = false;
	return true;
}

void Game::changeFoodPosition(Food* food)
{
	bool noLocationFound{ true };
	int randomX{};
	int randomY{};

	do
	{
		randomX = std::rand() % screenWidth;
		randomY = std::rand() % screenHeight;
		if (!(dynamic_cast<Obstacle*>(pixels[randomX][randomY]) || dynamic_cast<SnakeBody*>(pixels[randomY][randomY])))
		{
			pixels[randomX][randomY] = food;
			noLocationFound = false;
		}
	} while (noLocationFound);
}
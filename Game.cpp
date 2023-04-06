#include<iostream>
#include <chrono>
#include <conio.h>
#include "Game.h"
#include "SnakeConsoleFunctions.h"
#include "Food.h"



void Game::Init()
{
	consoleInit();
	generateLevel();
	generateSnakeBody();
}

void Game::Run()
{
	while (true)
	{
		inputCheck();
		if (canUpdate())
		{
			update();
			print();
		}
	}
	return;
}

void Game::inputCheck()
{
	if (_kbhit())
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
	}
}

void Game::update()
{
	bool updateStatus{true};
	if (snakeBodies[0]->isMoving())
	{
		
		//for (int i=size(snakeBodies) - 1; i >= 0; i--)
		for (int i{ 0 }; i < size(snakeBodies); i++)
		{
			if (i == size(snakeBodies) - 1)
			{
				pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = emptyPixel;
			}
			if (i != 0)
			{
				snakeBodies[i]->position = snakeBodies[i]->targetPosition;
				pixels[snakeBodies[i]->position.x][snakeBodies[i]->position.y] = snakeBodies[i];
				snakeBodies[i]->targetPosition = snakeBodies[i - 1]->position;
				//pixels[snakeBodies[i].position.x][snakeBodies[i].position.y] = emptyPixel;
			}

			else
			{
				snakeBodies[i]->move();
				updateStatus = evaluateNewSnakeHeadPosition(snakeBodies[i]->position);				
			}
		}

		if (!updateStatus)
			system("pause");
		
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

	/*cout << "\n snakeBodies[0].snakeMovement.X: " << snakeBodies[0].snakeMovement.getXVelocity();
	cout << "\n snakeBodies[0].snakeMovement.Y: " << snakeBodies[0].snakeMovement.getYVelocity();
	cout << "\n snakeBodies[0].position.x: " << snakeBodies[0].position.x;
	cout << "\n snakeBodies[0].position.y: " << snakeBodies[0].position.y;*/
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

bool Game::evaluateNewSnakeHeadPosition(Position pos)
{
	if (dynamic_cast<Obstacle*>(pixels[pos.x][pos.y]) || dynamic_cast<SnakeBody*>(pixels[pos.x][pos.y]))
	{
		pixels[pos.x][pos.y] = snakeBodies[0];
		return false;
	}
	else if (dynamic_cast<Food*>(pixels[pos.x][pos.y]))
	{
		pixels[pos.x][pos.y] = snakeBodies[0];
		return true;
	}

	pixels[pos.x][pos.y] = snakeBodies[0];
	return true;

	
}
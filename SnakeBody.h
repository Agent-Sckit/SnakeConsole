#pragma once
#include <vector>

#include "Pixel.h"
#include "Position.h"
#include "SnakeMovement.h"

class Game; //expected circular dependency

class SnakeBody : public Pixel
{
public:
	SnakeMovement snakeMovement;
	Position targetPosition;
	SnakeBody(int t_xPosition, int t_yPosition);
	void move();
	bool isMoving();
	

private:
	//std::vector<SnakeBody>* snakeBodiesRef;
};

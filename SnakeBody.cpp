#include "SnakeBody.h"
#include "Game.h"

SnakeBody::SnakeBody(int t_xPosition, int t_yPosition) : Pixel{static_cast<char>(254)}
{
	position.x = t_xPosition;
	position.y = t_yPosition;
	//snakeBodiesRef = static_cast<std::vector<SnakeBody>*>(&t_gameRef->snakeBodies);
}

void SnakeBody::move()
{
	position.x = position.x + snakeMovement.getXVelocity();
	position.y = position.y + snakeMovement.getYVelocity();
}

bool SnakeBody::isMoving()
{
	return (snakeMovement.getXVelocity() || snakeMovement.getYVelocity());
}

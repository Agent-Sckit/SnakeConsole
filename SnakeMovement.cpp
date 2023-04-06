#include "SnakeMovement.h"

void SnakeMovement::setXVelocity(int t_xVelocity)
{
	if (t_xVelocity != 0)
	{
		if (xVelocity == (-t_xVelocity))
		{
			return;
		}

		if (t_xVelocity > 0)
		{
			xVelocity = 1;
		}

		if (t_xVelocity < 0)
		{
			xVelocity = -1;
		}

		yVelocity = 0;
	}
}

void SnakeMovement::setYVelocity(int t_yVelocity)
{
	if (t_yVelocity != 0)
	{
		if (yVelocity == (-t_yVelocity))
		{
			return;
		}

		if (t_yVelocity > 0)
		{
			yVelocity = 1;
			
		}

		if (t_yVelocity < 0)
		{
			yVelocity = -1;
		}

		xVelocity = 0;
	}
}

int SnakeMovement::getXVelocity()
{
	return xVelocity;
}

int SnakeMovement::getYVelocity()
{
	return yVelocity;
}
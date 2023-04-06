#pragma once

class SnakeMovement
{
private:
	int xVelocity{};
	int yVelocity{};

public:
	void setXVelocity(int t_xVelocity);
	void setYVelocity(int t_yVelocity);
	int getXVelocity();
	int getYVelocity();
};
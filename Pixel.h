#pragma once
#include "Position.h"

class Pixel
{
public:
	Position position;
	//Constructor
	Pixel();
	Pixel(char character);
	
	//Methods
	char GetPixel();

	//Destructor
	virtual ~Pixel();
protected:
	char pixel{ ' ' };
};

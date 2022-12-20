#pragma once
#include "defines.h"

class Widget {
	float posX;
	float posY;
	float sizeX;
	float sizeY;

public:
	virtual void draw() = 0;
	virtual void update() = 0;
	
	float getPosX() { return posX; }
	float getPosY() { return posY; }
	void setPosX(float x) { posX = x; }
	void setPosY(float y) { posY = y; }
	void setSizeX(float x) { sizeX = x; }
	void setSizeY(float y) { sizeY = y; }
	float getSizeX() { return sizeX; }
	float getSizeY() { return sizeY; }
	bool contains(float x, float y){ return distance(x, y, posX, posY) < WIDGET_WIDTH * 0.4f; }
	
};

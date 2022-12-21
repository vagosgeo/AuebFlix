#include "Button.h"
#include "graphics.h"

void Button::update()
{
}

void Button::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + getPath();
	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);
}

void Button::setPath(int i)
{
	if (i == 0) {
		ButtonPath = LButton;
	}
	else {
		ButtonPath = RButton;
	}
}

std::string Button::getPath()
{
	return ButtonPath;
}

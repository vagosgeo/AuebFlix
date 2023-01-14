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

void Button::setPath(std::string path)
{
	ButtonPath = path;
}

std::string Button::getPath()
{
	return ButtonPath;
}

void Button::drawButton() {
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + getPath();
	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.5f;
	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);
}

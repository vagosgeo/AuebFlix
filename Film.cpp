#include "Film.h"
#include "defines.h"
#include "widget.h"
#include "graphics.h"
#include <string>

void Film::update()
{


}

void Film::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + getPath();
	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);


}

void Film::setPath(int i)
{
	if (i == 0) {
		IconPath = PHOTO;
	}
	else if (i == 1) {
		IconPath = PHOTO1;
	}
	else if (i == 2) {
		IconPath = PHOTO2;
	}
	else {
		IconPath = PHOTO3;
	}
}

std::string Film::getPath() {
	return IconPath;
}



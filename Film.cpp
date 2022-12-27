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
	br.fill_opacity = 0.5f;
	graphics::setOrientation(180.f);
	graphics::drawRect(getPosX(), getPosY() + getSizeY(), -getSizeX(), getSizeY(), br);
	graphics::resetPose();

}





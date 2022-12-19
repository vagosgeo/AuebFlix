#include "widget.h"
#include "graphics.h"
#include "defines.h"
#include <string>


void Widget::draw()
{
	float h = 1.0f * w_highlighted;
	graphics::Brush br;
	graphics::Brush br1;
	SETCOLOR(br1.fill_color, h, h, h);
	br.outline_opacity = 0.0f;
	graphics::drawDisk(w_pos[0], w_pos[1], WIDGET_WIDTH*0.4f,br);
	
	br.texture = ASSET_PATH + PHOTO_PATH;
	graphics::drawRect(w_pos[0],w_pos[1], WIDGET_WIDTH, WIDGET_HEIGHT,br);


}

void Widget::update()
{

}

std::string Widget::setPath(int i)
{
	if (i == 0) {
		PHOTO_PATH = colour[0];
		return PHOTO;
	}
	else if (i == 1) {
		PHOTO_PATH = PHOTO1;
		return PHOTO1;
	}
	else if (i == 2) {
		PHOTO_PATH = PHOTO2;
		return PHOTO2;
	}
	else {
		PHOTO_PATH = PHOTO3;
		return PHOTO3;
	}
}

bool Widget::contains(float x, float y)
{
	return distance(x, y, w_pos[0], w_pos[1]) < WIDGET_WIDTH*0.4f ;
}

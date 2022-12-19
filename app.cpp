#include "app.h"
#include "defines.h"
#include <graphics.h>
#include <string>


void App::draw()
{
	graphics::Brush br;
	//SETCOLOR(br.fill_color, 255.f, 255.f, 255.f);
	//graphics::drawRect(w_pos[0], w_pos[1],)
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("BackGround.png");
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	for (auto widget : widgets) {
		widget->draw();
	}

}


void App::init()
{
	
	for (int i = 0; i < 4; i++) {
		//pes oti kaneis kapoia allagh opws auto to sxolio
		
		// for each widget set the coordinates and the name of photo
		Widget* w = new Widget();
		widgets.push_front(w);
    	w->setPosX(CANVAS_WIDTH * (i + 0.5f) / 7.0f);
		w->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
		w->setPath(i);
			
		
	}
	
	/*Widget* w = new Widget();
	widgets.push_front(w);
	w->setPosX(CANVAS_WIDTH / 6.0f);
	w->setPosY(CANVAS_HEIGHT / 3.0f);*/
}

void App::update()
{

	for (auto widget : widgets) {
		widget->update();
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	Widget* cur_widget = nullptr;
	
	for (auto widget : widgets) {
		if (widget->contains(mx, my)) {
			widget->setHighlight(true);
			cur_widget = widget;

		}
		else
			widget->setHighlight(false);
	}

	
	/*if (ms.button_left_pressed && cur_widget) {
	}*/

}
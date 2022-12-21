#include "app.h"
#include "defines.h"
#include <graphics.h>
#include <string>
#include <iostream>
#include "Film.h"
#include "Button.h"
#include <thread>










void App::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("BackGround.png");
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	
	for (auto film : films) {
		film->draw();
	}
		
	for (auto button : buttons) {
		button->draw();
	}
	
	
}


void App::init()
{
	
	for (int i = 0; i < 15; i++) {
		
		// for each widget set the coordinates and the name of photo
		Film* w = new Film();
		films.push_front(w);
    	w->setPosX(CANVAS_WIDTH * (i + 0.9f) / 6.8f);
		w->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
		w->setPath(i);
		w->setId(counter);
		counter++;
		w->setSizeX(WIDGET_WIDTH);
		w->setSizeY(WIDGET_HEIGHT);
			
		
	}
	
	for (int i = 0; i < 3; i++) {
		Button* b = new Button();
		buttons.push_front(b);
		if (i == 0) {
			b->setPosX(CANVAS_WIDTH * (i + 0.2f) / 7.0f);
			b->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
			b->setPath(i);
			b->setId(counter);
			counter++;
			b->setSizeX(WIDGET_WIDTH/3);
			b->setSizeY(WIDGET_HEIGHT/3);
		}
		else if (i == 1) {
			b->setPosX(CANVAS_WIDTH * (6 + 0.85f) / 7.0f);
			b->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
			b->setPath(i);
			b->setId(counter);
			counter++;
			b->setSizeX(WIDGET_WIDTH/3);
			b->setSizeY(WIDGET_HEIGHT/3);

		}
	}
}





/*bool App::requestFocus()
{
	if (!m_focus || m_focus = ) {
		m_focus =
		return true;
	}
	return false;

}

void App::releasedFocus()
{
}*/

void App::update()
{
	
	

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	Widget* cur_widget = nullptr;
	
	for (auto widget : films) {
		if (widget->contains(mx, my)) {
			
			if (widget->getSizeX() < 150) {
				float widget_x = widget->getSizeX();
				float widget_y = widget->getSizeY();
				widget->setSizeX(widget_x + graphics::getDeltaTime() / 20);
				widget->setSizeY(widget_y + graphics::getDeltaTime() / 20);
			}

		}
		else 
		{
			
			widget->setSizeX(WIDGET_WIDTH);
			widget->setSizeY(WIDGET_HEIGHT);
			std::cout << "ELSE!!!";
		}
	}

	

	for (auto widget : buttons) {
		if (widget->contains(mx, my)) {

			if (widget->getSizeX() < 50) {
				float widget_x = widget->getSizeX();
				float widget_y = widget->getSizeY();
				widget->setSizeX(widget_x + graphics::getDeltaTime() / 20);
				widget->setSizeY(widget_y + graphics::getDeltaTime() / 20);
			}
			if (ms.button_left_pressed) {
				if ( widget->getPath() == "LButton.png") {
					for (auto film : films) {

						x = film->getPosX();

						film->setPosX(x + 200.f);

					}
				}
				else if(widget->getPath() == "RButton.png") {
					for (auto film : films) {

						x = film->getPosX();

						film->setPosX(x - 200.f);

					}
				}
			}

		}
		else
		{
			
			widget->setSizeX(WIDGET_WIDTH/3);
			widget->setSizeY(WIDGET_HEIGHT/3);
			std::cout << "ELSE!!!";
		}
	}

	
	

}
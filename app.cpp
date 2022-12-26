#include "app.h"
#include "defines.h"
#include <graphics.h>
#include <string>
#include <iostream>
#include "Film.h"
#include "Button.h"
#include <thread>
#include "readFilmData.h"
#include <iterator>
#include <list>
#include <vector>
#include <iostream>
#include <bits-stdc++.h>
using namespace std;










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
	
	textFields[0]->draw();
	
}


void App::init()
{
	readFilmData(films);	// READS ALL THE FILMS THAT EXIST ON THE .XML AND STORES THEM IN THE 'films' LIST.
	
	for (Film* film : films) {			
		
		// INITIALIZE THE COORDINATES AND SIZE OF ALL THE 'FILM' OBJECTS
		
			film->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
			film->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
			film->setId(counter);
			counter++;
			film->setSizeX(WIDGET_WIDTH);
			film->setSizeY(WIDGET_HEIGHT);
		
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		Button* b = new Button();
		buttons.push_front(b);
		if (i == 0) {
			b->setPosX(CANVAS_WIDTH * (i + 0.2f) / 7.0f);
			b->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
			b->setPath(LButton);
			b->setId(counter);
			counter++;
			b->setSizeX(WIDGET_WIDTH/3);
			b->setSizeY(WIDGET_HEIGHT/3);
		}
		else if (i == 1) {
			b->setPosX(CANVAS_WIDTH * (6 + 0.85f) / 7.0f);
			b->setPosY(CANVAS_HEIGHT * (0.5f) / 3.0f);
			b->setPath(RButton);
			b->setId(counter);
			counter++;
			b->setSizeX(WIDGET_WIDTH/3);
			b->setSizeY(WIDGET_HEIGHT/3);
		}
		else {
			b->setPosX(CANVAS_WIDTH /2);
			b->setPosY(20);
			b->setPath("downButton.png");
			b->setId(counter);
			counter++;
			b->setSizeX(WIDGET_WIDTH / 3);
			b->setSizeY(WIDGET_HEIGHT / 3);
		}
	}


	textField* field = new textField();
	field->setPosX(250);
	field->setPosY(250);
	field->setSizeX(150);
	field->setSizeY(40);
	textFields.push_back(field);

	graphics::setFont(std::string(ASSET_PATH) + "open-sans.light.ttf");
}








void App::update()
{
	auto l_front = films.begin();

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	
	
	for (auto widget : films) {
		if (widget->contains(mx, my) && requestFocus(widget)) {
			
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
		}
	}

	for (auto widget : buttons) {
		if (widget->contains(mx, my)) {
			
			forceFocus(widget);		// CURRENT BUTTON TAKES FOCUS BY FORCE (EVEN IF ANOTHER WIDGET HAS FOCUS ALREADY).
			Film* k = nullptr;
			if (widget->getSizeX() < 50) {
				float widget_x = widget->getSizeX();
				float widget_y = widget->getSizeY();
				widget->setSizeX(widget_x + graphics::getDeltaTime() / 20);
				widget->setSizeY(widget_y + graphics::getDeltaTime() / 20);
			}
			if (ms.button_left_pressed) {
				if ( widget->getPath() == "LButton.png") {
					int j = 0;
					for (auto film : films) {
						
						if (j == 0) {
							
							DimensionsVector.push_back(film->getPosX());
							j++;
				
						}
						else {
							DimensionsVector.push_back(film->getPosX());
							j++;
						}
						
					}
					
					int VectorCounter = 0;
					
					for (auto film : films) {
						if (VectorCounter == 0) {
							film->setPosX(DimensionsVector[DimensionsVector.size() - 1]);
							VectorCounter++;
						}
						else {
							film->setPosX(DimensionsVector[VectorCounter-1]);
							VectorCounter++;
						}
						
						
					}
					DimensionsVector.clear();

					
					
				}
				else if(widget->getPath() == "RButton.png") {

					int j = 0;
					for (auto film : films) {
						if (j == 0) {

							DimensionsVector.push_back(film->getPosX());
							j++;

						}
						else {
							DimensionsVector.push_back(film->getPosX());
							j++;
						}
					}
					int VectorCounter = 0;
					
					for (auto film : films) {
						if (VectorCounter == DimensionsVector.size()-1) {
							film->setPosX(DimensionsVector[0]);
							VectorCounter++;
						}
						else {
							film->setPosX(DimensionsVector[VectorCounter + 1]);
							VectorCounter++;
						}


					}
					DimensionsVector.clear();
				}
			}
		}
		else
		{
			widget->setSizeX(WIDGET_WIDTH/3);
			widget->setSizeY(WIDGET_HEIGHT/3);
			if (requestFocus(widget)) {			// RELEASE FOCUS ONLY IF THE MOUSE ISN'T HOVERING OVER THE OBJECT THAT CURRENTLY HAS THE FOCUS
				releaseFocus();					
			}
		}
	}

	for (textField* field : textFields) {
		if (field->contains(mx, my) && requestFocus(field)) {
			field->checkScanCodes();
		}
	}








}



void App::forceFocus(Widget* object_ptr) { 
		focus = object_ptr;
}

Film* App::get(std::list<Film*> films)
{
	std::list<Film*>::iterator it = films.begin();
	for (int i = 0; i < films.size(); i++) {
		++it;
	}
	return *it;
}

bool App::requestFocus(Widget* object_ptr) {
	if (focus == nullptr) {
		focus == object_ptr;
		return true;
	}
	else if(focus == object_ptr) {
		return true;
	}
	else { 
		return false;
	}
}




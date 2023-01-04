#include "searchRect.h"
#include "graphics.h"
#include <iostream>
using namespace std;




searchRect::searchRect()
{
	field = new textField(400, -300, 170, 30);
}

void searchRect::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.outline_opacity = 0.5f;
	br.gradient = true;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;

	br.fill_opacity = 2.0f;
	br.fill_secondary_opacity = 1.f;

	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.gradient = false;

	graphics::drawText(getPosX() - 50, getPosY() - 160.0f, 30.0f, "Filters", br);
	
	for (auto button : Rectbuttons) {
		button->draw();
			
	}
	

	
	field->draw();
	
}

void searchRect::update()
{

	if (getDropButtonState() == true) {		// IF DOWN BUTTON IS PRESSED THEN FETCH THE SEARCH BOX FROM THE UPPER BOUND.(APPEAR)
		
		if (getPosY() < 250) {
			setPosY(getPosY() + graphics::getDeltaTime() / 2);
											
			field -> setPosY(field -> getPosY() + graphics::getDeltaTime() / 2);	// Also fetch the textField that exist on the search box.
			for (auto button : Rectbuttons) {
				button->setPosY(button->getPosY() + graphics::getDeltaTime() / 2 );
			}
		}

	}
	else {												// IF DOWN BUTTON IS DE-PRESSED THEN PUT THE SEARCH BOX ABOVE THE UPPER BOUND.(DISSAPPEAR)
		if (Search == "clearfilters") {
			Search.clear();
		}
		if (getPosY() > -200) {
			setPosY(getPosY() - graphics::getDeltaTime() / 2);
					
			field->setPosY(field->getPosY() - graphics::getDeltaTime() / 2);	// Also takes away the textFields with the search box.
			for (auto button : Rectbuttons) {
				button->setPosY(button->getPosY() - graphics::getDeltaTime() / 2 );
			}
		}
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	if (field->contains(mx, my) ) {
		field->checkScanCodes();
	}
	else {
		for (auto button : Rectbuttons) {
			if (ms.button_left_pressed && button->contains(mx, my)) {

				if (button->getPath() == "DRAMA.png") {
					cout << "Button Pressed" << endl;
					Search = "drama";
				}
				else if (button->getPath() == "ACTION.png") {
					Search = "action";
				}
				else if (button->getPath() == "CRIME.png") {
					Search = "crime";
				}
				else if (button->getPath() == "FANTASY.png") {
					Search = "fantasy";
				}
				else if (button->getPath() == "ADVENTURE.png") {
					Search = "adventure";
				}
				else if (button->getPath() == "CLEARFILTERS.png") {
					Search = "clearfilters";
				}

			}

		}
	}
	

}

void searchRect::init() {
	for (int i = 0; i < 6; i++) {
		Button* b = new Button();
		Rectbuttons.push_back(b);
		if (i == 0) {
			b->setPosX(550.0f);
			b->setPosY(-300.0f);
			b->setPath("DRAMA.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 1) {
			b->setPosX(630.0f);
			b->setPosY(-300.0f);
			b->setPath("ACTION.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 2) {
			b->setPosX(550.0f);
			b->setPosY(-230.0f);
			b->setPath("CRIME.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 3) {
			b->setPosX(630.0f);
			b->setPosY(-230.0f);
			b->setPath("FANTASY.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 4) {
			b->setPosX(550.0f);
			b->setPosY(-160.0f);
			b->setPath("ADVENTURE.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 5) {
			b->setPosX(630.0f);
			b->setPosY(-160.0f);
			b->setPath("CLEARFILTERS.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}

	}
}

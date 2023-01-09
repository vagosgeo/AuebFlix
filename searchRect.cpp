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
	br.texture = ASSET_PATH + std::string("RectBackground.png");
	br.fill_opacity = 0.5f;
	br.fill_secondary_opacity = 1.f;

	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.gradient = false;
	br.fill_opacity = 1.0f;

	graphics::drawText(getPosX() - 50, getPosY() - 160.0f, 30.0f, "Filters", br);
	
	graphics::Brush br1;

	br1.fill_color[0] = 1.0f;
	br1.fill_color[1] = 1.0f;
	br1.fill_color[2] = 1.0f;
	graphics::drawText(getPosX() - 50, getPosY() + 120.0f, 20.0f,"From:", br1);
	graphics::drawText(getPosX(), getPosY() + 120.0f, 10.0f, "1970", br1);
	graphics::drawLine(getPosX() + 30, getPosY() + 120.0f, getPosX() + 150, getPosY() + 120.0f,br1);
	graphics::drawText(getPosX() + 160, getPosY() + 120.0f, 10.0f, "2020", br1);
	
	
	
	graphics::drawText(getPosX() -50, getPosY() + 170.0f, 20.0f, "To:", br1);
	graphics::drawText(getPosX(), getPosY() + 170.0f, 10.0f, "1970", br1);
	graphics::drawLine(getPosX() + 30 , getPosY() + 170.0f, getPosX() + 150, getPosY() + 170.0f, br1);
	graphics::drawText(getPosX() + 160, getPosY() + 170.0f, 10.0f, "2020", br1);
	
	
	// draw the buttons and specificaly for the buttons in the date filter, draw texts above them based on the distance from the init position of the button  
	for (auto button : Rectbuttons) {
		button->draw();
		if (button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) > 8.0f && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) < 25.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1980", br1);
		}
		else if (button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) >= 25.0f && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) < 55.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1990", br1);
		}
		else if (button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) >= 55.0f && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) < 80.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2000", br1);
		}
		else if (button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) >= 80.0f && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) < 110.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2010", br1);
		}
		else if (button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) >= 110.0f && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) <= 130.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2020", br1);
		}
		else if(button->getPath() == "from.png" && distance(init_from_posx, init_from_posy, cur_from_posx, cur_from_posy) <= 8.0f ){
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1970", br1);
		}
		
		


		if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) > 8.0f && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) < 25.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2010", br1);
		}
		else if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) >= 25.0f && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) < 55.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2000", br1);
		}
		else if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) >= 55.0f && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) < 80.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1990", br1);
		}
		else if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) >= 80.0f && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) < 110.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1980", br1);
		}
		else if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) >= 110.0f && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) <= 130.0f) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "1970", br1);
		}
		else if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, cur_to_posx, cur_to_posy) <= 8.0f ) {
			graphics::drawText(button->getPosX() - 8.0f, button->getPosY() - 15.0f, 10.0f, "2020", br1);
		}
		
	}
	
	// draw textfield
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
	else {						// IF DOWN BUTTON IS DE-PRESSED THEN PUT THE SEARCH BOX ABOVE THE UPPER BOUND.(DISSAPPEAR)

		
		if (getPosY() > -200) {
			setPosY(getPosY() - graphics::getDeltaTime() / 2);
					
			field->setPosY(field->getPosY() - graphics::getDeltaTime() / 2);	// Also takes away the textFields with the search box.
			for (auto button : Rectbuttons) {
				button->setPosY(button->getPosY() - graphics::getDeltaTime() / 2 );
				
			}
		}
	}
	if (Search == "clearfilters") {
		//set the buttons on the date filter back to the init position
		for (auto button : Rectbuttons) {

			if (button->getPath() == "from.png") {
				button->setPosX(getPosX() + 30);
				button->setPosY(getPosY() + 120.0f);
				cur_from_posx = button->getPosX();
				cur_from_posy = button->getPosY();
				counterFirstX == 0;
				DateSearchFrom.clear();

			}
			else if (button->getPath() == "to.png") {
				button->setPosX(getPosX() + 150);
				button->setPosY(getPosY() + 170.0f);
				cur_to_posx = button->getPosX();
				cur_to_posy = button->getPosY();
				counterFirstY == 0;
				DateSearchTo.clear();
				
			}
		}
		// clear the type filter
		Search.clear();
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
			// when the button is pressed take the type of films which is selected
			if (ms.button_left_pressed && button->contains(mx, my)) {

				if (button->getPath() == "DRAMA.png") {
					
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
				else if (button->getPath() == "from.png" && counterFirstX == 0) {
					init_from_posx = button->getPosX();   // take the first position of the button 
					init_from_posy = button->getPosY();
					cur_from_posx = button->getPosX();   // take the current position of the button 
					cur_from_posy = button->getPosY();
					counterFirstX++;

				}
				else if (button->getPath() == "to.png" && counterFirstY == 0) {
					
					init_to_posx = button->getPosX();	// take the first position of the button
					init_to_posy = button->getPosY();
					cur_to_posx = button->getPosX();   // take the current position of the button 
					cur_to_posy = button->getPosY();
					counterFirstY++;
				}
				

			}
			// dragging of mouse when you choose the age on the filters
			if (ms.dragging && button->contains(mx, my)) {
				if (button->getPath() == "from.png" && distance(init_from_posx,init_from_posy,mx,my)< 120.0f && mx >= init_from_posx) {
					button->setPosX(mx);
					cur_from_posx = mx;
					
				}
				if (button->getPath() == "to.png" && distance(init_to_posx, init_to_posy, mx, my) < 120.0f && mx <= init_to_posx) {
					
					button->setPosX(mx);
					cur_to_posx = mx;

				}
			}
			//when the mouse button is released take the date that user select
			if (ms.button_left_released && button->contains(mx, my)) {
				if (button->getPath() == "from.png") {
					if (distance(init_from_posx, init_from_posy, mx, my) > 8.0f && distance(init_from_posx, init_from_posy, mx, my) < 25.0f) {
						DateSearchFrom = "1980";
					}
					else if (distance(init_from_posx, init_from_posy, mx, my) >= 25.0f && distance(init_from_posx, init_from_posy, mx, my) < 55.0f) {
						DateSearchFrom = "1990";
					}
					else if (distance(init_from_posx, init_from_posy, mx, my) >= 55.0f && distance(init_from_posx, init_from_posy, mx, my) < 80.0f) {
						DateSearchFrom = "2000";
					}
					else if (distance(init_from_posx, init_from_posy, mx, my) >= 80.0f && distance(init_from_posx, init_from_posy, mx, my) < 110.0f) {
						DateSearchFrom = "2010";
					}
					else if (distance(init_from_posx, init_from_posy, mx, my) >= 110.0f && distance(init_from_posx, init_from_posy, mx, my) <= 130.0f) {
						DateSearchFrom = "2020";
					}
					else if (distance(init_from_posx, init_from_posy, mx, my) >= 0.5f && distance(init_from_posx, init_from_posy, mx, my) <= 8.0f) {
						DateSearchFrom = "1970";
					}
				}
				if (button->getPath() == "to.png") {
					if (distance(init_to_posx, init_to_posy, mx, my) > 8.0f && distance(init_to_posx, init_to_posy, mx, my) < 25.0f) {
						DateSearchTo = "2010";
					}
					else if (distance(init_to_posx, init_to_posy, mx, my) >= 25.0f && distance(init_to_posx, init_to_posy, mx, my) < 55.0f) {
						DateSearchTo = "2000";
					}
					else if (distance(init_to_posx, init_to_posy, mx, my) >= 55.0f && distance(init_to_posx, init_to_posy, mx, my) < 80.0f) {
						DateSearchTo = "1990";
					}
					else if (distance(init_to_posx, init_to_posy, mx, my) >= 80.0f && distance(init_to_posx, init_to_posy, mx, my) < 110.0f) {
						DateSearchTo = "1980";
					}
					else if (distance(init_to_posx, init_to_posy, mx, my) >= 110.0f && distance(init_to_posx, init_to_posy, mx, my) <= 130.0f) {
						DateSearchTo = "1970";
					}
					else if (distance(init_to_posx, init_to_posy, mx, my) >= 0.5f && distance(init_to_posx, init_to_posy, mx, my) <= 8.0f) {
						
						DateSearchTo = "2020";
					}
				}

				
			}

		}
	}
	

}

void searchRect::init() {
	// initialize the buttons in the filter's rectangle 
	for (int i = 0; i < 8; i++) {
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
			b->setSizeY(50.0f);
		}
		else if (i == 5) {
			b->setPosX(630.0f);
			b->setPosY(-160.0f);
			b->setPath("CLEARFILTERS.png");
			b->setSizeX(70.0f);
			b->setSizeY(60.0f);
		}
		else if (i == 6) {
			b->setPosX(getPosX() + 30);
			b->setPosY(getPosY() + 120.0f);
			b->setPath("from.png");
			b->setSizeX(10.0f);
			b->setSizeY(20.0f);
			
		}
		else {
			b->setPosX(getPosX() + 150);
			b->setPosY(getPosY() + 170.0f);
			b->setPath("to.png");
			b->setSizeX(10.0f);
			b->setSizeY(20.0f);
			
		}

	}

}

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
#include "searchRect.h"

using std::cout;
using namespace std;








void App::draw()
{
	if (status == STATUS_START)
		drawStartScreen();
	else if (status == STATUS_APP)
		drawAppScreen();


	


} // draw() ends here -------


void App::init()
{
	readFilmData(films);	// READS ALL THE FILMS THAT EXIST ON THE .XML AND STORES THEM IN THE 'films' LIST.
	//Shownfilms.splice(Shownfilms.begin(), films);
	Shownfilms.assign(films.begin(), films.end());
	

	for (Film* film : films) {			
		
		// INITIALIZE THE COORDINATES AND SIZE OF ALL THE 'FILM' OBJECTS
		
			film->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
			film->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
			film->setId(counter);
			cout << film->getPosX() << endl;
			cout << film->getPosY() << endl;
			counter++;
			film->setSizeX(WIDGET_WIDTH);
			film->setSizeY(WIDGET_HEIGHT);
		
	}
	counter = 0;

	// INITIALIZE THE COORDINATES AND SIZE OF ALL THE 'Button' OBJECTS
	for (int i = 0; i < 3; i++) {
		Button* b = new Button();
		buttons.push_back(b);
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

	graphics::setFont(std::string(ASSET_PATH) + "open-sans.light.ttf"); // sets the font of the application


	App::searchBox = new searchRect();
	searchBox->setPosX(500);
	searchBox->setPosY(-200);
	searchBox->setSizeX(400);
	searchBox->setSizeY(400);
	searchBox->init();

} // init() ends here ----------



void App::update()
{
	if (status == STATUS_START) {
		updateStartScreen();
		
	}
	else if (status == STATUS_APP) {
		updateAppScreen();
	}

} // update() ends here ---------

void App::drawStartScreen()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("BackGround.png");
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	char info[40];
	sprintf_s(info, "AUEBFLIX");
	graphics::drawText(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 2, 40, info, br);
	graphics::setOrientation(180.0f);
	br.fill_opacity = 0.5f;
	graphics::drawText(CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2, 40, info, br);
	graphics::resetPose();
	br.fill_opacity = 0.5f;
	char press[40];
	sprintf_s(press, "Press ENTER to continue...");
	graphics::drawText(CANVAS_WIDTH /1.5, CANVAS_HEIGHT /1.1 , 30, press, br);
	
}

void App::drawAppScreen()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("BackGround.png");
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	

	for (auto film : Shownfilms) {
		film->draw();
	}

	for (auto button : buttons) {
		button->draw();
	}

	// draw the texts under the films when the mouse hovers the widgets
	for (auto film : Shownfilms) {
		if (drawText && text == film->getPath()) {
		
			string TEXT = Capitalize_first_letter(film->getTitle());
			graphics::drawText(CANVAS_WIDTH / 10, CANVAS_HEIGHT / 1.6, 40, TEXT, br);
			TEXT = Capitalize_first_letter(film->getActors());
			graphics::drawText(CANVAS_WIDTH / 10, CANVAS_HEIGHT / 1.4, 30, TEXT, br);
			graphics::drawText(CANVAS_WIDTH / 10, CANVAS_HEIGHT / 1.2, 20, film->getDate(), br);
			TEXT = Capitalize_first_letter(film->getDescription());
			graphics::drawText(CANVAS_WIDTH / 10, CANVAS_HEIGHT / 1.1, 20, TEXT, br);

		}
	}
	
	if (PlayMusic) {

		graphics::playMusic(std::string(ASSET_PATH) + "button.wav", 0.3f, false, 100);
		PlayMusic = false;

	}
		
	searchBox->draw();

	

	
} // drawAppScreen() ends here ----------

void App::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
		status = STATUS_APP;
}

void App::updateAppScreen()
{
	
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);


	std::string search_string = searchBox->getTextField()->str;	 // Gets the string from the searchBoxe's textField.
	std::string SEARCH = searchBox->getSearch();				 //Gets the type (filter) that user selects
	std::string DateSearchFrom = searchBox->getDateSearchFrom(); //Gets the date from (filter) that user selects
	std::string DateSearchTo = searchBox->getDateSearchTo();	 //Gets the date to (filter) that user selects
	int counter = 0;
	if (!search_string.empty()) {
		
		cur_search = search_string;
	}
	else if (!SEARCH.empty()) {
		
		cur_search = SEARCH;
	}
	else if (!DateSearchFrom.empty() || !DateSearchTo.empty()) {
		
		cur_search = DateSearchFrom;
		cur_searchTo = DateSearchTo;
	}
	
	
	
	for (auto  widget : films) {
		// The hierarchy of the filters:
		// 1. textfield
		// 2. type
		// 3. date
		// The films will be shown, based on textfield regardless the other filters
		// The films will be shown, based on type if textfield filter is not energized
		// The films will be shown, based on date if any other filter is not energized
		
		
		//if user writes in the textfield, show the films based on the text 
		if (search_string != search_str && cur_search != prv_search && !search_string.empty()) {
			
			if ((search_string == "") || searchFilmFields(widget, search_string)) {
				//int ListCounter = 0;
				
				for (auto i = Shownfilms.begin(); i != Shownfilms.end(); i++) {
					if (*i == widget) {
						ListCounter  = true;
						
					}
				}
				if (!ListCounter) {
					Shownfilms.push_back(widget);
					
				}
				ListCounter = false;
				widget->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
				widget->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
				counter++;

			}
			else {
				Shownfilms.remove(widget);
				widget->setPosX(-100);
				widget->setPosY(-500);
			}
			
		}
		// else if user selects the type of the movies, show the films based on type
		else if (!SEARCH.empty() && search_string.empty() && SEARCH != "clearfilters"&& cur_search != prv_search) {
			
			if (searchFilmFields(widget, SEARCH)) {
				//int ListCounter = 0;
				
				for (auto i = Shownfilms.begin(); i != Shownfilms.end(); i++) {
					if (*i == widget) {
					
						ListCounter = true;
						
						
					}
					
				}
				if (!ListCounter) {
					Shownfilms.push_back(widget);
					
				}
				cout << Shownfilms.size() << endl;
				ListCounter = false;
				widget->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
				widget->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
				counter++;
			}
			else {
				Shownfilms.remove(widget);
				
				widget->setPosX(-100);
				widget->setPosY(-500);
			}
			
		}
		//else if user selects the date of the movies, show the films based on date
		else if (!DateSearchFrom.empty() && !DateSearchTo.empty() && SEARCH.empty() && search_string.empty() && (cur_search != prv_search || cur_searchTo!=prv_searchTo)) {
			
			if (searchFilmDate(widget, DateSearchFrom, DateSearchTo)) {
				//int ListCounter = 0;
				for (auto i = Shownfilms.begin(); i != Shownfilms.end(); i++) {
					if (*i == widget) {
						
						ListCounter = true;
					}
				}
				if (!ListCounter) {
					Shownfilms.push_back(widget);
					
				}
				ListCounter = false;
				widget->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
				widget->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
				counter++;
			}
			else {
				Shownfilms.remove(widget);
				widget->setPosX(-100);
				widget->setPosY(-500);
			}
		
		}
		//else if user selects clear filters, show all the films 
		else if(SEARCH == "clearfilters") {
			for (auto i = Shownfilms.begin(); i != Shownfilms.end(); i++) {
				if (*i == widget) {

					ListCounter = true;
				}
			}
			if (!ListCounter) {
				Shownfilms.push_back(widget);

			}
			ListCounter = false;
			widget->setPosX(CANVAS_WIDTH * (counter + 0.9f) / 6.8f);
			widget->setPosY(CANVAS_HEIGHT * (0.6f) / 3.0f);
			counter++;
		}
	




		if (widget->contains(mx, my) && requestFocus(widget)) {

			// if the mouse hovers a specific film, drawtext = true and take the path of the film
			drawText = true;
			if (widget->getPath() == "Godfather.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "FightClub.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "ANewHope.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "EmpireStrikesBack.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "TheInception.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "Terminator.png") {
				text = widget->getPath();
			}
			else if (widget->getPath() == "TopGun.png") {
				text = widget->getPath();
			}

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
	if (!search_string.empty()) {
		
		prv_search = search_string;
	}
	else if (!SEARCH.empty()) {
		
		prv_search = SEARCH;
	}
	else if (!DateSearchFrom.empty() || !DateSearchTo.empty()) {
		prv_search = DateSearchFrom;
		prv_searchTo = DateSearchTo;
		
	}
	

	for (auto widget : buttons) {
		if (widget->contains(mx, my)) {

			if (searchBox->getDropButtonState() == false) {
															// CURRENT BUTTON TAKES FOCUS BY FORCE (EVEN IF ANOTHER WIDGET HAS FOCUS ALREADY).
				forceFocus(widget);					// EXCEPT IF DROP-DOWN SEARCH BOX IS ON THE CANVAS.
			}					

			Film* k = nullptr;
			if (widget->getSizeX() < 50 && requestFocus(widget)) {
				float widget_x = widget->getSizeX();
				float widget_y = widget->getSizeY();
				widget->setSizeX(widget_x + graphics::getDeltaTime() / 20);
				widget->setSizeY(widget_y + graphics::getDeltaTime() / 20);
			}
			if (ms.button_left_pressed) {
				//if the specific button is pressed, move all the films left (circle movement) 
				if (widget->getPath() == "LButton.png") {
					
						PlayMusic = true;

					if (Shownfilms.empty()) {
						
						for (auto film : films) {
						
							DimensionsVector.push_back(film->getPosX());

						}

						int VectorCounter = 0;
					
						for (auto film : films) {
							
							if (VectorCounter == 0) {

								film->setPosX(DimensionsVector[DimensionsVector.size() - 1]);
								VectorCounter++;
							}
							else {

								film->setPosX(DimensionsVector[VectorCounter - 1]);
								VectorCounter++;
							}

						}
						DimensionsVector.clear();
					}
					else {
						
						for (auto film : Shownfilms) {

							DimensionsVector.push_back(film->getPosX());
							cout << film->getPath();
							cout << film->getPosX() << endl;

						}
						
						int VectorCounter = 0;
						for (auto film : Shownfilms) {
							
							if (VectorCounter == 0) {

								film->setPosX(DimensionsVector[DimensionsVector.size() - 1]);
								VectorCounter++;
								cout << film->getPath();
								cout << film->getPosX() << endl;
							}
							else {

								film->setPosX(DimensionsVector[VectorCounter - 1]);
								VectorCounter++;
								cout << film->getPath();
								cout << film->getPosX() << endl;
							}

						}
						DimensionsVector.clear();
					}
				}
				//else_if the specific button is pressed, move all the films right (circle movement) 
				else if (widget->getPath() == "RButton.png") {
					
					PlayMusic = true;

					if (Shownfilms.empty()) {
						for (auto film : films) {

							DimensionsVector.push_back(film->getPosX());
						}
						int VectorCounter = 0;

						for (auto film : films) {
							if (VectorCounter == DimensionsVector.size() - 1) {

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
					else {
						for (auto film : Shownfilms) {

							DimensionsVector.push_back(film->getPosX());
						}
						int VectorCounter = 0;
						for (auto film : Shownfilms) {
							if (VectorCounter == DimensionsVector.size() - 1) {

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

				else if (widget->getPath() == "downButton.png") {
					
					if (searchBox->getDropButtonState() == false) {
						searchBox->setDropButton(true);
						forceFocus(widget);			// WHILE DropButtonState IS TRUE HOLDS FOCUS EVEN IF ANOTHER BUTTON IS HOVERED.
						
					}
					else {
						searchBox->setDropButton(false);
						
					}
				}
			}
		}
		else
		{
			widget->setSizeX(WIDGET_WIDTH / 3);
			widget->setSizeY(WIDGET_HEIGHT / 3);
			if (requestFocus(widget) && searchBox->getDropButtonState() == false) {			// RELEASE FOCUS ONLY IF THE MOUSE ISN'T HOVERING OVER THE OBJECT THAT CURRENTLY HAS THE FOCUS
				releaseFocus();																		// AND SEARCH BOX ISN'T ON THE CANVAS( DROPBUTTONSTATE == FALSE).
			}
		}
	} // BUTTONS FOR() ENDS HERE --------

	searchBox->update();

	search_str = search_string;		// stores the search_string so it can be used in the next loop to check if it has changed or it's still the same.

} // updateAppScreen() ends here --------


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
} // requestFocus() ends here -------

void App::forceFocus(Widget* object_ptr) {
	focus = object_ptr;
}


bool App::searchFilmFields(Film* film, std::string str) {

	
	if (film->getActors().find(str) != std::string::npos) {
		return true;
	}
	else if (film->getGenre().find(str) != std::string::npos) {
		return true;
	}
	else if (film->getTitle().find(str) != std::string::npos) {
		return true;
	}
	else if (film->getDate().find(str) != std::string::npos) {
		return true;
	}
	else {
		return false;
	}


}

//search the films that the date of produce is between date FROM and date TO
bool App::searchFilmDate(Film* film, std::string from, std::string to)
{
		
	int Date = stol (film->getDate()); //casting string to integer
	int DateFrom = stol(from);
	int DateTo = stol(to);

	if (Date >= DateFrom && Date <= DateTo) {
		return true;
	}
	else if (from.empty() && !to.empty() && Date <= DateTo) {
		return true;
	}
	else if (!from.empty() && to.empty() && Date >= DateFrom) {
		return true;
	}
	else {
		return false;
	}
}


//Capitalize the first letter of each word in a string
string App::Capitalize_first_letter(std::string text)
{
	for (int x = 0; x < text.length(); x++)
	{
		
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}
	
	return text;
}

#pragma once
#include <list>
#include "widget.h"
#include "Film.h"
#include "Button.h"
#include <vector>
#include "textField.h"
#include "searchRect.h"
#include <string>
#include <iostream>
using namespace std;

class App {
	typedef enum { STATUS_START, STATUS_APP, STATUS_SEARCH } status_t;
	status_t status = STATUS_START;
	int counter = 0;
	std::vector<float> DimensionsVector;
	std::list<Film*> films;
	std::list<Film*> Shownfilms;
	std::vector<Button*> buttons;
	std::vector<textField*> textFields;
	bool drawText = false;
	std::string text;
	searchRect* searchBox;
	int ClearList;
	float x;
	float y;
	bool PlayMusic = false;
	Widget* focus = nullptr;
	std::string search_str;
	bool ListCounter = false;
	std::string cur_searchTo;
	std::string prv_searchTo;
	std::string cur_search;
	std::string prv_search;

public:
	void draw();
	void update();
	void init();
	bool requestFocus(Widget* object_ptr);		// TAKES FOCUS IF FOCUS == NULLPTR AND RETURNS TRUE (ALSO RETURNS TRUE IF OBJ. CURRENTLY HAS FOCUS).
	void forceFocus(Widget* object_ptr);		// TAKE FOCUS BY FORCE EVEN IF ANOTHER OBJECT HAS THE FOCUS.
	void inline releaseFocus() { focus = nullptr; }
	void drawStartScreen();
	void drawAppScreen();
	void updateStartScreen();
	void updateAppScreen();
	bool searchFilmFields(Film* film, std::string str);
	bool searchFilmDate(Film* film, std::string from,std::string to);
	//void drawSearchScreen();
	string Capitalize_first_letter(string text);
	
};
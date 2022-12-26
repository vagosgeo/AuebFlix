#pragma once
#include <list>
#include "widget.h"
#include "Film.h"
#include "Button.h"
#include <vector>
#include "textField.h"


class App {
	//typedef enum { STATUS_START, STATUS_APP, STATUS_SEARCH } status_t;
	//status_t status = STATUS_START;
	int counter = 0;
	std::vector<float> DimensionsVector;
	std::list<Film*> films;
	std::list<Button*> buttons;
	std::vector<textField*> textFields;
	
	float x;
	float y;
	Widget* focus = nullptr;


public:
	void draw();
	void update();
	void init();
	bool requestFocus(Widget* object_ptr);		// TAKES FOCUS IF FOCUS == NULLPTR AND RETURNS TRUE (ALSO RETURNS TRUE IF OBJ. CURRENTLY HAS FOCUS).
	void forceFocus(Widget* object_ptr);		// TAKE FOCUS BY FORCE EVEN IF ANOTHER OBJECT HAS THE FOCUS.
	void releaseFocus() { focus = nullptr; }
	void checkScanCodes();
	Film* get(std::list<Film*> films);
	//void drawStartScreen();
	//void drawAppScreen();
	//void drawSearchScreen();
	
};

#pragma once
#include <list>
#include "widget.h"
#include "Film.h"
#include "Button.h"


class App {
	//typedef enum { STATUS_START, STATUS_APP, STATUS_SEARCH } status_t;
	//status_t status = STATUS_START;
	int counter = 0;
	std::list<Film*> films;
	std::list<Button*> buttons;
	//static int m_focus;
	//bool focus = false;
	float x;
	float y;

public:
	void draw();
	void update();
	void init();
	//bool requestFocus();
	//void releasedFocus();
	//void drawStartScreen();
	//void drawAppScreen();
	//void drawSearchScreen();
	
};

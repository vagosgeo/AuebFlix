#pragma once
#include <list>
#include "widget.h"
#include "Film.h"


class App {

	std::list<Film*> films;

public:
	void draw();
	void update();
	void init();
	
};

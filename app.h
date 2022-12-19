#pragma once
#include <list>
#include "widget.h"


class App {

	std::list<Widget*> widgets;

public:
	void draw();
	void update();
	void init();
};

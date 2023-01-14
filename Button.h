#pragma once
#include "defines.h"
#include <string>
#include "widget.h"

class Button : public Widget {
	std::string ButtonPath;
	

public:
	void update();
	void draw();
	void setPath(std::string path);
	std::string getPath();
	void drawButton();


};

#pragma once
#include "widget.h"
#include <string>

class Film : public Widget {
	std::string IconPath;
	int counter;
	
public:
	void update();
	void draw();
	void setPath(int i);
	std::string getPath();
	


};
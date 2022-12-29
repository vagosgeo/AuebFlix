#pragma once
#include "widget.h"
#include <vector>

class textField : public Widget {

	std::vector<char> textFieldChars;
	float backSpace_timeCounter = 0;
	float chars_timeCounter = 0;
	
	

public :
	textField(float posx, float posy, float sizex, float sizey);
	void update();
	void draw();
	void checkScanCodes();
	std::string str = "";
};

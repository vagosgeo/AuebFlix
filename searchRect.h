#pragma once
#include "widget.h"
#include "textField.h"
#include <vector>
#include"textField.h"
#include "Button.h"


class searchRect : public Widget {

	bool dropButton_pressed = false;
	textField* field;
	std::vector<Button*> Rectbuttons;
	std::string Search;
	float init_from_posx;
	float init_from_posy;
	float init_to_posx;
	float init_to_posy;
	float cur_from_posx;
	float cur_from_posy;
	float cur_to_posx;
	float cur_to_posy;
	std::string DateSearchFrom;
	std::string DateSearchTo;
	int counterFirstX = 0;
	int counterFirstY = 0;
	bool colorButton = false;
	std::string Buttoncolor;
	

public :
	searchRect();
	void draw();
	void update();
	void setDropButton(bool b) { dropButton_pressed = b; }
	bool getDropButtonState() { return dropButton_pressed; }
	inline textField* getTextField() { return field; }
	std::string getSearch() { return Search; }
	std::string getDateSearchFrom() { return DateSearchFrom; }
	std::string getDateSearchTo() { return DateSearchTo; }
	void init();
};

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
	
	

public :
	searchRect();
	void draw();
	void update();
	void setDropButton(bool b) { dropButton_pressed = b; }
	bool getDropButtonState() { return dropButton_pressed; }
	inline textField* getTextField() { return field; }
	const std::string & getSearch() { return Search; }
	void init();
};

#pragma once
#include "widget.h"
#include "textField.h"
#include <vector>
#include"textField.h"


class searchRect : public Widget {

	bool dropButton_pressed = false;
	textField* field;
	

public :
	searchRect();
	void draw();
	void update();
	void setDropButton(bool b) { dropButton_pressed = b; }
	bool getDropButtonState() { return dropButton_pressed; }
	inline textField* getTextField() { return field; }
};

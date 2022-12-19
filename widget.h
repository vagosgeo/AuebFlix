#pragma once
#include <string>

class Widget {
	std::string PHOTO_PATH;
;	float w_pos[2];
	float w_color[3];
	std::string colour[4]
		= { "ANewHope.png", "EmpireStrikesBack.png", "FightClub.png", "Godfather.png" };
	bool w_highlighted = false;

public:
	void draw();
	void update();
	std::string setPath(int i);
	float getPosX() { return w_pos[0]; }
	float getPosY() { return w_pos[1]; }
	void setPosX(float x) { w_pos[0] = x; }
	void setPosY(float y) { w_pos[1] = y; }
	void setHighlight(bool h ) { w_highlighted = h; }
	bool contains(float x, float y);
};

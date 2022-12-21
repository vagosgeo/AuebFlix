#pragma once
#include <stdlib.h>
#include <string>


#define CANVAS_WIDTH 1000.0f
#define CANVAS_HEIGHT 500.0f

#define WIDGET_HEIGHT 170.0f
#define WIDGET_WIDTH 120.0f
#define PHOTO "ANewHope.png" 
#define PHOTO1 "EmpireStrikesBack.png"
#define PHOTO2 "FightClub.png"
#define PHOTO3 "Godfather.png"
#define PHOTO4 "ANewHope.png"
#define PHOTO5 "ANewHope.png"
#define PHOTO6 "ANewHope.png"
#define LButton "LButton.png"
#define RButton "RButton.png"




#define ASSET_PATH ".\\assets\\"
#define SETCOLOR(c,r,g,b) {c[0] = r; c[1] = g; c[2] = b;} 

inline float distance(float x1, float y1, float x2, float y2) {
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}
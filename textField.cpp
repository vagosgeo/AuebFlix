#include "textField.h"
#include "graphics.h"
#include <iostream>


textField::textField(float posx, float posy, float sizex, float sizey)
{
	setPosX(posx);
	setPosY(posy);
	setSizeX(sizex);
	setSizeY(sizey);

}
void textField::update(){

}

void textField::draw() {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.outline_opacity = 1.0f;
	
	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);		// DRAWS A BLANK TEXT FIELD.

	
	for (char ch : textFieldChars) {
		if (str.size() < 1) {									// IF str.size = 0 THEN  str += ch.
			str += ch;
			chars_timeCounter = graphics::getGlobalTime();		//GETS GLOBAL TIME SO WE CAN HANDLE INPUT BY ms THAT PASSED SINCE WE STARTED THE PROGRAMM.
		}     
		else if (str[str.size() - 1] != ch) {					//IF THE LAST CHAR OF str  IS DIFFERENT THAN THE NEW INPUT -> str += ch
			str += ch;
			chars_timeCounter = graphics::getGlobalTime();
		}
		else {
			if (graphics::getGlobalTime() - chars_timeCounter > 180.0f) {		// IF THE LAST CHAR OF str IS THE SAME AS THE NEW INPUT 
				str += ch;														// AND 180 ms HAVE PASSED THEN PRINT IT . ELSE DONT PRINT ANYTHING.
				chars_timeCounter = graphics::getGlobalTime();
			}
		}
		 
	}
	int vector_size = textFieldChars.size();
	textFieldChars.clear();					// CLEARS VECTOR SO IT DOESNT TAKE TOO MUCH MEMORY SPACE.( THE PRINTED STRING IS IN THE 'str' VARIABLE).
	

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	
	graphics::drawText(getPosX()-80, getPosY()+10, 18, str, br);

}

void textField::checkScanCodes() {			// CHECKS IF ANY ANY KEY OF THE KEYBOARD IS PRESSED.

	if (graphics::getKeyState(graphics::SCANCODE_A)) {
		textFieldChars.push_back('a');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_B)) {
		textFieldChars.push_back('b');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_C)) {
		textFieldChars.push_back('c');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_D)) {
		textFieldChars.push_back('d');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_E)) {
		textFieldChars.push_back('e');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_F)) {
		textFieldChars.push_back('f');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_G)) {
		textFieldChars.push_back('g');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_H)) {
		textFieldChars.push_back('h');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_I)) {
		textFieldChars.push_back('i');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_J)) {
		textFieldChars.push_back('j');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_K)) {
		textFieldChars.push_back('k');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_L)) {
		textFieldChars.push_back('l');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_M)) {
		textFieldChars.push_back('m');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_N)) {
		textFieldChars.push_back('n');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_O)) {
		textFieldChars.push_back('o');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_P)) {
		textFieldChars.push_back('p');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_Q)) {
		textFieldChars.push_back('q');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_R)) {
		textFieldChars.push_back('r');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_S)) {
		textFieldChars.push_back('s');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_T)) {
		textFieldChars.push_back('t');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_U)) {
		textFieldChars.push_back('u');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_V)) {
		textFieldChars.push_back('v');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_W)) {
		textFieldChars.push_back('w');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_X)) {
		textFieldChars.push_back('x');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_Y)) {
		textFieldChars.push_back('y');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_Z)) {
		textFieldChars.push_back('z');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_0)) {
		textFieldChars.push_back('0');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_1)) {
		textFieldChars.push_back('1');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_2)) {
		textFieldChars.push_back('2');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_3)) {
		textFieldChars.push_back('3');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_4)) {
		textFieldChars.push_back('4');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_5)) {
		textFieldChars.push_back('5');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_6)) {
		textFieldChars.push_back('6');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_7)) {
		textFieldChars.push_back('7');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_8)) {
		textFieldChars.push_back('8');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_9)) {
		textFieldChars.push_back('9');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		textFieldChars.push_back(' ');
	}
	else if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {
		if (str.size() > 0 && backSpace_timeCounter == 0) {		// IF ITS THE FIRTS TIME 'BACKSPACE' IS PRESSED THEN POP THE LAST ITEM
			str.pop_back();									
			backSpace_timeCounter = graphics::getGlobalTime();				// SET TIMECOUNTER AS THE CURRENT GLOBAL TIME
		}
		else if (backSpace_timeCounter != 0 && str.size() > 0) {
			if (graphics::getGlobalTime() - backSpace_timeCounter > 180.f) {		// POP THE NEXT ITEM ONLY IF 300ms(0.3 seconds) HAVE PASSED 
				str.pop_back();								// (IF THE CURRENT GLOBALTIME - THE PREVIOUS GLOBAL TIME > 0.3ms THEN REMOVE THE NEXT ITEM) 
				
				backSpace_timeCounter = graphics::getGlobalTime();				// SET TIMECOUNTER AS THE CURRENT GLOBAL TIME 
			}
		}

		
	}
}
#include "searchRect.h"
#include "graphics.h"




searchRect::searchRect()
{
	field = new textField(400, -300, 170, 30);
}

void searchRect::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.2f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.outline_opacity = 0.5f;
	br.gradient = true;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 0.0f;
	br.fill_secondary_color[2] = 0.0f;
	
	br.fill_opacity = 2.0f;
	br.fill_secondary_opacity = 1.f;

	graphics::drawRect(getPosX(), getPosY(), getSizeX(), getSizeY(), br);

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.gradient = false;
	
	graphics::drawText(getPosX()-50, getPosY()-160.0f, 30.0f, "Filters", br);

	
	field->draw();
	
}

void searchRect::update()
{

	if (getDropButtonState() == true) {		// IF DOWN BUTTON IS PRESSED THEN FETCH THE SEARCH BOX FROM THE UPPER BOUND.(APPEAR)

		if (getPosY() < 250) {
			setPosY(getPosY() + graphics::getDeltaTime() / 2);
											
			field -> setPosY(field -> getPosY() + graphics::getDeltaTime() / 2);	// Also fetch the textField that exist on the search box.
			
		}

	}
	else {												// IF DOWN BUTTON IS DE-PRESSED THEN PUT THE SEARCH BOX ABOVE THE UPPER BOUND.(DISSAPPEAR)

		if (getPosY() > -200) {
			setPosY(getPosY() - graphics::getDeltaTime() / 2);
					
			field->setPosY(field->getPosY() - graphics::getDeltaTime() / 2);	// Also takes away the textFields with the search box.
			
		}
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	if (field->contains(mx, my) ) {
		field->checkScanCodes();
	}
	

}

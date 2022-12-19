#include "graphics.h"
#include "defines.h"
#include <string>
#include "app.h"

void draw() {
	App* myapp = (App*)graphics::getUserData();
	myapp->draw();
}

void update(float ms) {
	//App* myapp = reinterpret_cast<App*>(graphics::getUserData());
	//myapp->update();
}

int main(int argc, char** argv) {
	graphics::createWindow(800, 600, "AuebFlix");
	App* myapp = new App();
	myapp->init();
	graphics::setUserData(myapp);
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();

	return 0;
}
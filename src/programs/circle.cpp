#include "circle.h"

void Circle::start() {}

void Circle::update() {
	M5.Display.fillCircle(M5.Display.width() / 2, M5.Display.height() / 2, 5, TFT_RED);
}

void Circle::end() {}



#include "system.h"

System* sys;

void setup() {
	sys = new System();
	Serial.begin(155200);
}

void loop() {
	sys->update();
}




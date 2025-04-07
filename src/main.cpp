#include "system.h"

System* sys;

void setup() {
	sys = new System();
	Serial.begin(155200);
	Serial.println("Main started");
}

void loop() {
    if (sys) {
		Serial.println("Sys updated");
		sys->update();
	} else {
		Serial.println("Sys not detected");
	}
}


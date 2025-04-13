#include "system.h"

System* sys;

void setup() {
	sys = new System();
}

void loop() {
	sys->update();
}




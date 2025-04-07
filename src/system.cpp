#include "system.h"

System::System() {
	Serial.println("System constructor begin");
	auto cfg = M5.config();
	M5.begin(cfg);
	Serial.begin(155200);
	Serial.println("Initialized M5 and Serial");

	applications.push_back({"Circle", "Fun", new Circle(this)});
	Serial.println("Created application");
	
	if (!applications.empty()) {
		current_program = &applications[0];
		Serial.println("Set current application");
		current_program->program->start();
		Serial.println("Run current application start function");
	} else {
		Serial.println("No applications found");
	}
}

System::~System() {
	for (auto& app : applications) {
		delete app.program;
	}
}

void System::update() {
	if (current_program && current_program->program) {
		current_program->program->update();	
		Serial.println("Updating current program");
	} else {
		Serial.println("Null current_program or program");
	}
}


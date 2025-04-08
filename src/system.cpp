#include "system.h"

System::System() {
	auto cfg = M5.config();
	M5.begin(cfg);
	Serial.begin(155200);

	applications.push_back({"Circle", "Fun", new Circle(this)});
	
	current_program = &applications[0];
	current_program->program->start();
}

System::~System() {
	for (auto& app : applications) {
		delete app.program;
	}
}

void System::update() {
    current_program->program->update();	
}

void System::startApplication(std::string name) {
    for (auto& app : applications) {
        if (app.name == name) {
            current_program->program->end();
		    current_program = &app;
		    current_program->program->start();
            break;
        }
    }
}


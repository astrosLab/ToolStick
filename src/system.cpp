#include "system.h"

System::System() {
	auto cfg = M5.config();
	M5.begin(cfg);
	Serial.begin(155200);

	applications.push_back({"Circle", "Fun", new Circle(this)});
    services.push_back({"CircleService", "Fun", new CircleService(this)});
	
	current_program = &applications[0];
	current_program->program->start();

    toggleService("CircleService", false);
}

System::~System() {
	for (auto& app : applications) {
		delete app.program;
	}
}

void System::update() {
    current_program->program->update();	
    
    for (auto& service : services) {
        if (service.enabled == true) {
            service.program->update();
        }
    }

    delay(1);
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

void System::toggleService(std::string name, bool state) {
    for (auto& service : services) {
        if (service.name == name) {
            if (state != service.enabled) {
                if (state == true)
                    service.program->start();
                else
                    service.program->end();
            }

            service.enabled = state;
        }
    }
}


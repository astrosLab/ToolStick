#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include "programs/program.h"
#include "programs/circle.h"
#include "M5StickCPlus2.h"

class System {
public:
	System();
	~System();

	void update();

	void startProgram(std::string name);
	void toggleProgram(std::string name, bool state);
private:
	struct Service {
		std::string name;
		std::string type;
		Program* program;
		bool enabled;
	};

	struct App {
		std::string name;
		std::string type;
		Program* program;
	};

	std::vector<App> applications;
	std::vector<Service> services;
	App* current_program;
};

#endif // SYSTEM_H

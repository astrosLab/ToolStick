#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include "programs/program.h"
#include "programs/circle.h"
#include "programs/circle_service.h"
#include "programs/menu.h"
#include "M5StickCPlus2.h"

class System {
public:
	struct Service {
		std::string name;
		std::string type;
		Program* program;
		bool enabled;
		bool hidden;
	};

	struct App {
		std::string name;
		std::string type;
		Program* program;
		bool hidden;
	};

	System();
	~System();

	void update();

	void startApplication(std::string name);
	void toggleService(std::string name, bool state);

	App getApplication(std::string name);
	std::vector<App> getApplications();
	Service getService(std::string name);
	std::vector<Service> getServices();
private:	
	std::vector<App> applications;
	std::vector<Service> services;
	App* current_program;
};

#endif // SYSTEM_H

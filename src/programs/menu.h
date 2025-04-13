#ifndef MENU_H
#define MENU_H

#include "M5StickCPlus2.h"
#include "program.h"
#include "../system.h"

class Menu : public Program {
public:
	Menu(System* system): Program(system) {};

	void start() override;
	void update() override;
	void end() override;
	
	void drawMainMenu();
	void drawSubMenu();
	void drawCurrentMenu();
	void drawBatteryLevel();
private:
	struct Category {
		std::string name;
		std::vector<Program*> programs;
	};

	std::vector<Category> categories;
	int selectedCategory;
	int selectedItem;
	std::string currentMenu;
	bool needsRedraw;
    int currentBatteryLevel;
    int lastBatteryLevel; 
};

#endif // MENU_H

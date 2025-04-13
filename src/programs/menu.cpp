#include "menu.h"

void Menu::start() {
	M5.Display.setRotation(3);
	M5.Display.setTextColor(WHITE);
	M5.Display.setTextDatum(middle_center);
	M5.Display.setFont(&fonts::TomThumb);
	M5.Display.setTextSize(4);
	M5.Display.setBrightness(10);

	needsRedraw = true;

	categories = {
		{"Wireless"},
		{"Tools"},
		{"Fun"},
		{"Time"},
		{"Games"},
		{"Settings"},
	};
	selectedCategory = 0;
	selectedItem = 0;
	currentMenu = "Main";

    currentBatteryLevel = 0;
    lastBatteryLevel = 0;

	for (auto& app : system->getApplications()) {
		if (app.hidden) continue;

		for (auto& category : categories) {
			if (app.type == category.name) {
				category.programs.push_back(app.program);
				break;
			}
		}
	}

	for (auto& service : system->getServices()) {
		if (service.hidden) continue;

		for (auto& category : categories) {
			if (service.type == category.name) {
				category.programs.push_back(service.program);
				break;
			}
		}
	}

	drawMainMenu();
}

int wrappedIndex(int index, int size) {
	if (index < 0) {
		return index + size;
	}

	if (index > size - 1) {
		return index - size;
	}

	return index;
}

void Menu::drawBatteryLevel() {
	int level = map(currentBatteryLevel, 100, 0, 0, M5.Display.height());

	int r = map(currentBatteryLevel, 100, 0, 0, 255);
	int g = map(currentBatteryLevel, 100, 0, 255, 0);

	M5.Display.fillRect(0, 0, 5, M5.Display.height(), TFT_DARKGREY);
	M5.Display.fillRect(0, level, 5, M5.Display.height(), M5.Display.color888(r, g, 0));
}

void Menu::drawMainMenu() {
	M5.Display.setTextColor(WHITE);
	M5.Display.setTextDatum(middle_center);
	M5.Display.setFont(&fonts::TomThumb);
	M5.Display.setTextSize(4);

	selectedCategory = wrappedIndex(selectedCategory, categories.size()); 

	int y = (M5.Display.height() / 3) - (M5.Display.height() / 6);

	for (int i = -1; i < 2; i++) {
		int index = selectedCategory + i;
		std::string name = categories[wrappedIndex(index, categories.size())].name;
		int x = (M5.Display.width() / 2) - (M5.Display.textWidth(name.c_str()) / 2);

		if (i == 0) {
			M5.Display.setTextColor(WHITE);
		} else {
			M5.Display.setTextColor(TFT_DARKGREY);
		}

		M5.Display.setCursor(x, y);
		M5.Display.printf(name.c_str());

		y += M5.Display.height() / 3;
	}

	M5.Display.setTextColor(WHITE);
	drawBatteryLevel();
}

void Menu::drawSubMenu() {
	M5.Display.setTextColor(WHITE);
	M5.Display.setTextDatum(middle_center);
	M5.Display.setFont(&fonts::TomThumb);
	M5.Display.setTextSize(2);

	M5.Display.setCursor(0, 10);
	M5.Display.println(categories[selectedItem].name.c_str());
}

void Menu::drawCurrentMenu() {
	if (currentMenu == "Main") {
		drawMainMenu();
	} else {
		drawSubMenu();
	}
}

void Menu::update() {
	M5.update();
    
    Battery* batteryService = (Battery*)(system->getService("Battery").program);
    lastBatteryLevel = currentBatteryLevel;
    currentBatteryLevel = batteryService->getBatteryLevel();

    if (currentBatteryLevel != lastBatteryLevel) {
        needsRedraw = true;
    } 

	if (M5.BtnA.wasPressed()) {
		currentMenu = categories[selectedCategory].name;	
		needsRedraw = true;
	}

	if (M5.BtnB.wasPressed()) {
		selectedCategory++;
		needsRedraw = true;
	}

	if (M5.BtnPWR.wasPressed()) {
		selectedCategory--;
		needsRedraw = true;
	}

	if (needsRedraw == true) {
		M5.Display.clear();
		drawCurrentMenu();
		needsRedraw = false;
	}
}

void Menu::end() {}


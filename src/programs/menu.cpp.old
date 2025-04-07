#include "menu.h"
#include "M5StickCPlus2.h"

Menu::Menu() {
    width = M5.Display.width();
    height = M5.Display.height();
}

void Menu::setup() {
    M5.Display.setRotation(3);
    M5.Display.setTextDatum(middle_center);
    M5.Display.setFont(&fonts::FreeMonoBold24pt7b);
    M5.Display.setTextSize(0.6);
}

void Menu::update() {
    M5.update();
    for (int i = 0; i < categories.size(); i++) {
        M5.Display.setCursor(0, 20 + i * 10);
        M5.Display.println(categories.at(i).name);
    }
}

void Menu::addCategory(std::string name) {
    categories.push_back(Category(name));
}


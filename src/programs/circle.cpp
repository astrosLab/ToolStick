#include "circle.h"

void Circle::start() {
    uint16_t color = rand();
    M5.Display.fillCircle(M5.Display.width() / 2, M5.Display.height() / 2, 10, color);
}

void Circle::update() {
    M5.update();

    if (M5.BtnA.wasPressed()) {
        service_toggled = !service_toggled;
        system->toggleService(std::string("CircleService"), service_toggled);
    }
}

void Circle::end() {}



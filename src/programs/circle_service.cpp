#include "circle_service.h"

void CircleService::start() {
    delay_count = 0;
}

void CircleService::update() {
    if (delay_count == 1000) {
        system->startApplication(std::string("Circle"));
        delay_count = 0;
    }
    delay_count++;
}

void CircleService::end() {}


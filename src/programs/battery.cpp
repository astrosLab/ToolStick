#include "battery.h"

const int BATTERY_UPDATE_INTERVAL = 10000;

void Battery::start() {
    battery_levels.clear();
    battery_level = 0;
    cycle_delay = 0;

    newBatteryEntry();
}

void Battery::update() {
    cycle_delay++;
    if (cycle_delay >= BATTERY_UPDATE_INTERVAL) {
        newBatteryEntry();    

        cycle_delay = 0;
    }
}

void Battery::end() {}

void Battery::newBatteryEntry() {
    battery_levels.push_back(M5.Power.getBatteryLevel());
    if (battery_levels.size() > 10) {
        battery_levels.erase(battery_levels.begin());
    }
}

int Battery::getBatteryLevel() {
    int maximum = 50;
    for (int level : battery_levels) {
        if (level > maximum) {
            maximum = level;
        }
    }
    return maximum;
}


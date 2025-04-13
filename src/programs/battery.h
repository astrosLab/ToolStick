#ifndef BATTERY_H
#define BATTERY_H

#include "M5StickCPlus2.h"
#include "program.h"
#include "../system.h"

class Battery : public Program {
public:
    Battery(System* system) : Program(system) {};

    void start() override;
    void update() override;
    void end() override;
    void newBatteryEntry();

    int getBatteryLevel();
private:
    std::vector<int> battery_levels;
    int battery_level;
    int cycle_delay;
};

#endif // BATTERY_H

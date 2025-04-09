#ifndef CIRCLE_SERVICE_H
#define CIRCLE_SERVICE_H

#include "program.h"
#include "../system.h"

class CircleService : public Program {
public:
    CircleService(System* system) : Program(system) {};
    
    void start() override;
    void update() override;
    void end() override;
private:
    int delay_count;
};

#endif // CIRCLE_SERVICE_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "M5StickCPlus2.h"
#include "program.h"

class Circle : public Program {
public:
	Circle(System* system) : Program(system) {};

	void start() override;
	void update() override;
	void end() override;
};

#endif // CIRCLE_H

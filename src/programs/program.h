#ifndef PROGRAM_H
#define PROGRAM_H

class System;

class Program {
public:
	Program(System* system) : system(system) {};
	virtual ~Program() {};

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void end() = 0;
protected:
	System* system;
};

#endif // PROGRAM_H

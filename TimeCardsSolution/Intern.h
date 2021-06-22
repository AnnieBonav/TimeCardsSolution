#pragma once
#include "Worker.h"

class Intern : public Worker {
private:
	std::string internType;
	int duration; //Works mnths duration

public:
	//constructors
	Intern();
	Intern(std::string, std::string, int, std::string, float, int); //userId, name, age, workArea, salary, duration
	~Intern();

	//GETTERS
	int getDuration();
	std::string getInternType();

	//SETTERS
	void setInternType(std::string);
	void setDuration(int);

	//OTHER
	void show();
};


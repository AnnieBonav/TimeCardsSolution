#pragma once
#include "Worker.h"
class FTW : public Worker { //Full-time-worker Class
private:
	std::string FTWtype;
	int yearsWorked;

public:
	FTW();
	FTW(std::string, std::string, int, std::string, float, std::string, int); //userId, name, age, workArea, salary, FTWtype, yearsworked
	~FTW();

	//GETTERS
	std::string getFTWtype();
	int getYearsWorked();

	//STTERS
	void setFTWtype(std::string);
	void setYearsWorked(int);

	//OTHER
	virtual void show();

};


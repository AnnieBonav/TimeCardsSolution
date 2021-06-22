#pragma once
#include "Worker.h"
class FTW : public Worker { //Full-time-worker Class
private:
	std::string FTWType;
	int yearsWorked;

public:
	FTW();
	FTW(std::string, std::string, int, std::string, float, int);
	~FTW();

	//GETTERS
	std::string getFTWType();
	int getYearsWorked();

	//STTERS
	void setFTWType(std::string);
	void setYearsWorked(int);

	//OTHER
	void show();

};


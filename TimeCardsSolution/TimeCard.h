#pragma once
#include "Time.h"

class TimeCard {
private:
	Time initialTime, finalTime;
	std::string userId;
	int timeCardIndex;

public:
	TimeCard();
	TimeCard(int, std::string, Time, Time); //Time cardIndex, userId Initial Time, Final Time
	TimeCard(int, std::string, int, int, int, int); //Time card index, userId, initial Minute, initial hour, finalMinute, finalHour
	~TimeCard();

	//GETTERS
	std::string getuserId();
	Time getInitialTime();
	Time getFinalTime();
	int getTimeCardIndex(); //Time card index does not have a set property, as it is read-only

	//SETTERS
	void setuserId(std::string);
	void setInitialTime(Time);
	void setFinalTime(Time);

	//OTHER
	virtual void show();

	//OPERATOR OVERCHARGE

};


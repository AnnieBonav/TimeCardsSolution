#pragma once
#include "Time.h"

class TimeCard {
private:
	Time initialTime, finalTime;
	int userIndex, timeCardIndex;

public:
	TimeCard();
	TimeCard(int, int, Time, Time); //User Index, cardIndex, Initial Time, Final Time
	~TimeCard();

	//GETTERS
	int getUserIndex();
	Time getInitialTime();
	Time getFinalTime();
	int getTimeCardIndex(); //Time card index does not have a set property, as it is read-only

	//SETTERS
	void setUserIndex(int);
	void setInitialTime(Time);
	void setFinalTime(Time);

	//OTHER
	void show();

	//OPERATOR OVERCHARGE

};


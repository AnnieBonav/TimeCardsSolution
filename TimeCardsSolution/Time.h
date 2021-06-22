#pragma once

#include <iostream>
#include <string>

class Time {
private:
	int minute, hour;

public:
	Time();
	Time(int, int); // hour : minute
	~Time();

	//GETTERS
	int getMinute();
	int getHour();

	//SETTERS
	void setMinute(int);
	void setHour(int);

	//OTHER
	virtual void show();

	//OPERATORS OVERCHARGE
	void operator=(Time);
};

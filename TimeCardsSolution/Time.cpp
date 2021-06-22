#include "Time.h"

Time::Time() {
	minute = 0;
	hour = 0;
}

Time::Time(int minute, int hour) {
	this->minute = minute;
	this->hour = hour;
}

Time::~Time() {
}

//GETTERS
int Time::getMinute() {
	return minute;
}

int Time::getHour() {
	return hour;
}

//SETTERS
void Time::setMinute(int minute) {
	if (minute >= 0 && minute < 60) {
		this->minute = minute;
	}
	else {
		std::cout << "\nMinute must be greater or equal than 0 and lower than 60\n";
	}
}

void Time::setHour(int hour) {
	if (hour >= 0 && hour < 24) {
		this->hour = hour;
	}
	else {
		std::cout << "\nMinute must be greater or equal than 0 and lower than 60\n";
	}
}

//OTHER
void Time::show() {
	std::cout << "\nThis is your time:" << "\nMinute: " << minute << "\nHour: " << hour;
}

//OPERATORS OVERCHARGE
void Time::operator=(Time time) {
	minute = time.getMinute();
	hour = time.getHour();
}
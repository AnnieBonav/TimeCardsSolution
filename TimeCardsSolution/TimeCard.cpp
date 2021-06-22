#include "TimeCard.h"

TimeCard::TimeCard() {
	timeCardIndex = 0;
	userId = "A00000000";
}

TimeCard::TimeCard(int timeCardIndex, std::string userIndex, Time initialTime, Time finalTime) {
	this->timeCardIndex = timeCardIndex;
	this->userId = userIndex;
	this->initialTime = initialTime;
	this->finalTime = finalTime;
}

TimeCard::TimeCard(int timeCardIndex, std::string usrId, int initMinute, int initHour, int finalMinute, int finalHour) {
	Time t1(initMinute, initHour);
	Time t2(finalMinute, finalHour);

	this->timeCardIndex = timeCardIndex;
	this->userId = userId;
	this->initialTime = t1;
	this->finalTime = t2;
}

TimeCard::~TimeCard() {

}

//GETTERS
std::string TimeCard::getuserId() {
	return userId;
}

Time TimeCard::getInitialTime() {
	return initialTime;
}

Time TimeCard::getFinalTime() {
	return finalTime;
}

int TimeCard::getTimeCardIndex() {
	return timeCardIndex;
}

//SETTEERS
void TimeCard::setuserId(std::string userId) {
	this->userId = userId;
}

void TimeCard::setInitialTime(Time initialTime) {
	this->initialTime = initialTime;
}

void TimeCard::setFinalTime(Time finalTime) {
	this->finalTime = finalTime;
}

//OTHER
void TimeCard::show() {
	std::cout << "\n\nTIME CARD #" << timeCardIndex << "\nUser Index: " << userId << "\nInitial time	";
	initialTime.show();
	std::cout << "\nFinal time	";
	finalTime.show();
}

//OPERATOR OVERCHARGE
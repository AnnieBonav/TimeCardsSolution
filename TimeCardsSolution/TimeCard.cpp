#include "TimeCard.h"

TimeCard::TimeCard() {
	userIndex = 0;
}

TimeCard::TimeCard(int userIndex, int timeCardIndex, Time initialTime, Time finalTime) {
	this->userIndex = userIndex;
	this->timeCardIndex = timeCardIndex;
	this->initialTime = initialTime;
	this->finalTime = finalTime;
}

TimeCard::~TimeCard() {

}

//GETTERS
int TimeCard::getUserIndex() {
	return userIndex;
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
void TimeCard::setUserIndex(int userIndex) {
	this->userIndex = userIndex;
}

void TimeCard::setInitialTime(Time initialTime) {
	this->initialTime = initialTime;
}

void TimeCard::setFinalTime(Time finalTime) {
	this->finalTime = finalTime;
}

//OTHER
void TimeCard::show() {
	std::cout << "\nTIME CARD" << "\nUser Index: " << userIndex << "\nINITIAL";
	initialTime.show();
	std::cout << "\nFINAL";
	finalTime.show();
}

//OPERATOR OVERCHARGE
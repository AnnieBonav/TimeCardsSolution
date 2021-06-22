#include "User.h"

User::User() {
	userId = "A0000";
	name = "Unknown Name";
	age = 0;
}

User::User(std::string userId, std::string name, int age) {
	this->userId = userId;
	this->name = name;
	this->age = age;
}

User::~User() {

}

//GETTERS
std::string User::getUserId() {
	return userId;
}

std::string User::getName() {
	return name;
}

int User::getAge() {
	return age;
}


//SETTERS
void User::setUserId(std::string userId) {
	this->userId = userId;
}

void User::setName(std::string name) {
	this->name = name;
}

void User::setAge(int age) {
	this->age = age;
}

//OTHER
void User::show() {
	std::cout << "\n\nUSER" << "\nId: " << userId << "\nName: " << name << "\nAge: " << age;
}

//OPERATOR OVERCHARGE
void User::operator+=(int timeCardIndex) {
	myTimeCards.push_back(timeCardIndex);
}

std::ostream& operator<<(std::ostream& message, User& printUser) {
	message << "\n\nUSER" << "\nName: " << printUser.getName() << "\nAge: " << printUser.getAge();
	return message;
}
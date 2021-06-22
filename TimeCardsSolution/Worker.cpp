#include "Worker.h"
Worker::Worker() {
	workArea = "Undefined";
	salary = 0;
}

Worker::Worker(std::string userId, std::string name, int age, std::string workArea, float salary) : User(userId, name, age) {
	this->workArea = workArea;
	this->salary = salary;
}

Worker::~Worker() {
}

//GETTERS
std::string Worker::getWorkArea() {
	return workArea;
}

float Worker::getSalary() {
	return salary;
}

//SETTERS
void Worker::setWorkArea(std::string workArea) {
	this->workArea = workArea;
}
void Worker::setSalary(float salary) {
	this->salary = salary;
}

//OTHER
void Worker::show() {
	std::cout << "\n\nWORKER" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nWork Area: " << workArea << "\nSalary: " << salary;
}
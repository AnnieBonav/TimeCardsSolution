#include "Intern.h"

Intern::Intern() {
	duration = 0;
}

Intern::Intern(std::string userId, std::string name, int age, std::string workArea, float salary, int duration) : Worker(userId, name, age, workArea, salary) {//userId, name, age, workArea, salary, duration
	this->duration = duration;
}

Intern::~Intern() {

}

//GETTERS
std::string Intern::getInternType() {
	return internType;
}

int Intern::getDuration() {
	return duration;
}

//SETTERS
void Intern::setInternType(std::string internType) {
	this->internType = internType;
}

void Intern::setDuration(int duration) {
	this->duration = duration;
}

//OTHER
void Intern::show() {
	std::cout << "\nINTERN" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nWork Area:" << getWorkArea() << "\nSalary: " << getSalary() << "\nIntern Type: " << internType << "\nDuration: " << duration;
}
#include "Intern.h"

Intern::Intern() {
	internType = "Unknown Intern Type";
	duration = 0;
}

Intern::Intern(std::string userId, std::string name, int age, std::string workArea, float salary, std::string internType, int duration) : Worker(userId, name, age, workArea, salary) {//userId, name, age, workArea, salary, duration
	this->internType = internType;
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
	std::cout << "\n\nINTERN" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nWork Area: " << getWorkArea() << "\nSalary: " << getSalary() << "\nIntern Type: " << internType << "\nDuration: " << duration;
}
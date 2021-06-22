#include "Student.h"

Student::Student() {
	studyType = '0';
	programName = "N/A Study Type";
}

Student::Student(std::string userId, std::string name, int age, char studyType, std::string programName) : User(userId, name, age) {
	this->studyType = studyType;
	this->programName = programName;
}

Student::~Student() {

}

//GETTERS
char Student::getStudyType() {
	return studyType;
}

std::string Student::getProgramName() {
	return programName;
}

//SETTERS
void Student::setStudyType(char studyType) {
	this->studyType = studyType;
}

void Student::setProgramName(std::string programName) {
	this->programName = programName;
}

//OTHER
void Student::show() {
	std::cout << "\nSTUDENT" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nStudy Type:" << studyType << "\nProgram Name: " << programName;
}
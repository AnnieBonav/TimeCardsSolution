#include "FTW.h"

FTW::FTW() {
	FTWtype = "Unknwown FTW Type";
	yearsWorked = 0;
}

FTW::FTW(std::string userId, std::string name, int age, std::string workArea, float salary, std::string FTWtype, int yearsWorked) : Worker(userId, name, age, workArea, salary) {//userId, name, age, workArea, salary, yearsWorked
	this->FTWtype = FTWtype;
	this->yearsWorked = yearsWorked;
}

FTW::~FTW() {

}

//GETTERS
std::string FTW::getFTWtype() {
	return FTWtype;
}

int FTW::getYearsWorked() {
	return yearsWorked;
}

//SETTERS
void FTW::setFTWtype(std::string FTWtype) {
	this->FTWtype = FTWtype;
}

void FTW::setYearsWorked(int yearsWorked) {
	this->yearsWorked = yearsWorked;
}

//OTHER
void FTW::show() {
	std::cout << "\n\nFULL-TIME WORKER" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nWork Area:" << getWorkArea() << "\nSalary: " << getSalary() << "\nWorker Type: " << FTWtype << "\nYears Worked: " << yearsWorked;
}
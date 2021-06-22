#include "FTW.h"

FTW::FTW() {
	yearsWorked = 0;
}

FTW::FTW(std::string userId, std::string name, int age, std::string workArea, float salary, int yearsWorked) : Worker(userId, name, age, workArea, salary) {//userId, name, age, workArea, salary, yearsWorked
	this->yearsWorked = yearsWorked;
}

FTW::~FTW() {

}

//GETTERS
std::string FTW::getFTWType() {
	return FTWType;
}

int FTW::getYearsWorked() {
	return yearsWorked;
}

//SETTERS
void FTW::setFTWType(std::string FTWType) {
	this->FTWType = FTWType;
}

void FTW::setYearsWorked(int yearsWorked) {
	this->yearsWorked = yearsWorked;
}

//OTHER
void FTW::show() {
	std::cout << "\nFULL-TIME WORKER" << "\nId: " << getUserId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nWork Area:" << getWorkArea() << "\nSalary: " << getSalary() << "\nWorker Type: " << FTWType << "\Years Worked: " << yearsWorked;
}
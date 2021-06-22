#pragma once
#include "User.h"
class Worker : public User {
private:
	std::string workArea;
	float salary; //PEr month

public:
	Worker();
	Worker(std::string, std::string, int, std::string, float); //userId, name, age, workArea, salary
	~Worker();

	//GETTERS
	std::string getWorkArea();
	float getSalary();

	//SETTERS
	void setWorkArea(std::string);
	void setSalary(float);

	//OTHER
	void show();
};


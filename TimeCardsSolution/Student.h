#pragma once
#include "User.h"
class Student : public User {
private:
	char studyType;
	std::string programName;

public:
	Student();
	Student(std::string, std::string, int, char, std::string);
	~Student();

	//GETTERS
	char getStudyType();
	std::string getProgramName();

	//SETTERS
	void setStudyType(char);
	void setProgramName(std::string);

	//OTHER
	virtual void show();
};


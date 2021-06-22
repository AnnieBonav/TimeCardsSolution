#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class User {
private:
	std::string name, userId;
	int age;
	std::vector <int> myTimeCards;

public:
	User();
	User(std::string, std::string, int); //userId, name, age, 
	~User();

	//GETTERS
	std::string getUserId();
	std::string getName();
	int getAge();

	//SETTERS
	void setUserId(std::string);
	void setName(std::string);
	void setAge(int);

	//OTHER
	virtual void show();

	//OPERATOR OVERCHARGE
	void operator+=(int); //This adds a time Card to the User vector

	friend std::ostream& operator << (std::ostream&, User&);
};


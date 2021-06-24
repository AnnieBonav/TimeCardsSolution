#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <stdexcept>

#include "TimeCard.h"
#include "Intern.h"
#include "Student.h"
#include "FTW.h"
/*

This method is called by the fileName method. What it does it take the name that was sent
and, if it is able to open it (check existence) then it returns a true boolean and, if it
is not able to open it (if it does not exist) then it returns false, hence, the boolean
variable that controls while in fileName() does not change and the loop continues.

*/
bool validateFileExistence(std::string fileName) {
    std::ifstream myFile;
    myFile.open(fileName);
    if (myFile.fail()) {
        std::cout << "This file does  not exist. Please write another name.\n";
        return false;
    }
    else {
        return true;
    }

}

/*

This method starts a loop to validate a file name (using validateFileExistence() method)
If it can be opened then the returning bool value changes this method´s bool correctName
to true; if it is not true, then this remains false and the loop continues.

*/
std::string validateFileName() {
    std::string myFileName;
    bool correctName = false;

    while (correctName != true) {
        std::cout << "Please enter your file name (without .txt): ";
        std::cin >> myFileName;
        myFileName += ".txt";
        correctName = validateFileExistence(myFileName);
    }
    return myFileName;
}

/*

This method counts the lines of any existing file, it returns that counter ad an integer.
This helops then create an iteration to save the information of that file.

*/
int countLines(std::string fileName) {
    int lineNum = 0;
    std::string fileLine;
    std::ifstream myFile;

    myFile.open(fileName, std::ios::in);

    while (getline(myFile, fileLine)) {
        lineNum += 1;
    }

    myFile.close();
    return lineNum;
}

/*

This method checks that the user´s inpit is actually a number and not something else.

*/
bool isNumber(std::string number) {
    bool validNumber = true;
    try {
        stoi(number);
    } catch (...) {
        validNumber = false;
        std::cout << "\nPlease remember that no letters or special characters are allowed.";
    }
    return validNumber; //This will return weather the input is a number or not
}

void useClasses() {
    Time t1;
    Time t2(44, 14);

    t1.show();
    t2.show();

    std::cout << "\n\nTIME CARDS\n";
    TimeCard tc1;
    TimeCard tc2(0, "A01423281", t1, t2);
    tc1.show();
    tc2.show();

    std::cout << "\n\nUSERS\n";
    User u1;
    User u2("A736489", "AnaBonavides", 19);
    u1.show();
    u2.show();

    std::cout << "\n\nWORKERS\n";
    Worker w1;
    Worker w2("A92648", "AguilarBonavides", 20, "DevDiv", 10);
    w1.show();
    w2.show();

    std::cout << "\n\nINTERNS\n";
    Intern i1;
    Intern i2("A92642", "AnnieBonav", 18, "Hololens", 11.5, "Explore", 3);
    i1.show();
    i2.show();

    FTW f1;
    FTW f2("A773826", "AguilarAna", 24, "DevDiv", 15.8, "Manager", 4);
    f1.show();
    f2.show();

    Student s1;
    Student s2("A837473", "BonavidesAnnie", 16, 'b', "ComputerScience");
    s1.show();
    s2.show();
}

/*

This function shows all the values inside a vector

*/
void showTimeCardVector(std::vector<TimeCard*> &timeCards, int timeCardsNum) {
    for (int i = 0; i < timeCardsNum; i++) {
        timeCards[i]->show();
    }
}

/*

This function shows all the values inside a vector

*/
void showUsersVector(std::vector<User*> &users, int usersNum) {
    for (int i = 0; i < usersNum; i++) {
        users[i]->show();
    }
}

/*

This function fills up my time Cards vector. I pass by reference the vector form the main function to this 
function.

*/

void fillTimeCardsInfo(std::string timeCardsFile, std::vector<TimeCard*> &timeCards, int timeCardsNum) {
    std::ifstream myFile;
    myFile.open(timeCardsFile, std::ios::in);

    std::string userId;
    int timeCardIndex, initMinute, initHour, finalMinute, finalHour;
    for (int i = 0; i < timeCardsNum; i++) {
        myFile >> timeCardIndex >> userId >> initMinute >> initHour >> finalMinute >> finalHour;
        timeCards.push_back(new TimeCard(timeCardIndex, userId, initMinute, initHour, finalMinute, finalHour));
    }
    myFile.close();
}

/*

This function fills up my users vector. I pass by reference the vector form the main function to this
function. What this does is check which is the first letter of the line in the document; That way, it can
assign the type of user that it is (from the inherited classes) and ask/save the other variables needed.

*/
void fillUsersVector(std::string usersFile, std::vector<User*> &users, int usersNum) {
    std::ifstream myFile;
    myFile.open(usersFile, std::ios::in);

    std::string userId, userName, workerWorkArea, studentProgramName, internType, FTWtype;
    int userAge, internDuration, FTWyearsWorked;
    float workerSalary;
    char studentStudyType, userType; //I use this to asign information to the corresponding subclass

    for (int i = 0; i < usersNum; i++) {
        myFile >> userType >> userId >> userName >> userAge;
        if (userType == 'u') {
            users.push_back(new User(userId, userName, userAge));
        }
        else if (userType == 'w') {
            myFile >> workerWorkArea >> workerSalary;
            users.push_back(new Worker(userId, userName, userAge, workerWorkArea, workerSalary));
        }
        else if (userType == 's') {
            myFile >> studentStudyType >> studentProgramName;
            users.push_back(new Student(userId, userName, userAge, studentStudyType, studentProgramName));
        }
        else if (userType == 'i') {
            myFile >> workerWorkArea >> workerSalary >> internType >> internDuration;
            users.push_back(new Intern(userId, userName, userAge, workerWorkArea, workerSalary, internType, internDuration));
        }
        else if (userType == 'f') {
            myFile >> workerWorkArea >> workerSalary >> FTWtype >> FTWyearsWorked;
            users.push_back(new FTW(userId, userName, userAge, workerWorkArea, workerSalary, FTWtype, FTWyearsWorked));
        }
    }

}

/*

What the boolean needsValidation sees is I want that number to go through validation or not. If that number is just
a part of a class or something, tyhen I do not need a validation. If it is used to choose a function, then I will
require a validation. I think I iwll also use this function (validate number) to validate the writen information
(when creating an instance of an object, for example). We will see

*/
int validateNumber(int min, int max, std::string numberType, bool needsValidation) { //Number type is in which metho dthe number is being asked
    bool validNumber = false, validChoice; /*ValidNumber is for the first while, validChoice is for the second 
    one. Could I use recursive?? Or something better??*/
    std::string stringNumber, validateAction;
    int validIntNum;
    while (validNumber != true) {
        validChoice = false;
        std::cout << "\nNumber: "; std::cin >> stringNumber;
        if (isNumber(stringNumber) == true) { /* This checks that the input is a number (through isNumber function
        which takes into account the input as a string. If it is a number, then the path continues. If it is not a
        number, then it just leaves the if and prints that 'no special characters or letters are allowed'.*/
            
            validIntNum = stoi(stringNumber); /*As I am now sure that the input is a number, then I can convert it
            to an integer with string to internet method. I do this making an integer variable 'validIntNum' to the result of
            stoi(stringNumber) value. With now I can now compare the integer to the minimum and maximum values.*/
            
            if (validIntNum >= min && validIntNum <= max) {/*This if checks that the value inserted (which we now
            are sure that is an integer) is greater or equal than the established minimum and lower or equal than
            the established maximum. If it checks the criteria, then we will ocntinue the path; If it does not,
            then */
                if (needsValidation == true) {
                    std::cout << "\nPlease enter 1 if you accept this information, 2 if you want to re-write it or 0 if you want to abort this action.\nChoice: ";
                    while (validChoice != true) {
                        std::cin >> validateAction;
                        if (validateAction == "1") {
                            std::cout << "\nThis is the number you chose: " << validIntNum << std::endl;
                            validChoice = true;
                            validNumber = true;
                        } else if (validateAction == "2") {
                            std::cout << "\nYou have decided to write another number for the " << numberType;
                            validChoice = true;
                        } else if (validateAction == "0") {
                            validIntNum = -1000;
                            validChoice = true;
                            validNumber = true;
                        }
                    }
                } else { //Needs validation == false
                    std::cout << "This is the number you chose: " << validIntNum;
                    validNumber = true;
                }
            } else { // validNum meets criteria
                std::cout << "\nRemember that your number must be greater or equal than " << min << " and lower or equal than " << max << ".";
            }
        } else { //Number is integer
            std::cout << " '" << stringNumber << "' is not a number.\n";
        }
    }
    return validIntNum;
}

char validateChar() {
    std::string myStringChar;
    char myChar;
    std::cout << "\nPlease enter your char: ";
    std::cin >> myStringChar;
    myChar = myStringChar[0];

    return myChar;
}

/*

SET FUNCTIONS

*/
void setTimeMinute(Time &time) {
    int minute = validateNumber(0, 59, "minute", true);
    if (minute == -1000) {
        std::cout << "You have decided to stop setting a Time's Minute";
    }else {
        time.setMinute(minute);
    }
}

void setTimeHour(Time& time) {
    int hour = validateNumber(1, 24, "minute", true);
    if (hour == -1000) {
        std::cout << "You have decided to stop setting the Time's Hour";
    } else {
        time.setMinute(hour);
    }
}


/*

CREATE FUNCTIONS

*/

Time createTime() {
    int minute, hour;
    std::string kind, number;
    bool validatedNum = false;
    minute = validateNumber(0, 59, "minute", false);
    hour = validateNumber(1, 24, "hour", false);

    Time time(hour, minute);

    return time;
}


void createStudent(std::vector<User*>& users, std::string userId, std::string userName, int userAge) {
    std::string userType = "s", studentProgramName = "";
    char studentStudyType = ' ';
    
    studentStudyType = validateChar();
    std::cout << "Program Name: ";
    std::cin >> studentProgramName;
    
    users.push_back(new Student(userId, userName, userAge, studentStudyType, studentProgramName));
}

/*

This function creates an intern using as base the information recollected from both the userCreation method and
the workerCreation one.

*/
void createIntern(std::vector<User*>& users, std::string userId, std::string userName, int userAge, std::string workerWorkArea, float workerSalary, std::string workerType) {
    std::string internType;
    int internDuration;

    std::cout << "Intern Type: "; std::cin >> internType;
    std::cout << "Please enter the Internship duration (in months)";
    internDuration = validateNumber(0, 12, "internship duration (in months)", false);

    users.push_back(new Intern(userId, userName, userAge, workerWorkArea, workerSalary, internType, internDuration));
}

void createFTW(std::vector<User*>& users, std::string userId, std::string userName, int userAge, std::string workerWorkArea, float workerSalary, std::string workerType) {
    std::string FTWtype;
    int yearsWorked;
    std::cout << "Full Time Worker Type: "; std::cin >> FTWtype;
    std::cout << "Please enter how long this FTW has worked (in years)";
    yearsWorked = validateNumber(0, 80, "internship duration (in months)", false); /*I oculd create a method that checks
    that the years worked, minus 18, is not bigger than the worker's age.*/
    users.push_back(new Intern(userId, userName, userAge, workerWorkArea, workerSalary, FTWtype, yearsWorked));
}

void createWorker(std::vector<User*>& users, std::string userId, std::string userName, int userAge) {
    int choice;
    std::string userType = "w", workerWorkArea = "", workerType = "";
    float workerSalary = 0;

    std::cout << "\n\nChoose which type of Worker will it be:\n1) Intern\n2) Full Time Worker\n3) Unspecified\n0) Stop Action";
    choice = validateNumber(0, 3, "'choosing Worker type'", true);
    if (choice == 0) {
        std::cout << "\nYou have chosen to stop the action.";
    }else {
        std::cout << "Work Area: "; std::cin >> workerWorkArea;
        std::cout << "Salary: "; std::cin >> workerSalary;
        switch (choice) {
            case 1:
                userType = "i";
                createIntern(users, userId, userName, userAge, workerWorkArea, workerSalary, workerType);
                break;
            case 2:
                userType = "f";
                createFTW(users, userId, userName, userAge, workerWorkArea, workerSalary, workerType);
                break;
            case 3:
                userType = "w";
                users.push_back(new Worker(userId, userName, userAge, workerWorkArea, workerSalary));
                break;
            default:
                break;
        }
    }
}

void createUser(std::vector<User*> &users) {
    int choice, userAge;
    std::string userId, userName;
    std::cout << "\n\nENTER YOUR USER'S INFORMATION";
    std::cout << "\nUser Id: ";
    std::cin >> userId;
    std::cout << "Name: ";
    std::cin >> userName;
    std::cout << "Please enter your age information";

    userAge = validateNumber(0, 120, "user Age", false);

    std::cout << "\n\nChoose which Type of User will it be:\n1) Worker\n2) Student\n3) Unspecified\n0) Stop Action";
    choice = validateNumber(0, 3, "'choosing user type'", true);
    switch (choice) {
        case 0:
            std::cout << "\nYou decided to abort the action.";
        case 1:
            createWorker(users, userId, userName, userAge);
            break;
        case 2:
            createStudent(users, userId, userName, userAge);
            break;
        case 3:
            users.push_back(new User(userId, userName, userAge));
        default:
            break;
    }
}

void createTimeCard(std::vector<TimeCard*>timeCards, int timeCardsNum) {
    std::string userId;

    std::cout << "\n\nENTER YOUR TIME CARD'S INFORMATION";
    //Time Card INdex is assigned automatically as the next number in the timeCards Vector
    std::cout << "\nUser Id: "; std::cin >> userId;

    //I can simplify this by creating a "Time Creator" and then just use the other TimeCard constructor
    std::cout << "Please enter your Initial Time information";
    Time t1 = createTime();
    if (t1.getMinute() == -1000 || t1.getHour() == -1000) {
        std::cout << "You have decided to abort creating a time Card";
    } else {
        std::cout << "Please enter your Final Time information";
        Time t2 = createTime();

        if (t2.getMinute() == -1000 || t2.getHour() == -1000) {
            std::cout << "You have decided to abort creating a time Card";
        } else {
            timeCards.push_back(new TimeCard(timeCardsNum, userId, t1, t2));
        }
    }
}


void menu(std::string usersFile, std::string timeCardsFile, std::vector<User*> &users, std::vector<TimeCard*> &timeCards, int usersNum, int timeCardsNum, std::string divider) {
    bool activeMenu = true;
    int choice;

    std::cout << "\nHey! Thanks for using this program!\n";
    while (activeMenu != false) {
        std::cout << divider << "Here is the menu you can choose from.\n1) Create User\n2) Create Time Card\n3) See Users\n4) See Time Cards\n0) Exit" << divider;
        choice = validateNumber(0, 4, "'choosing menu function'", true);
        switch (choice) {
            case 0:
                std::cout << divider << "You have chosen to exit the menu. Thanks for comming!" << divider << std::endl;
                activeMenu = false;
                break;
            case 1:
                std::cout << divider << "YOU HAVE CHOSEN TO ADD A USER";
                createUser(users);
                usersNum += 1;
                break;
                std::cout << divider;
            case 2:
                std::cout << divider << "YOU HAVE CHOSEN TO ADD A NEW TIME CARD";
                createTimeCard(timeCards, timeCardsNum);
                timeCardsNum += 1;

                break;
            case 3:
                std::cout << "\nYOU HAVE CHOSEN TO SEE THE USERS";
                showUsersVector(users, usersNum);
                break;
            case 4:
                std::cout << "YOU HAVE CHOSEN TO SEE THE TIME CARDS\n";
                showTimeCardVector(timeCards, timeCardsNum);
            default:
                break;
        }

    }
}

void createDivider(std::string &divider) {
    std::string sym;
    std::cout << "\nPlease enter your favorite symbol: ";
    std::cin >> sym;
    divider = sym;

    for (int i = 0; i < 6; i++) {
        divider += divider;
    }

    divider = "\n" + divider + "\n";
}

int main() {
    std::string usersFile = "Users.txt", timeCardsFile = "TimeCards.txt", divider = "\n****************************************\n";
    //createDivider(divider);

    int usersNum = countLines(usersFile);
    int timeCardsNum = countLines(timeCardsFile);
    
    std::vector<User*> users;
    std::vector<TimeCard*> timeCards;

    fillUsersVector(usersFile, users, usersNum);
    fillTimeCardsInfo(timeCardsFile, timeCards, timeCardsNum);

    menu(usersFile, timeCardsFile, users, timeCards, usersNum, timeCardsNum, divider);
    //useClasses();

    return 0;
}
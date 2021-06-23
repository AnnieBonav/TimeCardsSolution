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

int validateTimeNumber(char numberKind) {
    int max = 0, intNumber = 0;
    std::string kind, number;
    bool validatedNum = false;
    if (numberKind == 'm') {
        max = 60;
        kind = "Minute";
    }
    else if (numberKind == 'h') {
        max = 24;
        kind = "Hour";
    }
    while (validatedNum == false) {
        std::cout << "\nPlease enter the " << kind << ": ";
        std::cin >> number;

        if (isNumber(number) == true) {
            intNumber = std::stoi(number);
            if (intNumber >= 0 && intNumber < max) {
                validatedNum = true;
            }
            else {
                std::cout << "\nPlease write a number between 0 and " << max;
            }
        }

    }
    return intNumber;
}

void setTimeMinute(Time& time) {
    int minute = validateTimeNumber('m');
}

void setTimeHour(Time& time) {
    int hour = validateTimeNumber('h');
}

void useClasses() {
    std::cout << "\nHi, welcome to my program.\n";
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

    users[0]->show();
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

int validateNumber(int min, int max, std::string numberType) { //Number type is in which metho dthe number is being asked
    bool validNumber = false, validChoice; /*ValidNumber is for the first while, validChoice is for the second 
    one. Could I use recursive?? Or something better??*/
    std::string stringNumber, validateAction;
    int validIntNum;

    while (validNumber != true) {
        validChoice = false;
        std::cout << "\nNumber: ";
        std::cin >> stringNumber;
        if (isNumber(stringNumber) == true) {
            validIntNum = stoi(stringNumber);
            if (validIntNum >= min && validIntNum <= max) {
                std::cout << "This is the number you chose: " << validIntNum << "\nPlease enter 1 if you accept this information, 2 if you want to re-write it or 0 if you want to abort this action.\nChoice: ";
                
                while (validChoice != true) {
                    std::cin >> validateAction;
                    if (validateAction == "1") {
                        std::cout << "\nThis is the number you chose: " << validIntNum;
                        validChoice = true;
                        validNumber = true;

                    }else if (validateAction == "2") {
                        std::cout << "\nYou have decided to write another number for the " << numberType;
                        validChoice = true;

                    }else if (validateAction == "0") {
                        std::cout << "\nYou have decided to abort the " << numberType << " action.";
                        validIntNum = -1000;
                        validChoice = true;
                        validNumber = true;
                    }
                }
                
            }
        }

    }
    return validIntNum;
}

void createUser(std::vector<User*> &users) {
    int choice;
    std::string userType;
    std::cout << "\nChoose which Type of User will it be:\n1) Worker\n2) Student\n3) Unspecified\n0) Stop Action";
    choice = validateNumber(0, 3, "'choosing user type'");
    switch (choice) {
        case 0:
            std::cout << "\nChoose which type of Worker will it be:\n1) Intern\n2) Full Time Worker\n3) Unspecified\n0) Stop Action";
            choice = validateNumber(0, 3, "'choosing Worker type'");
            switch (choice) {
                case 0:
                    userType = "i";
                    break;
                case 1:
                    userType = "f";
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    break;
            }
            break;

        case 1:
            userType = "s";
            break;
        case 2:
            userType = "u";
            break;
        default:
            break;
    }
}

void createTimeCard(std::vector<TimeCard*>timeCards) {

}


void menu(std::string usersFile, std::string timeCardsFile, std::vector<User*> &users, std::vector<TimeCard*> &timeCards, int usersNum, int timeCardsNum, std::string divider) {
    bool activeMenu = true;
    int choice;

    std::cout << "\nHey! Thanks for using this program!\n";
    while (activeMenu != false) {
        std::cout << divider << "Here is the menu you can choose from.\n1) Create User\n2) Create Time Card\n3) See Users\n4) See Time Cards\n0) Exit" << divider;
        choice = validateNumber(0, 4, "'choosing menu function'");
        switch (choice) {
            case 0:
                std::cout << "\n\nYou have chosen to exit the menu. Thanks for comming!\n\n";
                activeMenu = false;
                break;
            case 1:
                std::cout << divider << "YOU HAVE CHOSEN TO ADD A USER\n";
                createUser(users);
                break;
                std::cout << divider;
            case 2:
                std::cout << "YOU HAVE CHOSEN TO ADD A NEW TIME CARD\n";
                createTimeCard(timeCards);
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



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

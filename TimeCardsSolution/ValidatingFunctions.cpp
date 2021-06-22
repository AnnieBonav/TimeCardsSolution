#include <iostream>
#include <string>
#include <vector>

bool isNumber(std::string number) {
    bool validNumber;
    if (true) {
        validNumber = true;
    }
    else {
        validNumber = false;
        std::cout << "\nPlease remember that no letters or special characters are allowed.";
    }
    return validNumber; //This will return weather the input is a number or not
}

int validateTimeNumber(char numberKind) {
    int max, intNumber;
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
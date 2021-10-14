#include "systemFunc.h"

int checkInput(int choice) {
    int errFlag = 1;
    if (choice < 0 || choice > 5) {
        errFlag = 0;
        std::cout << "Unvalid input, try again" << std::endl;
        std::cin >> choice;
        checkInput(choice);
    } else {
        errFlag = 1;
        return errFlag;
    }
    return errFlag;
}

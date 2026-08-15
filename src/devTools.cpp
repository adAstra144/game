#include "devTools.h"

// Fixes cin(input) if it's supposed to be a number   
void validnum (void) { 
    std::cin.clear();
    cinignore();
    
    horizontalBrokenLines();
    std::cout << "Not a number please try again" << std::endl;
    horizontalBrokenLines();
}

void cinignore (void) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// 1 => Yes | 2 => No
void yn (void) {
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cout << "Next Move: ";
}

// Return 1 If Accept. 2 If Decline
int accept (void) { 

    while (1) {
        int decision;
        std::cout << "[1] Accept" << std::endl;
        std::cout << "[2] Decline" << std::endl;

        std::cout << "Next Move: ";
        std::cin >> decision;

        if (decision == 1) {
            return 1;
        } else if (decision == 2) {
            return 0;
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "Invalid Number" << std::endl;
        }
    }
}

// Create 1 line space
void space (void) {
    std::cout << "\n";
}

// Hit enter to continue with arrow
void contin (void) {
    std::cout << "->";
    getchar();
}

// Clear the terminal
void clear (void) {
    std::system("clear");
}

std::string textSpacerHp (int amount) {
    if (amount >= 100) {
        return "   ";
    } else {
        return "    ";
    }
}

std::string textSpacerAtk (int amount) {
    if (amount >= 100) {
        return "  ";
    } else {
        return "   ";
    }
}

std::string textSpacerSpeed (int amount) {
    if (amount >= 100) {
        return "  ";
    } else {
        return "   ";
    }
}

void horizontalBrokenLines () {
    std::cout << "- - - - - - - - - -" << std::endl;
}

void delay (int seconds, int milliseconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void delayDots (int amount, int seconds, int milliseconds, bool newLine) {
    int i = 0;
    
    while (i != amount) {
        if (i == 0) {
            std::cout << "." << std::flush;
            delay(seconds, milliseconds);
            i++;
            continue;
        }
        std::cout << " ." << std::flush;
        delay(seconds, milliseconds);
        i++;
    }

    if (newLine == true) {
        std::cout << std::endl;
    }
}
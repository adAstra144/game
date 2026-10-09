#include "devTools.hpp"

#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <vector>
#include <sstream>
#include <cstdio>
#include <iomanip>

// Check if int or not
bool tryReadInt(int &out) {
    if (std::cin >> out) {
        cinIgnore();
        return true;
    }

    std::cin.clear();
    cinIgnore();
    return false;
}

// Prompts until the user enters an int; Clears bad input.
int readInt () {
    int value;

    while (true) {
        voidPrompt();

        if (tryReadInt(value)) return value;

        message(MessageType::ERROR, {"Not a number please try again"});
    }
}

// Prompts until the user enters a valid int; Redraws menu on bad input.
int readIntInRange(int min, int max, const std::function<void()> &draw, std::string input) {
    std::string error = "";

    while (true) {
        draw();

        if (error != "") message(MessageType::ERROR, {error});
        if (input != "") message(MessageType::INPUT, {input});
        voidPrompt();

        int value;
        if (!tryReadInt(value)) {
            error = "Not a number please try again";
        } else if (value < min || value > max) {
            error = "Invalid number";
        } else {
            return value;
        }

        clear();
    }
}

// Fixes cin(input) if it's supposed to be a number
void validNum (void) {
    std::cin.clear();
    cinIgnore();

    message(MessageType::ERROR, {"Not a number please try again"});
}

void cinIgnore (void) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// 1 => Yes | 2 => No
void yn (void) {
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
}

// Return 1 If Accept. 0 If Decline
int accept (void) {

    while (1) {
        int decision;
        std::cout << "[1] Accept" << std::endl;
        std::cout << "[2] Decline" << std::endl;

        voidPrompt();
        std::cin >> decision;

        if (decision == 1) {
            return 1;
        } else if (decision == 2) {
            return 0;
        } else if (std::cin.fail()) {
            validNum();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
            std::cout << "! Invalid Number" << std::endl;
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

void clear (void) {
    std::cout << "\033[2J\033[1;1H";
}

// Default = 10
void horizontalBrokenLines () {
    std::cout << "- - - - - - - - - -" << std::endl;
}
void horizontalBrokenLines (int amount) {
    for (int i = 0; i < amount; i++) {
        std::cout << "- ";
    }
    std::cout << std::endl;
}

// Default = 25
void horizontalLine () {
    std::cout << "─────────────────────────" << std::endl;
}
void horizontalLine (int amount) {
    for (int i = 0; i < amount; i++) {
        std::cout << "─";
    }
    std::cout << std::endl;
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

void delayString (std::string textInput, int seconds, int milliseconds) {
    std::stringstream ss(textInput);
    std::string token;
    std::vector<std::string> text;

    while (std::getline(ss, token, ' ')) {
        text.push_back(token);
    }

    for (size_t i = 0; i < text.size(); i++) {
        std::cout << text[i] << " " << std::flush;
        delay(seconds, milliseconds);
    }
}

void voidPrompt () {
    std::cout << " » ";
}

void dialouge (std::string name, std::string dialogue, bool pause) {
    std::cout << "< " << name << " >" << std::endl;

    if (dialogue == "") {
        //* No dialogue
    } else {
        delayString(dialogue, 0, 50);
        std::cout << std::endl;
    }

    if (pause == true) {
        contin();
    }
}

void message (MessageType type, std::initializer_list<std::string> message) {
    if (type == MessageType::SYS) {
        std::cout << "[i] ";
    } else if (type == MessageType::NARRATE) {
        std::cout << "# ";
    } else if (type == MessageType::ERROR) {
        std::cout << "! ";
    } else if (type == MessageType::ACTION) {
        std::cout << "* ";
    } else if (type == MessageType::INPUT) {
        std::cout << "? ";
    }

    for (auto& str : message) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void hideCursor() {
    std::cout << "\033[?25l" << std::flush;
}

void showCursor() {
    std::cout << "\033[?25h" << std::flush;
}


void statRow (int n, const std::string &name, int value, int lvl) {
    std::cout << "[" << n << "] " << std::left << std::setw(7) << name << std::setw(7) << value << lvl << std::endl;
}
void statRow(std::string name, int value, int lvl) {
    std::cout << std::left << std::setw(7) << name << std::setw(7) << value;
    if (lvl != 0) std::cout << lvl;
    std::cout << std::endl;
}
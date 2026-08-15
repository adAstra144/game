#include "game.h"

void game () {

    gameState g;

    resetGame(&g);

    int menuOptions;
    
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (1) {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> menuOptions;

        clear();

        // Return To 1 After Development
        if (menuOptions == 1) {
            std::cout << "Enter player name: ";
            std::string name;
            std::cin >> name;
            g.p.name = name;

            // TODO: Add optional tutorial here (function at the bottom)
            
            clear();

            std::cout << "Starting game";
            delayDots(3, 1, 0);

            clear();

            std::cout << "Presented before you are 3 paths" << std::endl;
            path0(&g);

            break;

        } else if (menuOptions == 2) {
            std::cout << "Goodbye!" << std::endl;
            break;

        } else if (menuOptions == 3) { 
            // Quick Start. Defaulted Player Name To Astra
            g.p.name = "Astra";       
            
            std::cout << "Presented before you are 3 paths" << std::endl;
            
            path0(&g);

            break;

        } else if (std::cin.fail()) {
            validnum();

        } else {
            std::cout << "Invalid Number" << std::endl;
        }    
    } 
}

void tutorial ()
{
    
}
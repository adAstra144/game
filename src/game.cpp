#include "game.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "devTools.hpp"

void game () {

    gameState g;

    resetGame(&g);

    int menuOptions;
    
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (1) {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
        voidPrompt();
        std::cin >> menuOptions;

        clear();

        // Return To 1 After Development
        if (menuOptions == 1) {
            std::string name;

            std::cout << "? Enter player name :" << std::endl;
            voidPrompt();
            std::cin >> name;
            
            g.p.name = name;

            tutorial(&g);
            
            clear();

            std::cout << "[i] Starting game";
            delayDots(3, 0, 600, false);

            clear();

            std::cout << "# Presented before you are 3 paths" << std::endl;
            path0(&g);

            break;

        } else if (menuOptions == 2) {
            std::cout << "[i] Goodbye!" << std::endl;
            break;

        } else if (menuOptions == 3) { 
            // Quick Start. Defaulted Player Name To Astra
            g.p.name = "Astra";       
            
            std::cout << "# Presented before you are 3 paths" << std::endl;
            
            path0(&g);

            break;

        } else if (std::cin.fail()) {
            validnum();

        } else {
            std::cout << "! Invalid Number" << std::endl;
        }    
    } 
}

void tutorial (gameState *g)
{
    clear();
    
    int skipTutorial;
    while (true) {
        std::cout << "? Skip tutorial :" << std::endl;
        yn();   
        std::cin >> skipTutorial;
    
        if (skipTutorial == 1) {
            return;
        } else if (skipTutorial == 2) {
            break;
        }
    }

    clear();

    std::cout << "The game revolves around these symbols so keep them in mind" << std::endl;
    horizontalBrokenLines();
    std::cout << "Game symbols :" << std::endl;
    std::cout << " »  => Requests your decision" << std::endl;
    std::cout << " #  => Narration/Description" << std::endl;
    std::cout << " *  => Player action" << std::endl;
    std::cout << " !  => Error" << std::endl;
    std::cout << "[i] => System message" << std::endl;
    std::cout << "[n] => Menu/Choice n is the number" << std::endl;
    std::cout << "->  => Hit enter to continue" << std::endl;

    space();

    cinignore();
    contin();

    while (true) {
        std::cout << "Enter the corresponding number of the example you want to see" << std::endl;
        std::cout << "Some symbols are already in use and will not be in this list" << std::endl;
        horizontalBrokenLines();
        std::cout << "Examples :" << std::endl;
        std::cout << "[1] #" << std::endl;
        std::cout << "[2] *" << std::endl;
        std::cout << "[3] !" << std::endl;
        std::cout << "[4] [i]" << std::endl;
        std::cout << "[5] Move on?" << std::endl;

        int move1;
        voidPrompt();
        std::cin >> move1;
        
        cinignore();
        if (move1 == 1) {
            clear();
            std::cout << "# A storm is approaching..." << std::endl;
            contin();
        } else if (move1 == 2) {
            clear();
            std::cout << "* " << g->p.name << " is scratching their head" << std::endl;
            contin();
        } else if (move1 == 3) {
            clear();
            std::cout << "! Invalid move!" << std::endl;
            contin();
        } else if (move1 == 4) { 
            clear();
            std::cout << "[i] Quest completed!" << std::endl;
            contin();
        } else if (move1 == 5) {
            break;
        } else if (std::cin.fail()) {
            clear();
            validnum();
            contin();
        } else {
            std::cout << "! Invalid number" << std::endl;
        }
    }
}
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

            message(messageType::INPUT, {"Enter player name :"});
            voidPrompt();
            std::cin >> name;
            g.p.name = name;

            tutorial(&g);
            
            clear();
            message(messageType::SYS, {"Starting game"});
            delayDots(3, 0, 600, false);

            clear();
            message(messageType::NARRATE, {"Presented before you are 3 paths"});

            path0(&g);

            break;

        } else if (menuOptions == 2) {
            message(messageType::SYS, {"Goodbye!"});
            break;

        } else if (menuOptions == 3) { 
            //* Quick Start. Defaulted Player Name To Astra
            g.p.name = "Astra";       
            
            message(messageType::NARRATE, {"Presented before you are 3 paths"});
            
            path0(&g);

            break;

        } else if (std::cin.fail()) {
            validnum();

        } else {
            message(messageType::ERROR, {"Invalid number"});
        }    
    } 
}

void tutorial (gameState *g)
{
    clear();
    
    int skipTutorial;
    while (true) {
        message(messageType::INPUT, {"Skip tutorial :"});
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
            message(messageType::NARRATE, {"A storm is approaching..."});
            contin();
        } else if (move1 == 2) {
            clear();
            message(messageType::ACTION, {g->p.name, "is scratching their head"});
            contin();
        } else if (move1 == 3) {
            clear();
            message(messageType::ERROR, {"Invalid move"});
            contin();
        } else if (move1 == 4) { 
            clear();
            message(messageType::SYS, {"Quest completed!"});
            contin();
        } else if (move1 == 5) {
            break;
        } else if (std::cin.fail()) {
            clear();
            validnum();
            contin();
        } else {
            message(messageType::ERROR, {"Invalid number"});
        }
    }
}
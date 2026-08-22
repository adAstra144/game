#include "game.hpp"

#include <iostream>

#include "paths/path_0.hpp"
#include "devTools.hpp"

void game () {

    gameState g;

    resetGame(&g);

    int menuOptions;
    
    clear();
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (true) {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;

        message(MessageType::INPUT, {"Next move :"});
        voidPrompt();
        std::cin >> menuOptions;

        clear();

        // Return To 1 After Development
        if (menuOptions == 1) {
            setUserName(&g);

            tutorial(&g);
            
            clear();
            message(MessageType::SYS, {"Starting game"});
            delayDots(3, 0, 600, false);

            clear();
            message(MessageType::NARRATE, {"Presented before you are 3 paths"});

            path0(&g);

            break;

        } else if (menuOptions == 2) {
            message(MessageType::SYS, {"Goodbye!"});
            break;

        } else if (menuOptions == 3) { 
            //* Quick Start. Defaulted Player Name To Astra
            g.p.name = "Astra";       
            
            message(MessageType::NARRATE, {"Presented before you are 3 paths"});
            
            path0(&g);

            break;

        } else if (std::cin.fail()) {
            validNum();

        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }    
    } 
}

void setUserName (gameState *g) {
    while (true) {
        std::string name;

        message(MessageType::INPUT, {"Enter player name :"});
        voidPrompt();
        std::cin >> name;
        
        int sure;
        message(MessageType::INPUT, {"Are you sure you want |", name, "| as your username :"});
        yn();
        std::cin >> sure;
        
        if (sure == 1) {
            g->p.name = name;
            break;
        } else if (sure == 2) {
            clear();
            continue;
        } else if (std::cin.fail()) {
            message(MessageType::ERROR, {"Not a number"});
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
}

void tutorial (gameState *g)
{
    clear();
    
    int tutorial;
    while (true) {
        message(MessageType::INPUT, {"Do you want a tutorial :"});
        yn();   
        std::cin >> tutorial;
    
        if (tutorial == 1) {
            break;
        } else if (tutorial == 2) {
            return;
        }
    }

    clear();

    std::cout << "The game revolves around these symbols so keep them in mind" << std::endl;
    horizontalBrokenLines();
    std::cout << "Game symbols :" << std::endl;
    std::cout << " »  => Requests your decision" << std::endl;
    std::cout << " #  => Narration/Description" << std::endl;
    std::cout << " *  => Player/NPC/Enemy action" << std::endl;
    std::cout << " !  => Error" << std::endl;
    std::cout << "[i] => System message" << std::endl;
    std::cout << "[n] => Menu/Choice n is the number" << std::endl;
    std::cout << "->  => Hit enter to continue" << std::endl;

    space();

    cinIgnore();
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
        
        cinIgnore();
        if (move1 == 1) {
            clear();
            message(MessageType::NARRATE, {"A storm is approaching..."});
            contin();
        } else if (move1 == 2) {
            clear();
            message(MessageType::ACTION, {g->p.name, "is scratching their head"});
            contin();
        } else if (move1 == 3) {
            clear();
            message(MessageType::ERROR, {"Invalid move"});
            contin();
        } else if (move1 == 4) { 
            clear();
            message(MessageType::SYS, {"Quest completed!"});
            contin();
        } else if (move1 == 5) {
            break;
        } else if (std::cin.fail()) {
            clear();
            validNum();
            contin();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
}
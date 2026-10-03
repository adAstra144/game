#include "game.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "devTools.hpp"

void game () {

    GameState g;

    resetGame(&g);

    g.musicMgr.play(Track::MENU);

    int menuOptions;

    clear();
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    menuOptions = readIntInRange(1, 3, [&]() {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
    }, "Next Move :");

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

    } else if (menuOptions == 2) {
        message(MessageType::SYS, {"Goodbye!"});

    } else {
        //* Quick Start. Defaulted Player Name To Astra
        g.p.name = "Astra";

        message(MessageType::NARRATE, {"Presented before you are 3 paths"});

        path0(&g);

    }
}

void setUserName (GameState *g) {
    while (true) {
        std::string name;

        clear();
        message(MessageType::INPUT, {"Enter player name :"});
        voidPrompt();
        std::cin >> name;
        cinIgnore();

        int sure = readIntInRange(1, 2, [&]() {
            message(MessageType::INPUT, {"Are you sure you want | ", name, " | as your username :"});
            yn();
        }, "Next Move :");

        if (sure == 1) {
            g->p.name = name;
            break;
        }
    }
}

void tutorial (GameState *g)
{
    clear();

    int tutorial;

    while (true) {
        tutorial = readIntInRange(1, 2, [&]() {
            message(MessageType::INPUT, {"Do you want a tutorial :"});
            yn();
        }, "Next Move :");

        if (tutorial == 1) {
            break;
        } else {
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
    contin();
    clear();

    int move1;

    while (true) {
        move1 = readIntInRange(1, 5, [&]() {
            std::cout << "Enter the corresponding number of the example you want to see" << std::endl;
            std::cout << "Some symbols are already in use and will not be in this list" << std::endl;
            horizontalBrokenLines();
            std::cout << "Examples :" << std::endl;
            std::cout << "[1] #" << std::endl;
            std::cout << "[2] *" << std::endl;
            std::cout << "[3] !" << std::endl;
            std::cout << "[4] [i]" << std::endl;
            std::cout << "[5] Move on?" << std::endl;
        }, "");

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
        } else {
            break;
        }
    }
}

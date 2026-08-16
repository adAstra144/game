#include "paths/path0.hpp"

#include <iostream>

#include "paths/path1.hpp"
#include "paths/path2.hpp"
#include "paths/path3.hpp"
#include "devTools.hpp"

void path0 (gameState *g) {
    while (1) {
        std::cout << "~ Current Path: 0" << std::endl;
        int move1;
        std::cout << "[1] Enter Path 1" << std::endl;
        std::cout << "[2] Enter Path 2" << std::endl;
        std::cout << "[3] Enter Path 3" << std::endl;
    
        std::cout << "? Next Move :" << std::endl;
        voidPrompt();
        std::cin >> move1;

        if (move1 == 1) {
            clear();
            path1(g);
            break;
        } else if (move1 == 2) {
            clear();

            if (g->dialogue2 == true) {
                path2(g);
                break;
            }
            else if (g->dialogue2 == false) {
                path2(g);
                break;
            } else {
                std::cout << "! Error" << std::endl;
                break;
            }
        } else if (move1 == 3) {
            clear();
            
            path3(g);
            break;
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "! Invalid Number" << std::endl;
        }
    }
}
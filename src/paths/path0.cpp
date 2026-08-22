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
        
        message(MessageType::INPUT, {"Next move :"});
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
                message(MessageType::ERROR, {"Error"});
                break;
            }
        } else if (move1 == 3) {
            clear();
            
            path3(g);
            break;
        } else if (std::cin.fail()) {
            validNum();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
}
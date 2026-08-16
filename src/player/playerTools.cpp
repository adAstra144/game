#include "player/playerTools.hpp"

#include <iostream>
#include "devTools.hpp"

void resetPlayerStats (gameState *g) {
    g->p.setHp(100);
    g->p.setAtk(10);
    g->p.setSpeed(10);
    g->p.setGold(0);
    g->p.setDefend(false);
}

// Handles Increasing
int statUp (gameState *g) {
    int move1;
    int amount;
    int basePrice = 10;
    int price;
    int result;

    while (1) {
        std::cout << "Select A Stat To Upgrade: " << std::endl;
        std::cout << "Current Gold: " << g->p.getGold() << std::endl;
        std::cout << "[1] HP" << std::endl;
        std::cout << "[2] ATK" << std::endl;
        std::cout << "[3] SPEED" << std::endl;
        std::cout << "[4] Exit" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> move1;
        
        // Only Requests An "Amount" Input If Picking A Stat Option
        if (move1 == 1 || move1 == 2 || move1 == 3) {
            std::cout << "? Enter Amount: ";
            std::cin >> amount;

            price = basePrice * amount;

            if (std::cin.fail()) {
                validnum();
                contin();
                statUp(g);
                return -1;
            }

            // Prevents Zero & Negative Values
            if (amount <= 0) {
                horizontalBrokenLines();
                std::cout << "! Amount Must Be At least 1" << std::endl;
                horizontalBrokenLines();

                statUp(g);

                return -1;          
            }

            space();
        }

        switch (move1) {
            case 1: {
                int hpBefore = g->p.getHp();
                int lvlBefore = g->p.getLvlHp();

                result = g->p.hpUp(amount, price);

                if (result == 1) {
                    message(messageType::SYS,{
                        "HP:",
                        std::to_string(hpBefore),
                        "->",
                        std::to_string(g->p.getHp()),    
                    });
                    message(messageType::SYS, {
                        "Level:",
                        std::to_string(lvlBefore),
                        "->",
                        std::to_string(g->p.getLvlHp()),
                    });
                    cinignore();
                    contin();
                } else {
                    contin();
                }

                break;
            }

            case 2: {
                int atkBefore = g->p.getAtk();
                int lvlBefore = g->p.getLvlAtk();

                result = g->p.atkUp(amount, price);
                if (result == 1) {
                    message(messageType::SYS,{
                        "HP:",
                        std::to_string(atkBefore),
                        "->",
                        std::to_string(g->p.getAtk()),    
                    });
                    message(messageType::SYS, {
                        "Level:",
                        std::to_string(lvlBefore),
                        "->",
                        std::to_string(g->p.getLvlAtk()),
                    });
                    cinignore();
                    contin();
                } else {
                    contin();
                }

                break;
            }

            case 3: {
                int speedBefore = g->p.getSpeed();
                int lvlBefore = g->p.getLvlSpeed();

                result = g->p.speedUp(amount, price);
                if (result == 1) {
                    message(messageType::SYS,{
                        "HP:",
                        std::to_string(speedBefore),
                        "->",
                        std::to_string(g->p.getSpeed()),    
                    });
                    message(messageType::SYS, {
                        "Level:",
                        std::to_string(lvlBefore),
                        "->",
                        std::to_string(g->p.getLvlSpeed()),
                    });
                    cinignore();
                    contin();
                } else {
                    contin();
                }

                break;
            }

            case 4: {
                return 0; // Exit With Return 0
                break;
            }

            default: {
                if (std::cin.fail()) {
                    validnum();
                } else {
                    cinignore();

                    horizontalBrokenLines();
                    std::cout << "! Invalid Number" << std::endl;
                    horizontalBrokenLines();
                }
                contin();
                break;
            }
        }
    }
    return -1;
}
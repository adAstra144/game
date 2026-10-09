#include "player/playerTools.hpp"

#include <iostream>

#include "devTools.hpp"

struct statUpVars {
    int amount;
    int basePrice;
    int price;
    UpgradeResult result;

    int stat;
    int lvl;

    int statBefore;
    int lvlBefore;
};

void statUpTopUI (GameState *g, int basePrice);
void printResult (GameState *g, UpgradeResult result, std::string name, statUpVars *v);

void resetPlayerStats (GameState *g) {
    g->p.setHp(100);
    g->p.setAtk(10);
    g->p.setSpeed(10);
    g->p.setGold(0);
    g->p.setDefend(false);
}

// Handles Increasing
int statUp (GameState *g) {
    int move1;
    
    statUpVars v;

    v.basePrice = 10;

    while (1) {
        clear();
        statUpTopUI(g, v.basePrice);
        std::cout << "    " << std::left << std::setw(7) << "Stat" << std::setw(7) << "Value" << "Level" << std::endl;
        statRow(1, "HP", g->p.getHp(), g->p.getLvlHp());
        statRow(2, "ATK", g->p.getAtk(), g->p.getLvlAtk());
        statRow(3, "SPEED", g->p.getSpeed(), g->p.getLvlSpeed());
        std::cout << "[4] Exit" << std::endl;
        voidPrompt();
        std::cin >> move1;

        // Only Requests An "Amount" Input If Picking A Stat Option
        if (move1 <= 3) {
            message(MessageType::INPUT, {"Enter amount :"});
            voidPrompt();
            std::cin >> v.amount;

            v.price = v.basePrice * v.amount;

            if (std::cin.fail()) {
                validNum();
                contin();
                statUp(g);
                return -1;
            }

            // Prevents Zero & Negative Values
            if (v.amount <= 0) {
                horizontalBrokenLines();
                message(MessageType::ERROR, {"Amount must be atleast 1"});
                horizontalBrokenLines();

                statUp(g);

                return -1;
            }

            space();
        }

        clear();
        statUpTopUI(g, v.basePrice);

        switch (move1) {
            case 1: {
                v.statBefore = g->p.getHp();
                v.lvlBefore = g->p.getLvlHp();

                v.result = g->p.hpUp(v.amount, v.price);
                v.stat = g->p.getHp();
                v.lvl = g->p.getLvlHp();

                printResult(g, v.result, "HP:", &v);

                break;
            }

            case 2: {
                v.statBefore = g->p.getAtk();
                v.lvlBefore = g->p.getLvlAtk();

                v.result = g->p.atkUp(v.amount, v.price);
                v.stat = g->p.getAtk();
                v.lvl = g->p.getLvlAtk();

                printResult(g, v.result, "ATK:", &v); 

                break;
            }

            case 3: {
                v.statBefore = g->p.getSpeed();
                v.lvlBefore = g->p.getLvlSpeed();

                v.result = g->p.speedUp(v.amount, v.price);
                v.stat = g->p.getSpeed();
                v.lvl = g->p.getLvlSpeed();    
            
                printResult(g, v.result, "SPEED:", &v);

                break;
            }

            case 4: {
                return 0;
                break;
            }

            default: {
                if (std::cin.fail()) {
                    validNum();
                } else {
                    cinIgnore();

                    horizontalBrokenLines();
                    message(MessageType::ERROR, {"Invalid number"});
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

void statUpTopUI (GameState *g, int basePrice) {
    std::cout << "Gold: " << g->p.getGold() << " | " << "Cost: " << basePrice << " per level" << std::endl;
    horizontalLine(30);
}

void printResult (GameState *g, UpgradeResult result, std::string name, statUpVars *v) {
    clear();
    statUpTopUI(g, v->basePrice);
    
    if (result == UpgradeResult::SUCCESS) {
        horizontalBrokenLines();
        message(MessageType::SYS, {"Upgrade Successful!"});
        horizontalBrokenLines();

        message(MessageType::SYS, {
            name,
            std::to_string(v->statBefore), 
            "->", 
            std::to_string(v->stat)
        });
        message(MessageType::SYS, {
            name, 
            std::to_string(v->lvlBefore), 
            "->", 
            std::to_string(v->lvl)
        });
    } else if (result == UpgradeResult::INSUFFICIENT_GOLD) {
        horizontalBrokenLines();
        message(MessageType::ERROR, {"Not enough gold!"});
        horizontalBrokenLines();
    } else if (result == UpgradeResult::CANCELLED) {
        horizontalBrokenLines();
        message(MessageType::SYS, {"StatUp Cancelled"});
        horizontalBrokenLines();
    }

    cinIgnore();
    contin();
}

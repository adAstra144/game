#include "combat.hpp"

#include <iostream>
#include <cassert>

#include "paths/path0.hpp"
#include "player/playerTools.hpp"
#include "devTools.hpp"

// Main Combat Mechanic
CombatResult turnBasedCombat (GameState *g, Enemy *e) {
    clear();

    CombatVariables cv;

    cv.turn = 0;

    cv.playerStartingHp = g->p.getHp();
    cv.enemyStartingHp = e->getHp();

    cv.playerTurnCount = 0;
    cv.enemyTurnCount = 0;

    message(MessageType::SYS, {"Combat start!"});
    contin();

    // Determine who goes first based on speed stat
    if (g->p.getSpeed() > e->getSpeed()) {
        // Player Start
        cv.turn = 0;
        message(MessageType::SYS, {g->p.name, "Starts first"});
    } else {
        // Enemy Start
        cv.turn = 1;
        message(MessageType::SYS, {e->name, "Starts first"});
    }
    contin();

    // Main combat loop
    while (1) {
        if (cv.turn == 0) {
            clear();
            cv.playerTurnCount++;
            cv.enemyHpBeforeAttack = e->getHp();

            g->p.setDefend(false); // Resets Defending to false
            int decision = playerCombatOptions(g, e, &cv);

            if (decision == 2) {
                return CombatResult::RAN_AWAY;
            }

            if (e->getHp() <= 0) {
                cinIgnore();
                contin();
                clear();

                g->p.setHp(cv.playerStartingHp);

                g->p.gainGold(e->getGold());

                horizontalBrokenLines();
                message(MessageType::SYS, {"You win!"});
                horizontalBrokenLines();
                std::cout << "Received Gold: " << e->getGold() << std::endl;
                std::cout << "Current Gold: " << g->p.getGold() << std::endl;
                horizontalBrokenLines();

                contin();

                clear();

                return CombatResult::WON;
            }

            if (decision != 3) {
                cinIgnore();
            }
            contin();


            cv.turn = 1;
        } else if (cv.turn == 1) {
            clear();
            cv.enemyTurnCount++;
            cv.playerHpBeforeAttack = g->p.getHp();

            topCombatUI(&cv, g, e);
            horizontalLine();

            delayDots(3, 0, 400, true);

            clear();
            topCombatUI(&cv, g, e);
            horizontalLine();

            horizontalBrokenLines();
            message(MessageType::ACTION, {e->name,"Attacks!"});
            horizontalBrokenLines();

            e->specialMove(cv.enemyTurnCount);

            g->p.takeDamage(e->getAtk());
            std::cout << g->p.name << "\'s HP: " << cv.playerHpBeforeAttack << " -> " << g->p.getHp() << std::endl;
            horizontalBrokenLines();

            if (g->p.getDefend() == true) {
                contin();

                clear();
                
                horizontalBrokenLines();
                message(MessageType::ACTION, {g->p.name, "Defended | Reduced damage taken"});
                horizontalBrokenLines();
            }

            if (g->p.getHp() <= 0) {
                contin();
                clear();
                horizontalBrokenLines();
                message(MessageType::SYS, {"You died!"});
                horizontalBrokenLines();

                respawn(g);
                return CombatResult::LOST;
            }
            contin();

            cv.turn = 0;
        }
    }
    assert(false && "Combat Error");
}

// Players Options during Combat
int playerCombatOptions (GameState *g, Enemy *e, CombatVariables *cv) {
    int combatDecision;

    while (1) {
        topCombatUI(cv, g, e);
        horizontalLine();
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Defend" << std::endl;
        std::cout << "[3] Try To Run" << std::endl;
        std::cout << "[4] Show Player Stats" << std::endl;
        std::cout << "[5] Show Enemy Stats" << std::endl;

        voidPrompt();
        std::cin >> combatDecision;

        clear();
        topCombatUI(cv, g, e);
        horizontalLine();

        if (combatDecision == 1) {
            e->takeDamage(g->p.getAtk());

            horizontalBrokenLines();
            message(MessageType::ACTION, {g->p.name, "Attacks!"});
            horizontalBrokenLines();
            std::cout << e->name << " HP: " << cv->enemyHpBeforeAttack << " -> " << e->getHp() << std::endl;
            horizontalBrokenLines();

            break;
        } else if (combatDecision == 2) {
            g->p.setDefend(true);

            horizontalBrokenLines();
            message(MessageType::ACTION, {g->p.name, "Defends!"});
            horizontalBrokenLines();

            break;
        } else if (combatDecision == 3) {
            cinIgnore();
            std::cin.clear();

            dialouge(g->p.name, "Time to run!", false);
            contin();

            if (g->p.getSpeed() > e->getSpeed()) {
                horizontalBrokenLines();
                message(MessageType::ACTION, {g->p.name, "Successfully ran away"});
                horizontalBrokenLines();
                contin();

                g->p.setHp(cv->playerStartingHp);

                return 2;
            } else {
                horizontalBrokenLines();
                message(MessageType::ACTION, {g->p.name, "Failed to run away"});
                horizontalBrokenLines();

                return 3;
            }
        } else if (combatDecision == 4) {
            printStats(0, g, e);
        } else if (combatDecision == 5) {
            printStats(1, g, e);
        } else if (std::cin.fail()) {
            validNum();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
    return -1;
}

void printStats(int who, GameState *g, Enemy *e) {

    if (who == 0) {
        clear();
        std::cout << g->p.name << std::endl;
        horizontalLine();
        std::cout << std::left << std::setw(7) << "Stat" << std::setw(7) << "Value" << "Level" << std::endl;
        statRow("HP ", g->p.getHp(), g->p.getLvlHp());
        statRow("ATK", g->p.getAtk(), g->p.getLvlAtk());
        statRow("SPD", g->p.getSpeed(), g->p.getLvlSpeed());
        std::cout << "GOLD   " << g->p.getGold() << std::endl;
        space();

        cinIgnore();
        contin();
        clear();  
    } else {
        clear();
        std::cout << e->name << std::endl;
        horizontalLine();
        statRow("HP ", e->getHp(), 0);
        statRow("ATK", e->getAtk(), 0);
        statRow("SPD", e->getSpeed(), 0);
        std::cout << "GOLD   " << e->getGold() << std::endl;
        space();

        cinIgnore();
        contin();
        clear();
    }
}

void respawn (GameState *g) {
    while (1) {
        int respawnDecision;
        message(MessageType::INPUT, {"Respawn :"});
        yn();
        message(MessageType::INPUT, {"Next Move :"});
        voidPrompt();
        std::cin >> respawnDecision;

        if (respawnDecision == 1) {
            resetPlayerStats(g);
            resetGame(g);
            clear();
            message(MessageType::NARRATE, {"Here we go again..."});
            path0(g);
            break;
        } else if (respawnDecision == 2) {
            message(MessageType::SYS, {"Goodbye!"});

            break;
        } else if (std::cin.fail()) {
            validNum();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
}

void topCombatUI (CombatVariables *cv, GameState *g, Enemy *e) {
    if (cv->turn == 0) {
        std::cout << g->p.name << "\'s HP: " << g->p.getHp() << " / " << cv->playerStartingHp << std::endl;
        std::cout << "Turn" << " | " << cv->playerTurnCount << std::endl;
    } else {
        std::cout << e->name << "\'s HP: " << e->getHp() << " / " << cv->enemyStartingHp << std::endl;
        std::cout << "Turn" << " | " << cv->enemyTurnCount << std::endl;
    }
}

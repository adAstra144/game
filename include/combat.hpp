#pragma once

#include "enemy/Enemy.hpp"
#include "GameState.hpp"

struct CombatVariables {
    int playerStartingHp;
    int enemyStartingHp;

    int turn;
    int playerTurnCount;
    int enemyTurnCount;

    int playerHpBeforeAttack;
    int enemyHpBeforeAttack;
};

enum class CombatResult {
    WON,
    LOST,
    RAN_AWAY
};

CombatResult turnBasedCombat (GameState *g, Enemy *e);
int playerCombatOptions (GameState *g, Enemy *e, CombatVariables *cv);
void printStats (int who, GameState *g, Enemy *e);
void respawn (GameState *g);

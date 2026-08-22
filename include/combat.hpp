#pragma once

#include "enemy/Enemy.hpp"
#include "gameState.hpp"

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

CombatResult turnBasedCombat (gameState *g, Enemy *e);
int playerCombatOptions (gameState *g, Enemy *e, CombatVariables *cv);
void playerStats (gameState *g);
void enemyStats (Enemy *e);
void respawn (gameState *g);
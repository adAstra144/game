#pragma once

#include "enemy/enemy.hpp"
#include "gameState.hpp"

struct combatVariables {
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

CombatResult turnBasedCombat (gameState *g, enemy *e);
int playerCombatOptions (gameState *g, enemy *e, combatVariables *cv);
void playerStats (gameState *g);
void enemyStats (enemy *e);
void respawn (gameState *g);
#pragma once

#include "enemy/enemy.hpp"
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

CombatResult turnBasedCombat (GameState *g, enemy *e);
int playerCombatOptions (GameState *g, enemy *e, CombatVariables *cv);
void playerStats (GameState *g);
void enemyStats (enemy *e);
void respawn (GameState *g);
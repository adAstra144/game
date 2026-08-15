#pragma once

#include "enemy/enemy.h"
#include "paths/path0.h"
#include "player/playerTools.h"
#include "devTools.h"
#include "gameState.h"

struct combatVariables {
    int playerStartingHp;
    int enemyStartingHp;

    int turn;
    int playerTurnCount;
    int enemyTurnCount;

    int playerHpBeforeAttack;
    int enemyHpBeforeAttack;
};

// Main Combat Mechanics (Basic Turn Based)
int turnBasedCombat (gameState *g, enemy *e);

// Players Options during Combat
int playerCombatOptions (gameState *g, enemy *e, combatVariables *cv);

// Handles Player Respawns
void respawn (gameState *g);
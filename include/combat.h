#pragma once

#include "enemy/enemy.h"
#include "paths/path0.h"
#include "player/playerTools.h"
#include "gameState.h"

// Main Combat Mechanics (Basic Turn Based)
int turnBasedCombat (gameState *g, enemy *e);

// Players Options during Combat
int playerCombatOptions (gameState *g, enemy *e, int playerStartingHp);

// Handles Player Respawns
void respawn (gameState *g);
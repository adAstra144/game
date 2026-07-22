#pragma once

#include "gameState.h"
#include "enemy.h"
#include "playerTools.h"
#include "path0.h"

// Main Combat Mechanics (Basic Turn Based)
int turnBasedCombat (gameState *g, enemy *e);

// Players Options during Combat
int playerCombatOptions (gameState *g, enemy *e, int playerStartingHp);

// Handles Player Respawns
void respawn (gameState *g);
#pragma once

#include "gameState.h"
#include "enemy.h"
#include "devTools.h"

// Player Tools
void resetPlayerStats (gameState *g);
void playerStats (gameState *g);
void enemyStats (enemy *e);
int statUp (gameState *g);
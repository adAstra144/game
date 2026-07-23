#pragma once

#include "enemy/enemy.h"
#include "../devTools.h"
#include "../gameState.h"

// Player Tools
void resetPlayerStats (gameState *g);
void playerStats (gameState *g);
void enemyStats (enemy *e);
int statUp (gameState *g);
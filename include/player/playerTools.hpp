#pragma once

#include "enemy/enemy.hpp"
#include "../gameState.hpp"

// Player Tools
void resetPlayerStats (gameState *g);
void playerStats (gameState *g);
void enemyStats (enemy *e);
int statUp (gameState *g);
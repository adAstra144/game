#include "gameState.h"

void resetGame (gameState *g) // Add All Dialogues and Quests Here
{
    // Dialogues
    g->dialogue2 = true;

    // Quests
    g->qWizard.active = false;
    g->qWizard.finished = false;

}
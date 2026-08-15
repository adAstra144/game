#include "gameState.h"

// Add All Dialogues and Quests Here
void resetGame (gameState *g) {
    // Dialogues
    g->dialogue2 = true;
    g->dialogue2_2 = true;

    // Quests
    g->qWizard.active = false;
    g->qWizard.finished = false;
    g->numOfSkeletons = 3;
}
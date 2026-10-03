#include "GameState.hpp"

// Add All Dialogues and Quests Here
void resetGame (GameState *g) {
    // Dialogues
    g->dialogue2 = true;
    g->dialogue2_2 = true;

    // Quests
    g->qWizard.active = false;
    g->qWizard.finished = false;
    g->numOfSkeletons = 3;
}

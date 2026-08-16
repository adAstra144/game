#pragma once

#include <string>
#include <cstdlib>

// Error Tools
void validnum (void);
void cinignore (void);

// Option Tools 
void yn (void);
int accept (void);

// Design Tools
void space (void);
void contin (void);
void clear (void);
std::string textSpacerHp (int amount);
std::string textSpacerAtk (int amount);
std::string textSpacerSpeed (int amount);
void horizontalBrokenLines ();
void delay (int seconds, int milliseconds);
void delayDots (int amount, int seconds, int milliseconds, bool newLine);
void voidPrompt ();
void dialouge (std::string name, std::string dialogue, bool pause);
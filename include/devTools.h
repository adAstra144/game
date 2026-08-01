#pragma once

#include <iostream>
#include <limits>
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
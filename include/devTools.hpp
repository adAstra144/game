#pragma once

#include <string>
#include <cstdlib>
#include <initializer_list>

enum class MessageType {
    ACTION,
    ERROR,
    INPUT,
    NARRATE,
    SYS,
};

// Error Tools
void validNum (void);
void cinIgnore (void);

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
void delayString (std::string textInput, int seconds, int milliseconds);
void voidPrompt ();
void dialouge (std::string name, std::string dialogue, bool pause);
void message (MessageType type, std::initializer_list<std::string> message);
void hideCursor();
void showCursor();
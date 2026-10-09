#pragma once

#include <string>
#include <initializer_list>
#include <functional>

enum class MessageType {
    ACTION,
    ERROR,
    INPUT,
    NARRATE,
    SYS,
};

// Error Tools
bool tryReadInt(int &out);
int readInt();
int readIntInRange(int min, int max, const std::function<void()> &draw, std::string input);
void validNum (void);
void cinIgnore (void);

// Option Tools
void yn (void);
int accept (void);

// Design Tools
void space (void);
void contin (void);
void clear (void);
void horizontalBrokenLines ();
void horizontalBrokenLines (int amount);
void horizontalLine ();
void horizontalLine (int amount);
void delay (int seconds, int milliseconds);
void delayDots (int amount, int seconds, int milliseconds, bool newLine);
void delayString (std::string textInput, int seconds, int milliseconds);
void voidPrompt ();
void dialouge (std::string name, std::string dialogue, bool pause);
void message (MessageType type, std::initializer_list<std::string> message);
void hideCursor();
void showCursor();
void statRow (int n, const std::string &name, int value, int lvl);
void statRow (std::string name, int value, int lvl);
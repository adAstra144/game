#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "game.hpp"

int main (){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    game();
    return 0;
}

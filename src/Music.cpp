#include "Music.hpp"

#include <chrono>
#include <thread>

MusicManager::MusicManager() : current(Track::NONE) {}

MusicManager::~MusicManager () {
    fadeAbort = true;
    if (fadeThread.joinable())
        fadeThread.join();
}

std::string MusicManager::trackPath (Track t) {
    switch (t) {
        case Track::MENU:       return "assets/music/menu.ogg"; break;
        case Track::DUNGEON:    return "assets/music/dungeon.ogg"; break;
        case Track::LEISURE:    return "assets/music/leisure.ogg"; break;
        case Track::WIZARD:     return "assets/music/wizard.ogg"; break;
        case Track::BOSS:       return "assets/music/boss.ogg"; break;
        case Track::NOTSURE1:   return "assets/music/idkyet1.ogg"; break;
        case Track::NOTSURE2:   return "assets/music/idkyet1.ogg"; break;
        default:                return ""; break;
    }
}

void MusicManager::fade (float target, int ms) {
    float from  = music.getVolume();
    int   steps = ms / FADE_STEP_MS;

    if (steps < 1) steps = 1;

    for (int i = 1; i <= steps; i++) {
        if (fadeAbort) return;

        music.setVolume(from + (target - from) * i / steps);
        std::this_thread::sleep_for(std::chrono::milliseconds(FADE_STEP_MS));
    }
}

void MusicManager::play (Track t, bool loop) {
    if (t == current) return; //* Already playing

    //* Cancel any running fade & wait, so only one thread touches `music`
    fadeAbort = true;
    if (fadeThread.joinable())
        fadeThread.join();
    fadeAbort = false;

    current = t;

    fadeThread = std::thread([this, t, loop] () {
        if (music.getStatus() == sf::Music::Status::Playing)
            fade (0.0f, FADE_OUT_MS);

        if (fadeAbort) return;

        if (!music.openFromFile(trackPath(t))) {
            current = Track::NONE; // TODO: log/handle error
            return;
        }

        music.setLooping(loop);
        music.setVolume(0.0f);
        music.play();

        fade (MAX_VOLUME, FADE_IN_MS);
    });
}

void MusicManager::stop () {
    fadeAbort = true;
    if (fadeThread.joinable())
        fadeThread.join();

    music.stop();
    current = Track::NONE;
}

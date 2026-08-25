#include "Music.hpp"

MusicManager::MusicManager() : current(Track::NONE) {}

std::string MusicManager::trackPath (Track t) {
    switch (t) {
        case Track::MENU:       return "assets/music/menu.ogg"; break;
        case Track::DUNGEON:    return "assets/music/boss.ogg"; break;
        case Track::LEISURE:    return "assets/music/leisure.ogg"; break;
        case Track::WIZARD:     return "assets/music/wizard.ogg"; break;
        case Track::BOSS:       return "assets/music/boss.ogg"; break;
        case Track::NOTSURE1:   return "assets/music/idkyet1.ogg"; break;
        case Track::NOTSURE2:   return "assets/music/idkyet1.ogg"; break;
        default:                return ""; break;
    }
}

void MusicManager::play (Track t, bool loop) {
    if (t == current) return; //* Already playing

    if (!music.openFromFile(trackPath(t))) {
        return; // TODO: log/handle error
    }

    music.setLoop(loop);
    music.setVolume(20.0f);
    music.play();
    current = t;
}

void MusicManager::stop () {
    music.stop();
    current = Track::NONE;
}
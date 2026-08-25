#pragma once 

#include <SFML/Audio.hpp>
#include <string>

enum class Track {
    NONE,
    MENU,
    DUNGEON,
    WIZARD,
    BOSS,
    LEISURE,
    NOTSURE1,
    NOTSURE2
};

class MusicManager {
    private:
        sf::Music music;
        Track current;

        std::string trackPath (Track t);

    public:
        MusicManager();

        void play (Track t, bool loop = true);
        void stop ();
};
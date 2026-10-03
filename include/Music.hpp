#pragma once

#include <SFML/Audio.hpp>
#include <atomic>
#include <string>
#include <thread>

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
        // TODO: Make this adjustable in a possible settings menu
        static constexpr float MAX_VOLUME   = 5.0f;
        static constexpr int   FADE_OUT_MS  = 900;
        static constexpr int   FADE_IN_MS   = 1400;
        static constexpr int   FADE_STEP_MS = 30;

        sf::Music music;
        std::atomic<Track> current;

        // Fades run on their own thread so the game never blocks on music.
        // fadeAbort cancels a running fade; the thread is always joined
        // before play()/stop() touch `music` again.
        std::thread fadeThread;
        std::atomic<bool> fadeAbort {false};

        std::string trackPath (Track t);

        void fade (float target, int ms);

    public:
        MusicManager();
        ~MusicManager();

        void play (Track t, bool loop = true);
        void stop ();
};

#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/GameEngine.hpp>

class Global{
    public:
        static int Width;
        static int Height;
        static ALLEGRO_FONT* JetBrainMono;
        static std::string previousScene;
        static std::string currentScene;
        static bool secondWeek;
        static bool emeraldCollected;
        static int impressionLevel;
        static bool GiveEmeraldToAlthea;
        static bool TellMoira;
};

#endif // GLOBAL_HPP
#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/GameEngine.hpp>

class Global{
    public:
        static ALLEGRO_FONT* JetBrainMono;
        static std::string previousScene;
        static std::string currentScene;
};

#endif // GLOBAL_HPP
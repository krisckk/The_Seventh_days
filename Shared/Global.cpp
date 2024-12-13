#include "Global.hpp"
#include <allegro5/allegro_font.h>
#include <string>
ALLEGRO_FONT* Global::JetBrainMono = al_load_font("Resources/fonts/JetBrainsMono.ttf", 24, 0);
std::string Global::previousScene = "";
std::string Global::currentScene = "";
bool Global::secondWeek = false;
bool Global::emeraldCollected = false;
int Global::impressionLevel = 0;
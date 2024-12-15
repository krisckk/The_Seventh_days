#include "Global.hpp"
#include <allegro5/allegro_font.h>
#include <string>
ALLEGRO_FONT* Global::JetBrainMono = al_load_font("Resources/fonts/JetBrainsMono.ttf", 24, 0);
std::string Global::previousScene = "";
std::string Global::currentScene = "";
bool Global::secondWeek = false;
bool Global::emeraldCollected = true;
int Global::impressionLevel = 4;
int Global::Width = 1600;
int Global::Height = 900;
bool Global::GiveEmeraldToAlthea = true;
bool Global::TellMoira = true;
bool Global::NotebookGet = true;
bool Global::GroupPhotoGet = true;
bool Global::NecklaceGet = true;
std::string Global::endingType = "";
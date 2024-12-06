#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_video.h>
#include <Engine/AudioHelper.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/Resources.hpp>
#include <Engine/Sprite.hpp>
#include <Engine/LOG.hpp>
#include <UI/Component/Label.hpp>
#include <UI/Component/ImageButton.hpp>
#include "Character/MainCharacter.hpp"
#include "Shared/Global.hpp"
#include "Map.hpp"

void Map::Initialize(){
    Engine::LOG(Engine::INFO) << "Map initialized";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("Map/Map.png", 0, 0, 1600, 900, 0, 0));
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("Map/MapTown.png", "Map/MapTownHovered.png", 575 * 1600 / 1920, 550 * 900 / 1080, 294.8 * 1600 / 1920, 257.2 * 900 / 1080, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Map::TownOnclick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("Map/Port.png", "Map/PortHovered.png", 870 * 1600 / 1920, 570 * 900 / 1080, 298.6 * 1600 / 1920, 181.10 * 900 / 1080, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Map::PortOnClick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("Map/MushroomFarm.png", "Map/MushroomFarmHovered.png", 914 * 1600 / 1920, 397 * 900 / 1080, 360 * 1600 / 1920, 190 * 900 / 1080, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Map::MushroomFarmOnClick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("Map/Hideaway.png", "Map/HideawayHovered.png", 1183.5 * 1600 / 1920, 279.1 * 900 / 1080, 183.8 * 1600 / 1920, 79.4 * 900 / 1080, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Map::HideawayOnClick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("Map/Laboratory.png", "Map/LaboratoryHovered.png", 456.5 * 1600 / 1920, 413.5 * 900 / 1080, 252.7 * 1600 / 1920, 53.9 * 900 / 1080, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Map::LaboratoryOnClick, this, 1));
    AddNewControlObject(btn);
    Engine::LOG(Engine::INFO) << "Map created";
}
void Map::Terminate(){
    IScene::Terminate();
}
void Map::OnKeyDown(int keyCode){
    const std::string StageName = Global::previousScene;
    switch(keyCode){
        case ALLEGRO_KEY_C:
            Engine::GameEngine::GetInstance().ChangeScene(StageName);
            break;
    }
}
void Map::TownOnclick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("VillageToBackery");
}
void Map::PortOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("Port");
}
void Map::MushroomFarmOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("MushroomFarm");
}
void Map::HideawayOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("Hideaway");
}
void Map::LaboratoryOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("Laboratory");
}
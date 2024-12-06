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
#include "Character/MainCharacter.hpp"
#include "Character/Althea.hpp"
#include "Shared/Global.hpp"
#include "VillageToBackery.hpp"

static ALLEGRO_SAMPLE_ID MedievalBGM;
MainCharacter* MC;
Althea* _Althea;
void VillageToBackery::Initialize() {
    Engine::LOG(Engine::INFO) << "VillageToBackery initialized";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("Act1/Glyswen/HomeToBackery.jpg", 0, 0, w, h, 0, 0));
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(100, 404), 80);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
    Althea* _Althea = new Althea("Character/Althea/Altheaidle.png", Engine::Point(1080, 600), 80);
    if(!_Althea){
        Engine::LOG(Engine::ERROR) << "Failed to create Althea";
        return;
    }
    AddNewObject(_Althea);
    WangHanZunFont = Engine::Resources::GetInstance().GetFont("WangHanZun.ttf", 30);
}
void VillageToBackery::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(MC -> Position.x > 1030.56 && MC -> Position.x < 1135.42 && MC -> Position.y > 561.505 && MC -> Position.y < 620.122) {
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 50, MC -> Position.y - 88, 0, "按E查看");
    }
}
void VillageToBackery::Terminate() {
    MC = nullptr;
    _Althea = nullptr;
    IScene::Terminate();
}
void VillageToBackery::Update(float deltaTime) {
    IScene::Update(deltaTime);
    if(MC -> Position.x < 724.477 && MC -> Position.y < 403.004) MC -> Stop();
    if(MC -> Position.x > 791.991 && MC -> Position.y < 404) MC -> Stop();
    if(MC -> Position.x < 721.444 && MC -> Position.y > 448.802) MC -> Stop();
    if(MC -> Position.x > 796.075 && MC -> Position.y > 446.783 && 
        !(MC -> Position.x > 775.612 && MC -> Position.y > 567.874 && MC -> Position.x < 1135.42) && !(MC -> Position.x > 775.612 && MC -> Position.x < 1135.42&& MC -> Position.y < 610.533)) MC -> Stop();
}
void VillageToBackery::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_W:
            MC->MoveUp(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_S:
            MC->MoveDown(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_L:
            MC -> Position.x = 1031;
            MC -> Position.y = 563;
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x > 1030.56 && MC -> Position.x < 1135.42 && MC -> Position.y > 561.505 && MC -> Position.y < 620.122){
                Engine::GameEngine::GetInstance().ChangeScene("Bakery");
            }
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
            break;
    }
}
void VillageToBackery::OnKeyUp(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_A:
        case ALLEGRO_KEY_D:
        case ALLEGRO_KEY_W:
        case ALLEGRO_KEY_S:
            MC->Stop();
            break;
    }
}
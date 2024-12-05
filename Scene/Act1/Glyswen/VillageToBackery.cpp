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
#include "Shared/Global.hpp"
#include "VillageToBackery.hpp"

static ALLEGRO_SAMPLE_ID MedievalBGM;
extern MainCharacter* MC;
void VillageToBackery::Initialize() {
    Engine::LOG(Engine::INFO) << "VillageToBackery initialized";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("Act1/Glyswen/HomeToBackery.jpg", 0, 0, w, h, 0, 0));
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(800, 300), 200);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
}
void VillageToBackery::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
}
void VillageToBackery::Terminate() {
    MC = nullptr;
    IScene::Terminate();
}
void VillageToBackery::Update(float deltaTime) {
    IScene::Update(deltaTime);
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
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
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
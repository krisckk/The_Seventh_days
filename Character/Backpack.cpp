#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_acodec.h>

#include <Engine/GameEngine.hpp>
#include <Engine/LOG.hpp>
#include <Shared/Global.hpp>
#include "Backpack.hpp"

void Backpack::Initialize() {
    Engine::LOG(Engine::INFO) << "Backpack Scene initialized";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Backpack Scene created";
}
void Backpack::Draw() const{
    IScene::Draw();
}
void Backpack::Terminate() {
    IScene::Terminate();
}
void Backpack::OnKeyDown(int keyCode) {
    const std::string PreviousScene = Global::previousScene;
    if(keyCode == ALLEGRO_KEY_C){
        Engine::GameEngine::GetInstance().ChangeScene(PreviousScene);
    }
}
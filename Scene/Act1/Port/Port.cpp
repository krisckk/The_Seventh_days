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
#include "Character/Adrian.hpp"
#include "Shared/Global.hpp"
#include "Port.hpp"
Adrian* _Adrian;

void Port::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("Act1/Port/HarborBackground.png", 0, 0, w, h, 0, 0));
    WoodenBox1 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox1.png");
    WoodenBox2 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox2.png");
    WoodenBox3 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox3.png");
    WangHanZunFont = Engine::Resources::GetInstance().GetFont("WangHanZun.ttf", 36);
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(100, 680), 80);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
    _Adrian = new Adrian("Character/Adrian/Adrianidle.png", Engine::Point(100, 720), 80);
    if(!_Adrian){
        Engine::LOG(Engine::ERROR) << "Failed to create Adrian";
        return;
    }
    AddNewObject(_Adrian);
}
void Port::Terminate(){
    MC = nullptr;
    _Adrian = nullptr;
    IScene::Terminate();
}
void Port::Update(float deltaTime){
    IScene::Update(deltaTime);
}
void Port::Draw() const{
    IScene::Draw();
}
void Port::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_D:
            MC -> MoveRight(1.0f / 120.0f);
            _Adrian -> MoveRight(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_A:
            MC -> MoveLeft(1.0f / 120.0f);
            _Adrian -> MoveLeft(1.0f / 120.0f);
            break;
    }
}
void Port::OnKeyUp(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_D:
        case ALLEGRO_KEY_A:
            MC -> Stop();
            _Adrian -> Stop();
            break;
    }
}

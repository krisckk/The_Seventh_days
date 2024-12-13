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
bool ifWoodenboxDisplacement = false;

int WoodenBoxDisplacement = 0;

void Port::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    showTextBox = true;
    Epressed = false;
    EmeraldGet = false;
    AddNewObject(new Engine::Image("Act1/Port/HarborBackground.png", 0, 0, w, h, 0, 0));
    WoodenBox1 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox1.png");
    WoodenBox2 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox2.png");
    WoodenBox3 = Engine::Resources::GetInstance().GetBitmap("Act1/Port/WoodenBox3.png");
    Emerald = Engine::Resources::GetInstance().GetBitmap("Act1/Port/Emerald.png");
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
    UpdateTextBox(deltaTime);
    IScene::Update(deltaTime);
    if(!ifWoodenboxDisplacement) WoodenBoxDisplacement--;
    else WoodenBoxDisplacement++;
    if(WoodenBoxDisplacement < -50) ifWoodenboxDisplacement = true;
    else if(WoodenBoxDisplacement == 0) ifWoodenboxDisplacement = false;
}
void Port::Draw() const{
    IScene::Draw();
    if(showTextBox && EmeraldGet) {
        al_draw_filled_rounded_rectangle(_Adrian -> Position.x - 70, _Adrian-> Position.y - 140, _Adrian -> Position.x + 330, _Adrian -> Position.y - 35, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 50, MC -> Position.y - 88, 0, "看，有個會動的箱子");
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 50, MC -> Position.y - 48, 0, "我們去看看吧");
    }
    if(MC -> Position.x > 1140 && MC -> Position.x < 1230) {
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 70, MC -> Position.y - 88, 0, "按E查看");
    }
    if(!Epressed) al_draw_scaled_bitmap(WoodenBox1.get(), 0, 0, al_get_bitmap_width(WoodenBox1.get()), al_get_bitmap_width(WoodenBox1.get()), 1300, MC -> Position.y + WoodenBoxDisplacement, 100, 100, 0);
    else{
        if(!EmeraldGet)al_draw_scaled_bitmap(Emerald.get(), 0, 0, al_get_bitmap_width(Emerald.get()), al_get_bitmap_width(Emerald.get()), 1300, _Adrian -> Position.y + WoodenBoxDisplacement, 50, 50, 0);
    }

}
void Port::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_D:
            if(!showTextBox){
                MC -> MoveRight(1.0f / 120.0f);
                _Adrian -> MoveRight(1.0f / 120.0f);
            }
            break;
        case ALLEGRO_KEY_A:
            if(!showTextBox){
                MC -> MoveLeft(1.0f / 120.0f);
                _Adrian -> MoveLeft(1.0f / 120.0f);
            }
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x > 1140 && MC -> Position.x < 1230 && Epressed) EmeraldGet= true;
            if(MC -> Position.x > 1140 && MC -> Position.x < 1230){
                Epressed = true;
            }
            if(EmeraldGet) Engine::GameEngine::GetInstance().ChangeScene("EmeraldGetNarration");
            break;
        case ALLEGRO_KEY_P:
            Engine::GameEngine::GetInstance().ChangeScene("PauseScene");
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
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
void Port::UpdateTextBox(float deltaTime){
    textBoxTimer += deltaTime;
    if(textBoxTimer >= 2.0f) showTextBox = false;
}
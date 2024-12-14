#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_video.h>
#include <Engine/AudioHelper.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/Resources.hpp>
#include <Engine/Sprite.hpp>
#include <Engine/LOG.hpp>
#include <UI/Component/Label.hpp>
#include "Character/MainCharacter.hpp"
#include "Shared/Global.hpp"
#include "MushroomFarm.hpp"
void MushroomFarm::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Redmushroom1Get = false;
    Redmushroom2Get = false;
    Whitemushroom1Get = false;
    Whitemushroom2Get = false;
    AddNewObject(new Engine::Image("Act1/MushroomFarm/MushroomFarm.jpg", 0, 0, w, h, 0, 0));
    RedMushroom1 = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/RedMushroom.png");
    RedMushroom2 = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/RedMushroom.png");
    WhiteMushroom1 = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/WhiteMushroom.png");
    WhiteMushroom2 = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/WhiteMushroom.png");
    WangHanZunFont = Engine::Resources::GetInstance().GetFont("WangHanZun.ttf", 36);
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(100, 620), 80);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
}
void MushroomFarm::Terminate(){
    MC = nullptr;
    IScene::Terminate();
}
void MushroomFarm::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(!Redmushroom1Get) al_draw_scaled_bitmap(RedMushroom1.get(), 0, 0, al_get_bitmap_width(RedMushroom1.get()), al_get_bitmap_height(RedMushroom1.get()), 670, 100, 100, 100, 0);
    if(!Redmushroom2Get) al_draw_scaled_bitmap(RedMushroom2.get(), 0, 0, al_get_bitmap_width(RedMushroom2.get()), al_get_bitmap_height(RedMushroom2.get()), 670, 500, 100, 100, 0);
    if(!Whitemushroom1Get) al_draw_scaled_bitmap(WhiteMushroom1.get(), 0, 0, al_get_bitmap_width(WhiteMushroom1.get()), al_get_bitmap_height(WhiteMushroom1.get()), 1500, 650, 80, 80, 0);
    if(!Whitemushroom2Get) al_draw_scaled_bitmap(WhiteMushroom2.get(), 0, 0, al_get_bitmap_width(WhiteMushroom2.get()), al_get_bitmap_height(WhiteMushroom2.get()), 1000, 650, 80, 80, 0);
    if(MC -> Position.x > 1460 && MC -> Position.x < 1580 && MC -> Position.y > 580 && MC -> Position.y < 670){
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 60, MC -> Position.y - 88, 0, "按E揀取");
    }
    if(MC -> Position.x > 960 && MC -> Position.x < 1080 && MC -> Position.y > 580 && MC -> Position.y < 670){
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 60, MC -> Position.y - 88, 0, "按E揀取");
    }
    if(MC -> Position.x > 630 && MC -> Position.x < 750 && MC -> Position.y > 30 && MC -> Position.y < 120){
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 60, MC -> Position.y - 88, 0, "按E揀取");
    }
    if(MC -> Position.x > 630 && MC -> Position.x < 750 && MC -> Position.y > 430 && MC -> Position.y < 520){
        al_draw_filled_rounded_rectangle(MC -> Position.x - 80, MC-> Position.y - 100, MC -> Position.x + 80, MC -> Position.y - 50, 10, 10, al_map_rgb(64, 64, 64));
        al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), MC -> Position.x - 60, MC -> Position.y - 88, 0, "按E揀取");
    }
}
void MushroomFarm::Update(float deltaTime){
    IScene::Update(deltaTime);
}
void MushroomFarm::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_W:
            MC->MoveUp(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_S:
            MC->MoveDown(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x > 960 && MC -> Position.x < 1080 && MC -> Position.y > 580 && MC -> Position.y < 670){
                Whitemushroom1Get = true;
            }
            if(MC -> Position.x > 1460 && MC -> Position.x < 1580 && MC -> Position.y > 580 && MC -> Position.y < 670){
                Whitemushroom2Get = true;
            }
            if(MC -> Position.x > 630 && MC -> Position.x < 750 && MC -> Position.y > 30 && MC -> Position.y < 120) {
                Redmushroom1Get = true;
                Engine::GameEngine::GetInstance().ChangeScene("MushroomFarmSecondNarration");
            }
            if(MC -> Position.x > 630 && MC -> Position.x < 750 && MC -> Position.y > 430 && MC -> Position.y < 520){
                Redmushroom2Get = true;
                Engine::GameEngine::GetInstance().ChangeScene("MushroomFarmSecondNarration");
            }
            break;
    }
}
void MushroomFarm::OnKeyUp(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_W:
        case ALLEGRO_KEY_A:
        case ALLEGRO_KEY_S:
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
    }
}
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
#include "TuesdayBakery.hpp"

void TuesdayBakery::Initialize(){
    NotebookGet = false;
    AddNewObject(new Engine::Image("Act2/Tuesday/Bakery/TuesdayBakery.jpg", 0, 0, Global::Width, Global::Height, 0, 0));
    Notebook = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/Bakery/Notebook.png");
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(100, 620), 80);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
}
void TuesdayBakery::Terminate(){
    MC = nullptr;
    IScene::Terminate();
}
void TuesdayBakery::Draw() const{
    IScene::Draw();
    if(!NotebookGet) al_draw_scaled_bitmap(Notebook.get(), 0, 0, al_get_bitmap_width(Notebook.get()), al_get_bitmap_height(Notebook.get()), 1000, 500, 50, 50, 0);
}
void TuesdayBakery::Update(float deltaTime){
    Engine::LOG(Engine::INFO) << MC -> Position.x << " " << MC -> Position.y;
    IScene::Update(deltaTime);
}
void TuesdayBakery::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_W:
            MC -> MoveUp(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_S:
            MC -> MoveDown(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_A:
            MC -> MoveLeft(1.0f / 120.0f);
            break;
        case ALLEGRO_KEY_D:
            MC -> MoveRight(1.0f / 120.0f);
            break;
        
    }
}
void TuesdayBakery::OnKeyUp(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_W:
        case ALLEGRO_KEY_A:
        case ALLEGRO_KEY_S:
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
    }
}
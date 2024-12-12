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
#include "EmeraldGetNarration.hpp"

void EmeraldGetNarration::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act1/Port/EmeraldGetNarration/FirstImage.png");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act1/Port/EmeraldGetNarration/SecondImage.png");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act1/Port/EmeraldGetNarration/ThirdImage.png");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Port/EmeraldGetNarration/FourthImage.png");
}
void EmeraldGetNarration::Draw() const{
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if(showTextBox == 0){
        al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 1) {
        al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 2) {
        al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 3) {
        al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, 1600, 900, 0);
    }
}
void EmeraldGetNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void EmeraldGetNarration::Terminate() {
    IScene::Terminate();
}
void EmeraldGetNarration::OnKeyDown(int keyCode) {
    switch (keyCode)
    {
        case ALLEGRO_KEY_C:
            showTextBox++;
            break;
    }
}
void EmeraldGetNarration::OnKeyUp(int keyCode) {}
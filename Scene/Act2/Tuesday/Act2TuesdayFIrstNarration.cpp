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
#include "Shared/Global.hpp" 
#include "Act2TuesdayFirstNarration.hpp"

void Act2TuesdayFirstNarration::Initialize() {
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/FifthImage.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SixthImage.jpg");
}
void Act2TuesdayFirstNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Act2TuesdayFirstNarration::Draw() const {
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void Act2TuesdayFirstNarration::Terminate() {
    IScene::Terminate();
}
void Act2TuesdayFirstNarration::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox < 5) showTextBox++;
            else if(showTextBox == 5) Engine::GameEngine::GetInstance().ChangeScene("Act2MondayNarration");
            break;
    }
}
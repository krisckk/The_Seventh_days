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
#include "Act2TuesdaySecondNarration.hpp"

void Act2TuesdaySecondNarration::Initialize() {
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/FifthImage.jpg");
    FirstChoice = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/FirstChoice.jpg");
    SecondChoice = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/SecondChoice.jpg");
    GroupPhoto = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/GroupPhoto.jpg");
    LastImage = Engine::Resources::GetInstance().GetBitmap("Act2/Tuesday/SecondNarration/LastImage.jpg");
}
void Act2TuesdaySecondNarration::Terminate() {
    IScene::Terminate();
}
void Act2TuesdaySecondNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Act2TuesdaySecondNarration::Draw() const {
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 5) al_draw_scaled_bitmap(FirstChoice.get(), 0, 0, al_get_bitmap_width(FirstChoice.get()), al_get_bitmap_height(FirstChoice.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 6) al_draw_scaled_bitmap(SecondChoice.get(), 0, 0, al_get_bitmap_width(SecondChoice.get()), al_get_bitmap_height(SecondChoice.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 7) al_draw_scaled_bitmap(GroupPhoto.get(), 0, 0, al_get_bitmap_width(GroupPhoto.get()), al_get_bitmap_height(GroupPhoto.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 8) al_draw_scaled_bitmap(LastImage.get(), 0, 0, al_get_bitmap_width(LastImage.get()), al_get_bitmap_height(LastImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void Act2TuesdaySecondNarration::OnKeyDown(int keyCode) {
    switch(keyCode) {
        case ALLEGRO_KEY_C:
            if(showTextBox < 5) showTextBox++;
            else if(showTextBox == 8) Engine::GameEngine::GetInstance().ChangeScene("Act2WednesdayNarration");
            else if(showTextBox >= 7) showTextBox++;
            break;
        case ALLEGRO_KEY_W:
            if(showTextBox == 6) showTextBox = 5;
            break;
        case ALLEGRO_KEY_S:
            if(showTextBox == 5) showTextBox = 6;
            break;
        case ALLEGRO_KEY_ENTER:
            if(showTextBox == 5) {
                showTextBox = 7;
                Global::GroupPhotoGet = true;
            }
            else if(showTextBox == 6) showTextBox = 8;
            break;
    }
}
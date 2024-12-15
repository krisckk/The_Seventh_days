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
#include "Act2ThursdayNarration.hpp"

void Act2ThursdayNarration::Initialize() {
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/ThirdImage.jpg");
    FirstchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/FirstchoiceResult.jpg");
    SecondchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/SecondchoiceResult.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/FifthImage.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Thursday/SixthImage.jpg");
}
void Act2ThursdayNarration::Terminate() {
    IScene::Terminate();
}
void Act2ThursdayNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Act2ThursdayNarration::Draw() const {
    IScene::Draw();
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 3) al_draw_scaled_bitmap(FirstchoiceResult.get(), 0, 0, al_get_bitmap_width(FirstchoiceResult.get()), al_get_bitmap_height(FirstchoiceResult.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 4) al_draw_scaled_bitmap(SecondchoiceResult.get(), 0, 0, al_get_bitmap_width(SecondchoiceResult.get()), al_get_bitmap_height(SecondchoiceResult.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 5) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 6) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 7) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void Act2ThursdayNarration::OnKeyDown(int keyCode) {
    switch(keyCode) {
        case ALLEGRO_KEY_C:
            if(showTextBox == 0) showTextBox = 1;
            else if(showTextBox == 3 || showTextBox == 4) showTextBox = 5;
            else if(showTextBox == 5) showTextBox = 6;
            else if(showTextBox == 6) showTextBox = 7;
            else if(showTextBox == 7) Engine::GameEngine::GetInstance().ChangeScene("Act2FridayNarration");
            break;
        case ALLEGRO_KEY_ENTER:
            if(showTextBox == 2){
                showTextBox = 4;
                Global::impressionLevel += 1;
            }
            else if(showTextBox == 1){
                showTextBox = 3;
                Global::impressionLevel += 2;
            }
            break;
    }
}
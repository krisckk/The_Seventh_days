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
#include "HideawayNarration.hpp"

void HideawayNarration::Initialize() {
    int halfW = Global::Width / 2;
    int halfH = Global::Height / 2;
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/FifthImage.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/SixthImage.jpg");
    SeventhImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/SeventhImage.jpg");
    EighthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/EighthImage.jpg");
    NinethImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/NinethImage.jpg");
    TenthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/TenthImage.jpg");
    Firstchoice = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/Firstchoice.jpg");
    SecondChoice = Engine::Resources::GetInstance().GetBitmap("Act1/Saturday/Hideaway/SecondChoice.jpg");
}
void HideawayNarration::Terminate() {
    IScene::Terminate();
}
void HideawayNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void HideawayNarration::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox < 7) showTextBox++;
            else if(showTextBox == 11) Engine::GameEngine::GetInstance().ChangeScene("FirstSundayNarration");
            else if(showTextBox >= 9) showTextBox++;
            break;
        case ALLEGRO_KEY_W:
            if(showTextBox == 8) showTextBox = 7;
            break;
        case ALLEGRO_KEY_S:
            if(showTextBox == 7) showTextBox = 8;
            break;
        case ALLEGRO_KEY_ENTER:
            if(showTextBox == 7) {
                showTextBox = 9;
                Global::TellMoira = true;
            }
            else if(showTextBox == 8){
                showTextBox = 9;
                Global::TellMoira = false;
            }
            break;
    }
}
void HideawayNarration::Draw() const {
    if(showTextBox == 0){
        al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 1){
        al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 2){
        al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 3){
        al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 4){
        al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 5){
        al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 6){
        al_draw_scaled_bitmap(SeventhImage.get(), 0, 0, al_get_bitmap_width(SeventhImage.get()), al_get_bitmap_height(SeventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 7){
        al_draw_scaled_bitmap(Firstchoice.get(), 0, 0, al_get_bitmap_width(Firstchoice.get()), al_get_bitmap_height(Firstchoice.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 8){
        al_draw_scaled_bitmap(SecondChoice.get(), 0, 0, al_get_bitmap_width(SecondChoice.get()), al_get_bitmap_height(SecondChoice.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 9){
        al_draw_scaled_bitmap(EighthImage.get(), 0, 0, al_get_bitmap_width(EighthImage.get()), al_get_bitmap_height(EighthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 10){
        al_draw_scaled_bitmap(NinethImage.get(), 0, 0, al_get_bitmap_width(NinethImage.get()), al_get_bitmap_height(NinethImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(showTextBox == 11){
        al_draw_scaled_bitmap(TenthImage.get(), 0, 0, al_get_bitmap_width(TenthImage.get()), al_get_bitmap_height(TenthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
}
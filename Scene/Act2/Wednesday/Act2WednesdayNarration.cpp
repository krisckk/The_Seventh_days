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
#include "Act2WednesdayNarration.hpp"

void Act2WednesdayNarration::Initialize() {
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/FifthImage.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/SixthImage.jpg");
    SeventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/SeventhImage.jpg");
    if(Global::TellMoira){
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/TM_FirstImage.jpg");
        NinethImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/TM_SecondImage.jpg");
        TenthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/TM_ThirdImage.jpg");
        EleventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/TM_LastImage.jpg");
        
    }
    else {
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/NTM_FirstImage.jpg");
        NinethImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/NTM_SecondImage.jpg");
        TenthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/NTM_ThirdImage.jpg");
        EleventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/NTM_FourthImage.jpg");
    }
    Ending3FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/Ending3/FirstImage.jpg");
    Ending3SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/Ending3/SecondImage.jpg");
    Ending3ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/Ending3/ThirdImage.jpg");
    Ending3FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/Ending3/FourthImage.jpg");
    Ending3FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Wednesday/Ending3/FifthImage.jpg");
}
void Act2WednesdayNarration::Terminate() {
    IScene::Terminate();
}
void Act2WednesdayNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Act2WednesdayNarration::Draw() const {
    IScene::Draw();
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 6) al_draw_scaled_bitmap(SeventhImage.get(), 0, 0, al_get_bitmap_width(SeventhImage.get()), al_get_bitmap_height(SeventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 7) al_draw_scaled_bitmap(EighthImage.get(), 0, 0, al_get_bitmap_width(EighthImage.get()), al_get_bitmap_height(EighthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 8) al_draw_scaled_bitmap(NinethImage.get(), 0, 0, al_get_bitmap_width(NinethImage.get()), al_get_bitmap_height(NinethImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 9) al_draw_scaled_bitmap(TenthImage.get(), 0, 0, al_get_bitmap_width(TenthImage.get()), al_get_bitmap_height(TenthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 10) al_draw_scaled_bitmap(EleventhImage.get(), 0, 0, al_get_bitmap_width(EleventhImage.get()), al_get_bitmap_height(EleventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 11) al_draw_scaled_bitmap(Ending3FirstImage.get(), 0, 0, al_get_bitmap_width(Ending3FirstImage.get()), al_get_bitmap_height(Ending3FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 12) al_draw_scaled_bitmap(Ending3SecondImage.get(), 0, 0, al_get_bitmap_width(Ending3SecondImage.get()), al_get_bitmap_height(Ending3SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 13) al_draw_scaled_bitmap(Ending3ThirdImage.get(), 0, 0, al_get_bitmap_width(Ending3ThirdImage.get()), al_get_bitmap_height(Ending3ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 14) al_draw_scaled_bitmap(Ending3FourthImage.get(), 0, 0, al_get_bitmap_width(Ending3FourthImage.get()), al_get_bitmap_height(Ending3FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    else if(showTextBox == 15) al_draw_scaled_bitmap(Ending3FifthImage.get(), 0, 0, al_get_bitmap_width(Ending3FifthImage.get()), al_get_bitmap_height(Ending3FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void Act2WednesdayNarration::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox < 10) showTextBox++;
            else if(Global::TellMoira && showTextBox == 10) Engine::GameEngine::GetInstance().ChangeScene("Act2ThursdayNarration");
            else if(!Global::TellMoira && showTextBox >= 10){
                if(showTextBox == 15){
                    Global::endingType = "3";
                    Engine::GameEngine::GetInstance().ChangeScene("StartScene");
                }
                showTextBox++;
            }
            break;
    }
}
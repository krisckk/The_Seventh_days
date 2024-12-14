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
#include "Act2MondayNarration.hpp"

void Act2MondayNarration::Initialize(){
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FifthImage.jpg");
    if(Global::TellMoira){
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FC_FirstImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FC_SecondImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FC_ThirdImage.jpg");
        NinethImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FC_FourthImage.jpg");
        TenthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/FC_FifthImage.jpg");
    }
    else {
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SC_FirstImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SC_SecondImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SC_ThirdImage.jpg");
        NinethImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SC_FourthImage.jpg");
        TenthImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/SC_FifthImage.jpg");
    }
    EleventhImage = Engine::Resources::GetInstance().GetBitmap("Act2/Monday/LastImage.jpg");
}
void Act2MondayNarration::Terminate() {
    IScene::Terminate();
}
void Act2MondayNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Act2MondayNarration::Draw() const {
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 6) al_draw_scaled_bitmap(SeventhImage.get(), 0, 0, al_get_bitmap_width(SeventhImage.get()), al_get_bitmap_height(SeventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 7) al_draw_scaled_bitmap(EighthImage.get(), 0, 0, al_get_bitmap_width(EighthImage.get()), al_get_bitmap_height(EighthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 8) al_draw_scaled_bitmap(NinethImage.get(), 0, 0, al_get_bitmap_width(NinethImage.get()), al_get_bitmap_height(NinethImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 9) al_draw_scaled_bitmap(TenthImage.get(), 0, 0, al_get_bitmap_width(TenthImage.get()), al_get_bitmap_height(TenthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 10) al_draw_scaled_bitmap(EleventhImage.get(), 0, 0, al_get_bitmap_width(EleventhImage.get()), al_get_bitmap_height(EleventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void Act2MondayNarration::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox < 10) showTextBox++;
            else if(showTextBox == 10) Engine::GameEngine::GetInstance().ChangeScene("Act2TuesdayFirstNarration");
            break;
    }
}

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
#include "Ending.hpp"

void Ending::Initialize(){
    if(Global::impressionLevel >= 6 && Global::GiveEmeraldToAlthea && Global::TellMoira && Global::GroupPhotoGet){
        Global::endingType = "1.1";
        FirstImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/FirstImage.jpg");
        SecondImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/SecondImage.jpg");
        ThirdImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/ThirdImage.jpg");
        FourthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/FourthImage.jpg");
        FifthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/FifthImage.jpg");
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/SixthImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/SeventhImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-1/EighthImage.jpg");
    }
    else if(Global::impressionLevel < 6 && Global::GiveEmeraldToAlthea && Global::TellMoira && Global::GroupPhotoGet){
        Global::endingType = "1.2";
        FirstImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FirstImage.jpg");
        SecondImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/SecondImage.jpg");
        ThirdImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/ThirdImage.jpg");
        FourthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FourthImage.jpg");
        FifthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FourthImage.jpg");
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FourthImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FourthImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Ending/1-2/FourthImage.jpg");
    }
    else if(Global::GiveEmeraldToAlthea && !Global::TellMoira && !Global::GroupPhotoGet){
        Global::endingType = "2.1";
        FirstImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/FirstImage.jpg");
        SecondImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/SecondImage.jpg");
        ThirdImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/ThirdImage.jpg");
        FourthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/FourthImage.jpg");
        FifthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/FifthImage.jpg");
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/SixthImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/SixthImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-1/SixthImage.jpg");
    }
    else if(!Global::GiveEmeraldToAlthea && !Global::TellMoira && !Global::GroupPhotoGet){
        Global::endingType = "2.2";
        FirstImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FirstImage.jpg");
        SecondImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/SecondImage.jpg");
        ThirdImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/ThirdImage.jpg");
        FourthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FourthImage.jpg");
        FifthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FourthImage.jpg");
        SixthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FourthImage.jpg");
        SeventhImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FourthImage.jpg");
        EighthImage = Engine::Resources::GetInstance().GetBitmap("Ending/2-2/FourthImage.jpg");
    }
}
void Ending::Update(float deltaTime){
    IScene::Update(deltaTime);
}
void Ending::Terminate(){
    IScene::Terminate();
}
void Ending::Draw() const {
    IScene::Draw();
    if(Global::endingType == "1.1"){
        if(showTextbox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 6) al_draw_scaled_bitmap(SeventhImage.get(), 0, 0, al_get_bitmap_width(SeventhImage.get()), al_get_bitmap_height(SeventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 7) al_draw_scaled_bitmap(EighthImage.get(), 0, 0, al_get_bitmap_width(EighthImage.get()), al_get_bitmap_height(EighthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "1.2"){
        if(showTextbox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "2.1"){
        if(showTextbox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "2.2"){
        if(showTextbox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
        else if(showTextbox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
}
void Ending::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(Global::endingType == "1.1"){
                if(showTextbox < 7) showTextbox++;
                else if(showTextbox == 7) Engine::GameEngine::GetInstance().ChangeScene("Achievement");
            }
            else if(Global::endingType == "1.2"){
                if(showTextbox < 3) showTextbox++;
                else if(showTextbox == 3) Engine::GameEngine::GetInstance().ChangeScene("Achievement");
            }
            else if(Global::endingType == "2.1"){
                if(showTextbox < 5) showTextbox++;
                else if(showTextbox == 5) Engine::GameEngine::GetInstance().ChangeScene("Achievement");
            }
            else if(Global::endingType == "2.2"){
                if(showTextbox < 3) showTextbox++;
                else if(showTextbox == 3) Engine::GameEngine::GetInstance().ChangeScene("Achievement");
            }
            break;
    }
}
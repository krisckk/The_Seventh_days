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
#include "Achievement.hpp"

void Achievement::Initialize(){
    JetBrinsMono = Engine::Resources::GetInstance().GetFont("JetBrainsMono.ttf", 36);
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Achievement/0.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Achievement/1_1.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Achievement/1_2.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Achievement/2_1.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Achievement/2_2.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Achievement/3.jpg");
}
void Achievement::Terminate(){
    IScene::Terminate();
}
void Achievement::Update(float deltaTime){
    IScene::Update(deltaTime);
}
void Achievement::Draw() const{
    if(Global::endingType == ""){
        al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "1_1"){
        al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "1_2"){
        al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "2_1"){
        al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "2_2"){
        al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    else if(Global::endingType == "3"){
        al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    }
    al_draw_text(JetBrinsMono.get(), al_map_rgb(255, 255, 255), 800, 850, ALLEGRO_ALIGN_CENTER, "Press Enter to return to the main menu");
}
void Achievement::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_ENTER:
            Engine::GameEngine::GetInstance().ChangeScene("StartScene");
            break;
    }
}
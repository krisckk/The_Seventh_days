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
#include "FirstNarration.hpp"

void MushroomFarmFirstNarration::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    MFFirstNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/FirstNarration.jpg");
    MFSecondNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/SecondNarration.jpg");
    MFThirdNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/ThirdNarration.jpg");
    MFFourthNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/FourthNarration.jpg");
    MFFifthNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/FifthNarration.jpg");
}   
void MushroomFarmFirstNarration::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox == 4){
        al_draw_scaled_bitmap(MFFifthNarration.get(), 0, 0, al_get_bitmap_width(MFFifthNarration.get()), al_get_bitmap_height(MFFifthNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 3){
        al_draw_scaled_bitmap(MFFourthNarration.get(), 0, 0, al_get_bitmap_width(MFFourthNarration.get()), al_get_bitmap_height(MFFourthNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 2){
        al_draw_scaled_bitmap(MFThirdNarration.get(), 0, 0, al_get_bitmap_width(MFThirdNarration.get()), al_get_bitmap_height(MFThirdNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 1){
        al_draw_scaled_bitmap(MFSecondNarration.get(), 0, 0, al_get_bitmap_width(MFSecondNarration.get()), al_get_bitmap_height(MFSecondNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 0){
        al_draw_scaled_bitmap(MFFirstNarration.get(), 0, 0, al_get_bitmap_width(MFFirstNarration.get()), al_get_bitmap_height(MFFirstNarration.get()), 0, 0, 1600, 900, 0);
    }
}    
void MushroomFarmFirstNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void MushroomFarmFirstNarration::Terminate(){
    IScene::Terminate();
}
void MushroomFarmFirstNarration::OnKeyDown(int keyCode) {
    switch (keyCode)
    {
        case ALLEGRO_KEY_C:
            if(showTextBox == 0 || showTextBox == 1 || showTextBox == 2 || showTextBox == 3) showTextBox++;
            else if(showTextBox == 4) Engine::GameEngine::GetInstance().ChangeScene("MushroomFarm");
            break;
    }
}
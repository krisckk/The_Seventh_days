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
#include "SecondNarration.hpp"

void MushroomFarmSecondNarration::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    MFSixthNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/SixthNarration.jpg");
    MFSeventhNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/SeventhNarration.jpg");
    MFEighthNarration = Engine::Resources::GetInstance().GetBitmap("Act1/MushroomFarm/Narration/EighthNarration.jpg");
}
void MushroomFarmSecondNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void MushroomFarmSecondNarration::Terminate() {
    IScene::Terminate();
}
void MushroomFarmSecondNarration::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox == 2){
        al_draw_scaled_bitmap(MFEighthNarration.get(), 0, 0, al_get_bitmap_width(MFEighthNarration.get()), al_get_bitmap_height(MFEighthNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 1){
        al_draw_scaled_bitmap(MFSeventhNarration.get(), 0, 0, al_get_bitmap_width(MFSeventhNarration.get()), al_get_bitmap_height(MFSeventhNarration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 0){
        al_draw_scaled_bitmap(MFSixthNarration.get(), 0, 0, al_get_bitmap_width(MFSixthNarration.get()), al_get_bitmap_height(MFSixthNarration.get()), 0, 0, 1600, 900, 0);
    }
}
void MushroomFarmSecondNarration::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox == 0){
                showTextBox = 1;
            }
            else if(showTextBox == 1){
                showTextBox = 2;
            }
            else if(showTextBox == 2){
                Engine::GameEngine::GetInstance().ChangeScene("BakeryNarration");
            }
            break;
    }
}
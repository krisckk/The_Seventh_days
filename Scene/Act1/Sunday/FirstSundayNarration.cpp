#include <cmath>
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
#include "FirstSundayNarration.hpp"

void FirstSundayNarration::Initialize() {
    TextTimer = 0;
    showTextBox = 0;
    int halfW = Global::Width / 2;
    int halfH = Global::Height / 2;
    FirstImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/FirstImage.jpg");
    SecondImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/SecondImage.jpg");
    ThirdImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/ThirdImage.jpg");
    FourthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/FourthImage.jpg");
    FifthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/FifthImage.jpg");
    SixthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/SixthImage.jpg");
    SeventhImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/SeventhImage.jpg");
    EighthImage = Engine::Resources::GetInstance().GetBitmap("Act1/Sunday/EighthImage.jpg");
}
void FirstSundayNarration::Terminate() {
    IScene::Terminate();
}
void FirstSundayNarration::Update(float deltaTime) {
    if(showTextBox <= 7) UpdateTextTimer(deltaTime);
    IScene::Update(deltaTime);
}
void FirstSundayNarration::Draw() const {
    if(showTextBox == 0) al_draw_scaled_bitmap(FirstImage.get(), 0, 0, al_get_bitmap_width(FirstImage.get()), al_get_bitmap_height(FirstImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 1) al_draw_scaled_bitmap(SecondImage.get(), 0, 0, al_get_bitmap_width(SecondImage.get()), al_get_bitmap_height(SecondImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 2) al_draw_scaled_bitmap(ThirdImage.get(), 0, 0, al_get_bitmap_width(ThirdImage.get()), al_get_bitmap_height(ThirdImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 3) al_draw_scaled_bitmap(FourthImage.get(), 0, 0, al_get_bitmap_width(FourthImage.get()), al_get_bitmap_height(FourthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 4) al_draw_scaled_bitmap(FifthImage.get(), 0, 0, al_get_bitmap_width(FifthImage.get()), al_get_bitmap_height(FifthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 5) al_draw_scaled_bitmap(SixthImage.get(), 0, 0, al_get_bitmap_width(SixthImage.get()), al_get_bitmap_height(SixthImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox == 6) al_draw_scaled_bitmap(SeventhImage.get(), 0, 0, al_get_bitmap_width(SeventhImage.get()), al_get_bitmap_height(SeventhImage.get()), 0, 0, Global::Width, Global::Height, 0);
    if(showTextBox >= 7) al_draw_scaled_bitmap(EighthImage.get(), 0, 0, al_get_bitmap_width(EighthImage.get()), al_get_bitmap_height(EighthImage.get()), 0, 0, Global::Width, Global::Height, 0);
}
void FirstSundayNarration::UpdateTextTimer(float deltaTime) {
    TextTimer += deltaTime;
    showTextBox = TextTimer / 3.0f;
}
void FirstSundayNarration::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox >= 7) Engine::GameEngine::GetInstance().ChangeScene("Act2MondayNarration");
            break;
    }
}

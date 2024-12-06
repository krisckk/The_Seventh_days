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
#include "Bakery.hpp"

void Bakery::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Bakery Scene Initialized";
    Bakery1narration = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/Bakery1narration.jpg");
    Bakery2narration = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/Bakery2narration.jpg");
    BakeryFirstChoice = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/BakeryFirstChoice.jpg");
    BakerySecondChoice = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/BakerySecondChoice.jpg");
    BakeryFirstchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/BakeryFirstchoiceResult.jpg");
    BakerySecondchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/BakerySecondchoiceResult.jpg");
    BakeryImpressionLevelReveal = Engine::Resources::GetInstance().GetBitmap("Act1/Bakery/BakeryImpressionLevelReveal.jpg");
    WangHanZunFont = Engine::Resources::GetInstance().GetFont("WangHanZun.ttf", 36);
    Engine::LOG(Engine::INFO) << "Bakery Scene Created";
}
void Bakery::Terminate() {
    IScene::Terminate();
}
void Bakery::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox == 0) al_draw_scaled_bitmap(Bakery1narration.get(), 0, 0, al_get_bitmap_width(Bakery1narration.get()), al_get_bitmap_height(Bakery1narration.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 1) al_draw_scaled_bitmap(BakeryFirstChoice.get(), 0, 0, al_get_bitmap_width(BakeryFirstChoice.get()), al_get_bitmap_height(BakeryFirstChoice.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 2) al_draw_scaled_bitmap(BakerySecondChoice.get(), 0, 0, al_get_bitmap_width(BakerySecondChoice.get()), al_get_bitmap_height(BakerySecondChoice.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 4) al_draw_scaled_bitmap(BakeryFirstchoiceResult.get(), 0, 0, al_get_bitmap_width(BakeryFirstchoiceResult.get()), al_get_bitmap_height(BakeryFirstchoiceResult.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 3) al_draw_scaled_bitmap(BakerySecondchoiceResult.get(), 0, 0, al_get_bitmap_width(BakerySecondchoiceResult.get()), al_get_bitmap_height(BakerySecondchoiceResult.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 5) al_draw_scaled_bitmap(BakeryImpressionLevelReveal.get(), 0, 0, al_get_bitmap_width(BakeryImpressionLevelReveal.get()), al_get_bitmap_height(BakeryImpressionLevelReveal.get()), 0, 0, 1600, 900, 0);
    else if(showTextBox == 6) al_draw_scaled_bitmap(Bakery2narration.get(), 0, 0, al_get_bitmap_width(Bakery2narration.get()), al_get_bitmap_height(Bakery2narration.get()), 0, 0, 1600, 900, 0);
    if(showTextBox == 5){
        if(choiceNumber == 3) {
            al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), halfW - 100, h - 150, 0, "好感度加 1");
        }
        else if(choiceNumber == 4) {
            al_draw_text(WangHanZunFont.get(), al_map_rgb(255, 255, 255), halfW - 100, h - 150, 0, "好感度加 2");
        }
    }
    
}
void Bakery::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void Bakery::OnKeyDown(int keyCode) {
    switch(keyCode){
        case ALLEGRO_KEY_C:
            if(showTextBox == 0) showTextBox = 1;
            else if(showTextBox == 3 || showTextBox == 4) showTextBox = 5;
            else if(showTextBox == 5) showTextBox = 6;
            else if(showTextBox == 6) Engine::GameEngine::GetInstance().ChangeScene("PortNarration");
            break;
        case ALLEGRO_KEY_W:
            if(showTextBox == 2) showTextBox = 1;
            break;
        case ALLEGRO_KEY_S:
            if(showTextBox == 1) showTextBox = 2;
            break;
        case ALLEGRO_KEY_ENTER:
            if(showTextBox == 1) choiceNumber = showTextBox = 3;
            else if(showTextBox == 2) choiceNumber = showTextBox = 4;
            break;
    }
}

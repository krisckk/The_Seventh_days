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
#include "PortNarration.hpp"

void PortNarration::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    PortFirstChoice = Engine::Resources::GetInstance().GetBitmap("Act1/Port/PortNarration/PortFirstChoice.jpg");
    PortSecondChoice = Engine::Resources::GetInstance().GetBitmap("Act1/Port/PortNarration/PortSecondChoice.jpg");
    PortFirstchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act1/Port/PortNarration/PortFirstchoiceResult.jpg");
    PortSecondchoiceResult = Engine::Resources::GetInstance().GetBitmap("Act1/Port/PortNarration/PortSecondchoiceResult.jpg");
}
void PortNarration::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox == 0){
        al_draw_scaled_bitmap(PortFirstChoice.get(), 0, 0, al_get_bitmap_width(PortFirstChoice.get()), al_get_bitmap_height(PortFirstChoice.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 1) {
        al_draw_scaled_bitmap(PortSecondChoice.get(), 0, 0, al_get_bitmap_width(PortSecondChoice.get()), al_get_bitmap_height(PortSecondChoice.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 2) {
        al_draw_scaled_bitmap(PortFirstchoiceResult.get(), 0, 0, al_get_bitmap_width(PortFirstchoiceResult.get()), al_get_bitmap_height(PortFirstchoiceResult.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 3) {
        al_draw_scaled_bitmap(PortSecondchoiceResult.get(), 0, 0, al_get_bitmap_width(PortSecondchoiceResult.get()), al_get_bitmap_height(PortSecondchoiceResult.get()), 0, 0, 1600, 900, 0);
    }
}
void PortNarration::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void PortNarration::Terminate(){
    IScene::Terminate();
}
void PortNarration::OnKeyDown(int keyCode) {
    switch (keyCode)
    {
        case ALLEGRO_KEY_C:
            if(showTextBox == 2 || showTextBox == 3) Engine::GameEngine::GetInstance().ChangeScene("Port");
            break;
        case ALLEGRO_KEY_ENTER:
            if(showTextBox == 0 || showTextBox == 1) showTextBox = showTextBox + 2;
            break;
        case ALLEGRO_KEY_W:
            if(showTextBox == 1) showTextBox = 0;
            break;
        case ALLEGRO_KEY_S:
            if(showTextBox == 0) showTextBox = 1;
            break;
    }
}
void  PortNarration::OnKeyUp(int keyCode) {
}

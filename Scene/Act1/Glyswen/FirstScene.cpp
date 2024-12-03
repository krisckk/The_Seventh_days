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
#include "FirstScene.hpp"
static ALLEGRO_SAMPLE_ID MedievalBGM;
MainCharacter* MC;
void FirstScene::Initialize() {
    Engine::LOG(Engine::INFO) << "First Scene created";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    FirstSceneGIF = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstSceneGIF.jpg");
    FirstScene1narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene1narration.jpg");
    FirstScene2narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene2narration.jpg");
    FirstScene3narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene3narration.jpg");
    FirstScene4narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene4narration.jpg");
    FirstScene5narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene5narration.jpg");
    FirstScene6narration = Engine::Resources::GetInstance().GetBitmap("Act1/Glyswen/FirstScene6narration.jpg");
    MedievalBGM = AudioHelper::PlayBGM("MedievalMusic.ogg");
    Engine::LOG(Engine::INFO) << "First Scene initialized";
    MC = new MainCharacter("Character/MainCharacter/MCidle.png", Engine::Point(800, 300), 200);
    if(!MC){
        Engine::LOG(Engine::ERROR) << "Failed to create Main Character";
        return;
    }
    AddNewObject(MC);
}
void FirstScene::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox == 0) {
        al_draw_scaled_bitmap(FirstSceneGIF.get(), 0, 0, al_get_bitmap_width(FirstSceneGIF.get()), al_get_bitmap_height(FirstSceneGIF.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 1) {
        al_draw_scaled_bitmap(FirstScene1narration.get(), 0, 0, al_get_bitmap_width(FirstScene1narration.get()), al_get_bitmap_height(FirstScene1narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 2) {
        al_draw_scaled_bitmap(FirstScene2narration.get(), 0, 0, al_get_bitmap_width(FirstScene2narration.get()), al_get_bitmap_height(FirstScene2narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 3) {
        al_draw_scaled_bitmap(FirstScene3narration.get(), 0, 0, al_get_bitmap_width(FirstScene3narration.get()), al_get_bitmap_height(FirstScene3narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 4){
        al_draw_scaled_bitmap(FirstScene4narration.get(), 0, 0, al_get_bitmap_width(FirstScene4narration.get()), al_get_bitmap_height(FirstScene4narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 5) {
        al_draw_scaled_bitmap(FirstScene5narration.get(), 0, 0, al_get_bitmap_width(FirstScene5narration.get()), al_get_bitmap_height(FirstScene5narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox == 6) {
        al_draw_scaled_bitmap(FirstScene6narration.get(), 0, 0, al_get_bitmap_width(FirstScene6narration.get()), al_get_bitmap_height(FirstScene6narration.get()), 0, 0, 1600, 900, 0);
    }
}
void FirstScene::Terminate() {
    MC = nullptr;
    AudioHelper::StopBGM(MedievalBGM);
    IScene::Terminate();
}
void FirstScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void FirstScene::OnKeyDown(int keyCode){
    switch (keyCode)
    {
        case ALLEGRO_KEY_C:
            showTextBox++;
            break;
        case ALLEGRO_KEY_A:
            if(showTextBox > 6) MC -> MoveLeft(1.0f / 120.0f); // Assuming 120 fps
            break;
        case ALLEGRO_KEY_D:
            if(showTextBox > 6) MC -> MoveRight(1.0f / 120.0f); // Assuming 120 fps
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
    }
}
void FirstScene::OnKeyUp(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_A:
        case ALLEGRO_KEY_D:
            MC -> Stop();
            break;
    }
}
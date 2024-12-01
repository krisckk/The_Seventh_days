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
#include "FirstScene.hpp"

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
}
void FirstScene::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(showTextBox1) {
        al_draw_scaled_bitmap(FirstSceneGIF.get(), 0, 0, al_get_bitmap_width(FirstSceneGIF.get()), al_get_bitmap_height(FirstSceneGIF.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox2) {
        al_draw_scaled_bitmap(FirstScene1narration.get(), 0, 0, al_get_bitmap_width(FirstScene1narration.get()), al_get_bitmap_height(FirstScene1narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox3) {
        al_draw_scaled_bitmap(FirstScene2narration.get(), 0, 0, al_get_bitmap_width(FirstScene2narration.get()), al_get_bitmap_height(FirstScene2narration.get()), 0, 0, 1600, 900, 0);
    }
    else if(showTextBox4) {
        al_draw_scaled_bitmap(FirstScene3narration.get(), 0, 0, al_get_bitmap_width(FirstScene3narration.get()), al_get_bitmap_height(FirstScene3narration.get()), 0, 0, 1600, 900, 0);
    }
}
void FirstScene::Terminate() {
    IScene::Terminate();
}
void FirstScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
    UpdateTextBox(deltaTime);
}
void FirstScene::UpdateTextBox(float deltaTime) {
    textBoxTimer += deltaTime;
    if(textBoxTimer > 5.0f && textBoxTimer < 9.0f) {
        showTextBox1 = false;
        showTextBox2 = true;
    }
    else if(textBoxTimer >= 9.0f && textBoxTimer < 13.0f){
        showTextBox3 = true;
        showTextBox2 =false;
    }
    else if(textBoxTimer >= 13.0f){
        showTextBox4 = true;
        showTextBox3 = false;
    }
}
void FirstScene::OnKeyDown(int keyCode){

}
void FirstScene::OnKeyUp(int keyCode){

}
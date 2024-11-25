#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/StartScene.hpp"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("MenuBackground.png", 0, 0, 0, 0, 0, 0));
    AddNewObject(new Engine::Label("The 7 Days", "pirulen.ttf", 48, halfW / 2 - 260, halfH / 2 + 20 , 255, 255, 255, 255, 0, 0.5));

}
void StartScene::Terminate() {
    IScene::Terminate();
}
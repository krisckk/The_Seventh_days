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
static ALLEGRO_SAMPLE_ID BGM;
void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("StartScene/MenuBackground.png", 0, 0, 1600, 900, 0, 0));
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("StartScene/NewGameButton.png", "StartScene/NewGameButtonHovered.png", 108, 400, 360, 80, 0, 0);
    btn -> SetOnClickCallback(std::bind(&StartScene::NewGameOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("StartScene/ContinueButton.png", "StartScene/ContinueButtonHovered.png", 115, 500, 360, 80, 0, 0);
    btn -> SetOnClickCallback(std::bind(&StartScene::ContinueOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("StartScene/SettingsButton.png", "StartScene/SettingsButtonHovered.png", 108, 600, 360, 80, 0, 0);
    btn -> SetOnClickCallback(std::bind(&StartScene::SettingsOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("StartScene/AchievementButton.png", "StartScene/AchievementButtonHovered.png", 122, 700, 360, 80, 0, 0);
    btn -> SetOnClickCallback(std::bind(&StartScene::AchievementOnClick, this, 1));
    AddNewControlObject(btn);
    BGM = AudioHelper::PlayBGM("BeginningReadyFotlt.ogg");
}
void StartScene::Terminate() {
    AudioHelper::StopBGM(BGM);
    IScene::Terminate();
}
void StartScene::NewGameOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("FirstScene");
}
void StartScene::SettingsOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("Settings");
}
void StartScene::AchievementOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("achievement");
}
void StartScene::ContinueOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage" + std::to_string(stage));
}
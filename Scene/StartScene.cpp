#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <sqlite3.h>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/StartScene.hpp"
#include "Shared/Global.hpp"
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
    Engine::GameEngine::GetInstance().ChangeScene("MushroomFarm");
}
void StartScene::ContinueOnClick(int stage) {
    std::ifstream checkFile("the7days_saves.db");
    if (!checkFile.good()) {
        Engine::LOG(Engine::INFO) << "No save file found";
        return;
    }
    checkFile.close();
    sqlite3* db;
    sqlite3_stmt* stmt;

    // Open database
    int rc = sqlite3_open("the7days_saves.db", &db);
    if(rc) {
        Engine::LOG(Engine::ERROR) << "Can't open database: " << sqlite3_errmsg(db);
        return;
    }
    // Get most recent save
    const char * query = "SELECT scene_name, emerald_collected, impression_level "
                            "FROM saves ORDER BY id DESC LIMIT 1";
    if(sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        if(sqlite3_step(stmt) == SQLITE_ROW) {
            std::string sceneName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            Global::emeraldCollected = sqlite3_column_int(stmt, 1);
            Global::impressionLevel = sqlite3_column_int(stmt, 2);
            Engine::LOG(Engine::INFO) << "Game loaded successfully";
            
            Engine::GameEngine::GetInstance().ChangeScene(sceneName);
        }
        else {
            Engine::LOG(Engine::ERROR) << "No saved game in database";
        }
    }
    else {
        Engine::LOG(Engine::ERROR) << "Nothing found" ;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
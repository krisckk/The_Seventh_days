#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <thread>
#include <sqlite3.h>
#include <string>
#include <sstream>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Shared/Global.hpp"
#include "PauseScene.hpp"
#include "Engine/Resources.hpp" // Add this line to include the Resources header

void PauseScene::Initialize() {
    Engine::LOG(Engine::INFO) << "Pause Scene Initialized";
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Save = Engine::Resources::GetInstance().GetBitmap("Pause/Save.png");
    Back = Engine::Resources::GetInstance().GetBitmap("Pause/Back.png");
    testFont = Engine::Resources::GetInstance().GetFont("JetBrainsMono.ttf", 24);
    isSave = true;
    isBack = false;
    Engine::LOG(Engine::INFO) << "Pause Scene Created";
}
void PauseScene::Terminate(){
    IScene::Terminate();
}
void PauseScene::Draw() const {
    IScene::Draw();
    if(isSave) al_draw_scaled_bitmap(Save.get(), 0, 0, al_get_bitmap_width(Save.get()), al_get_bitmap_height(Save.get()), 0, 0, 1600, 900, 0);
    if(isBack) al_draw_scaled_bitmap(Back.get(), 0, 0, al_get_bitmap_width(Back.get()), al_get_bitmap_height(Back.get()), 0, 0, 1600, 900, 0);
    al_draw_text(testFont.get(), al_map_rgb(255, 255, 255), 800, 800, ALLEGRO_ALIGN_CENTER, "Press W/S to choose, Press Enter to continue");
}
void PauseScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
}
void PauseScene::OnKeyDown(int keyCode) {
    switch (keyCode) {
        case ALLEGRO_KEY_W:
            isSave = true;
            isBack = false;
            break;
        case ALLEGRO_KEY_S:
            isSave = false;
            isBack = true;
            break;
        case ALLEGRO_KEY_ENTER:
            auto lastScene =Global::previousScene;
            if(isSave) {
                // use a SQLite database to save the game
                // save the current game file to the data base, and resserved some space for othere data
                SaveGameToDatabase();
                Engine::GameEngine::GetInstance().ChangeScene("StartScene");
            }
            else if (isBack) Engine::GameEngine::GetInstance().ChangeScene(lastScene);
            
    }
}
void PauseScene::SaveGameToDatabase() {
    sqlite3* db;
    char *errMsg = 0;
    
    // Open/Create database
    int rc = sqlite3_open("the7days_saves.db", &db);

    if(rc) {
        Engine::LOG(Engine::ERROR) << "Can't open database: " << sqlite3_errmsg(db);
        return;
    }
    // Create saves table if not exists
    const char* createTable = "CREATE TABLE IF NOT EXISTS saves ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "scene_name TEXT NOT NULL,"
                            "emerald_collected INTEGER,"
                            "impression_level INTEGER)"; // "save_date DATETIME DEFAULT CURRENT_TIMESTAMP);"
    rc = sqlite3_exec(db, createTable, 0, 0, &errMsg);

    if(rc != SQLITE_OK) {
        Engine::LOG(Engine::ERROR) << "SQL error: " << errMsg;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return;
    }

    // Prepare save data
    std::stringstream saveQuery;
    saveQuery  << "INSERT INTO saves (scene_name, emerald_collected, impression_level) VALUES ('"
               << Global::previousScene << "', "
               << (Global::emeraldCollected ? 1 : 0) << ", "
               << Global::impressionLevel << ")";
    // Execute save
    rc = sqlite3_exec(db, saveQuery.str().c_str(), 0, 0, &errMsg);

    if(rc != SQLITE_OK) {
        Engine::LOG(Engine::ERROR) << "SQL error: " << errMsg;
        sqlite3_free(errMsg);
    }
    else Engine::LOG(Engine::INFO) << "Save successful!";
    sqlite3_close(db);
}



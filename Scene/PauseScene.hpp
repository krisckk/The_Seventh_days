#ifndef PAUSESCENE_HPP
#define PAUSESCENE_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <memory>
#include "Engine/IScene.hpp"

class PauseScene final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_BITMAP> Save;
        std::shared_ptr<ALLEGRO_BITMAP> Back;
        bool isSave;
        bool isBack;
        std::shared_ptr<ALLEGRO_FONT> testFont;
    public:
        explicit PauseScene() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void SaveGameToDatabase();
        std::string GetName() const override {return "PauseScene"; };
};

#endif
#ifndef MUSHROOMFARM_HPP
#define MUSHROOMFARM_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"

extern MainCharacter* MC;

class MushroomFarm final : public Engine::IScene {
    private:
        std::shared_ptr <ALLEGRO_BITMAP> MushroomFarmBackground;
        std::shared_ptr <ALLEGRO_BITMAP> RedMushroom1;
        std::shared_ptr <ALLEGRO_BITMAP> RedMushroom2;
        std::shared_ptr <ALLEGRO_BITMAP> WhiteMushroom1;
        std::shared_ptr <ALLEGRO_BITMAP> WhiteMushroom2;
        std::shared_ptr <ALLEGRO_FONT> WangHanZunFont;
        bool Redmushroom1Get;
        bool Redmushroom2Get;
        bool Whitemushroom1Get;
        bool Whitemushroom2Get;
    public:
        explicit MushroomFarm() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "MushroomFarm"; };
};

#endif

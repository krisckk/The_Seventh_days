#ifndef MAP_HPP
#define MAP_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Map final : public Engine::IScene {
    public:
        explicit Map() = default;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void TownOnclick(int stage);
        void PortOnClick(int stage);
        void MushroomFarmOnClick(int stage);
        void HideawayOnClick(int stage);
        void LaboratoryOnClick(int stage);
        std::string GetName() const override {return "Map"; };
};

#endif
#ifndef VILLAGETOBACKERY_HPP
#define VILLAGETOBACKERY_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <Engine/IScene.hpp>
#include "Character/Althea.hpp"
extern Althea* _Althea;
class VillageToBackery final : public Engine::IScene {
    private:
        std::shared_ptr <ALLEGRO_BITMAP> VillageToBackeryImage;
        std::shared_ptr <ALLEGRO_FONT> WangHanZunFont;
    public:
        VillageToBackery() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "VillageToBackery"; }
};
#endif
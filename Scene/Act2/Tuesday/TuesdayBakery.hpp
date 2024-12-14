#ifndef TUESDAYBAKERY_HPP
#define TUESDAYBAKERY_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"
extern MainCharacter* MC;

class TuesdayBakery final : public Engine::IScene {
    private:
        std::shared_ptr <ALLEGRO_BITMAP> TuesdayBakeryBackground;
        std::shared_ptr <ALLEGRO_BITMAP> Notebook;
        bool NotebookGet;
    public:
        explicit TuesdayBakery() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "TuesdayBakery"; };
};

#endif
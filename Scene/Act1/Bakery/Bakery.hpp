#ifndef BAKERY_HPP
#define BAKERY_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"
extern MainCharacter* MC;
class Bakery final : public Engine::IScene {
    private:
        int showTextBox = 0;
        int choiceNumber;
        std::shared_ptr<ALLEGRO_FONT> WangHanZunFont;
        std::shared_ptr<ALLEGRO_BITMAP> Bakery1narration;
        std::shared_ptr<ALLEGRO_BITMAP> Bakery2narration;
        std::shared_ptr<ALLEGRO_BITMAP> BakeryFirstChoice;
        std::shared_ptr<ALLEGRO_BITMAP> BakerySecondChoice;
        std::shared_ptr<ALLEGRO_BITMAP> BakeryFirstchoiceResult;
        std::shared_ptr<ALLEGRO_BITMAP> BakerySecondchoiceResult;
        std::shared_ptr<ALLEGRO_BITMAP> BakeryImpressionLevelReveal;
    public:
        Bakery() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        std::string GetName() const override { return "Backery"; }
};
#endif

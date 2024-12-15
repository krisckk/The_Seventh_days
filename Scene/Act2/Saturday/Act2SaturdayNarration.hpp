#ifndef ACT2SATURDAYNARRATION_HPP
#define ACT2SATURDAYNARRATION_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Act2SaturdayNarration final : public Engine::IScene{
    private:
        int showTextbox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr<ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr<ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr<ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr<ALLEGRO_BITMAP> FifthImage;
    public:
        explicit Act2SaturdayNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        std::string GetName() const override { return "Act2SaturdayNarration"; }
};

#endif
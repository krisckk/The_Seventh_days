#ifndef ACT2TUESDAYSECONDNARRATION_HPP
#define ACT2TUESDAYSECONDNARRATION_HPP
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Act2TuesdaySecondNarration final : public Engine::IScene{
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr <ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr <ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr <ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr <ALLEGRO_BITMAP> FifthImage;
        std::shared_ptr <ALLEGRO_BITMAP> SixthImage;
        std::shared_ptr <ALLEGRO_BITMAP> FirstChoice;
        std::shared_ptr <ALLEGRO_BITMAP> SecondChoice;
        std::shared_ptr <ALLEGRO_BITMAP> GroupPhoto;
        std::shared_ptr <ALLEGRO_BITMAP> LastImage;
    public:
        explicit Act2TuesdaySecondNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "Act2TuesdaySecondNarration"; }
};
#endif
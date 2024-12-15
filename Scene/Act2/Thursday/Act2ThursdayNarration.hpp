#ifndef ACT2THURSDAYNARRATION_HPP
#define ACT2THURSDAYNARRATION_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Act2ThursdayNarration final : public Engine::IScene {
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr <ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr <ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr <ALLEGRO_BITMAP> FirstchoiceResult;
        std::shared_ptr <ALLEGRO_BITMAP> SecondchoiceResult;
        std::shared_ptr <ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr <ALLEGRO_BITMAP> FifthImage;
        std::shared_ptr <ALLEGRO_BITMAP> SixthImage;
    public:
        explicit Act2ThursdayNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "Act2ThursdayNarration"; }
};

#endif
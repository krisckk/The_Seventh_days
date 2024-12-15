#ifndef ACT2WEDNESDAYNARRATION_HPP
#define ACT2WEDNESDAYNARRATION_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Act2WednesdayNarration final : public Engine::IScene{
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr <ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr <ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr <ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr <ALLEGRO_BITMAP> FifthImage;
        std::shared_ptr <ALLEGRO_BITMAP> SixthImage;
        std::shared_ptr <ALLEGRO_BITMAP> SeventhImage;
        std::shared_ptr <ALLEGRO_BITMAP> EighthImage;
        std::shared_ptr <ALLEGRO_BITMAP> NinethImage;
        std::shared_ptr <ALLEGRO_BITMAP> TenthImage;
        std::shared_ptr <ALLEGRO_BITMAP> EleventhImage;
        std::shared_ptr <ALLEGRO_BITMAP> Ending3FirstImage;
        std::shared_ptr <ALLEGRO_BITMAP> Ending3SecondImage;
        std::shared_ptr <ALLEGRO_BITMAP> Ending3ThirdImage;
        std::shared_ptr <ALLEGRO_BITMAP> Ending3FourthImage;
        std::shared_ptr <ALLEGRO_BITMAP> Ending3FifthImage;
    public:
        explicit Act2WednesdayNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "Act2WednesdayNarration"; }
};

#endif
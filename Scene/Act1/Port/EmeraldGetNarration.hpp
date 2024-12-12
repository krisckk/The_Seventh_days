#ifndef EMERALDGETNARRATION_HPP
#define EMERALDGETNARRATION_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class EmeraldGetNarration final : public Engine::IScene {
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr <ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr <ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr <ALLEGRO_BITMAP> FourthImage;
    public:
        explicit EmeraldGetNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "EmeraldGetNarration"; }
};


#endif
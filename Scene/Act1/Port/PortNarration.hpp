#ifndef PORTNARRATION_HPP
#define PORTNARRATION_HPP
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class PortNarration final : public Engine::IScene {
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> PortFirstChoice;
        std::shared_ptr <ALLEGRO_BITMAP> PortSecondChoice;
        std::shared_ptr <ALLEGRO_BITMAP> PortFirstchoiceResult;
        std::shared_ptr <ALLEGRO_BITMAP> PortSecondchoiceResult;
    public:
        explicit PortNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "PortNarration"; }
};


#endif
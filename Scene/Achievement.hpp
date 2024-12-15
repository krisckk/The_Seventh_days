#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Achievement final : public Engine::IScene {
    private:
        int showTextbox = 0;
        std::shared_ptr <ALLEGRO_FONT> JetBrinsMono;
        std::shared_ptr<ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr<ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr<ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr<ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr<ALLEGRO_BITMAP> FifthImage;
        std::shared_ptr<ALLEGRO_BITMAP> SixthImage;
    public:
        explicit Achievement() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        std::string GetName() const override { return "Achievement"; }
};

#endif

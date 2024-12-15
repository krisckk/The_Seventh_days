#ifndef ENDING_HPP
#define ENDING_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class Ending final : public Engine::IScene {
    private:
        int showTextbox = 0;
        std::shared_ptr<ALLEGRO_BITMAP> FirstImage;
        std::shared_ptr<ALLEGRO_BITMAP> SecondImage;
        std::shared_ptr<ALLEGRO_BITMAP> ThirdImage;
        std::shared_ptr<ALLEGRO_BITMAP> FourthImage;
        std::shared_ptr<ALLEGRO_BITMAP> FifthImage;
        std::shared_ptr<ALLEGRO_BITMAP> SixthImage;
        std::shared_ptr<ALLEGRO_BITMAP> SeventhImage;
        std::shared_ptr<ALLEGRO_BITMAP> EighthImage;
    public:
        explicit Ending() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        std::string GetName() const override { return "Ending"; }
};

#endif
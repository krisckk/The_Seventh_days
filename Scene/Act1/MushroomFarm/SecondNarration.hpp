#ifndef SECONDNARRATION_HPP
#define SECONDNARRATION_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class MushroomFarmSecondNarration final : public Engine::IScene {
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> MFSixthNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFSeventhNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFEighthNarration;
    public:
        explicit MushroomFarmSecondNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void Draw() const override;
        std::string GetName() const override { return "MushroomFarmSecondNarration"; }
};

#endif
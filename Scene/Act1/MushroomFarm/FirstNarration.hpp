#ifndef FIRSTNARRATION_HPP
#define FIRSTNARRATION_HPP


#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>

class MushroomFarmFirstNarration final : public Engine::IScene {
    private:
        int showTextBox = 0;
        std::shared_ptr <ALLEGRO_BITMAP> MFFirstNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFSecondNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFThirdNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFFourthNarration;
        std::shared_ptr <ALLEGRO_BITMAP> MFFifthNarration;
    public:
        explicit MushroomFarmFirstNarration() = default;
        void Initialize() override;
        void Terminate() override;
        void Update(float deltaTime) override;
        void Draw() const override;
        std::string GetName() const override { return "MushroomFarmFirstNarration"; }
};

#endif
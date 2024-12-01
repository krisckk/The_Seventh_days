#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Settings final : public Engine::IScene {
    public:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> BGMInstance;
        explicit Settings() = default;
        void Initialize() override;
        void Terminate() override;
        void BackOnClick(int Stage);
        void BGMSliderOnValueChanged(float value);
        void SFXSliderOnValueChanged(float value);
        std::string GetName() const override {return "Settings"; };
};

#endif
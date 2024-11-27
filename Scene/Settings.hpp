#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"
using namespace std;
class Settings final : public Engine::IScene {
    private:
        shared_ptr<ALLEGRO_SAMPLE_INSTANCE> sfxInstance;
        shared_ptr<ALLEGRO_SAMPLE> backgroundBGM;
    public:
        explicit Settings() = default;
        void Initialize() override;
        void Terminate() override;
        void BackOnClick(int Stage);
        void BGMSliderOnValueChanged(float value);
        void SFXSliderOnValueChanged(float value);
        string GetName() const override {return "Settings"; };
};

#endif
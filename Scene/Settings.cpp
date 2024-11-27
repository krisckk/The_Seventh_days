#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Settings.hpp"

void Settings::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    AddNewObject(new Engine::Image("SettingsBackground.png", 0, 0, 1600, 900, 0, 0));
    AddNewObject(new Engine::Label("Settings", "JetBrainsMono.ttf", 56, halfW / 2 - 210, halfH / 2 + 2, 255, 255, 255, 0, 0.5));
    Engine::ImageButton *btn;
    Slider *BGMslider, *SFXslider;
    BGMslider = new Slider(40 + halfW - 130, halfH - 50 - 2, 190, 4);
    BGMslider -> SetOnValueChangedCallback(std::bind(&Settings::BGMSliderOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(BGMslider);
    AddNewObject(
        new Engine::Label("BGM: ", "NimbusSansCHS.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 0, 0, 0.5, 0.5));
    SFXslider = new Slider(40 + halfW - 130, halfH + 50 - 2, 190, 4);
    SFXslider -> SetOnValueChangedCallback(std::bind(&Settings::SFXSliderOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(SFXslider);
    AddNewObject(
        new Engine::Label("SFX: ", "JetBrainsMono.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("BackButton.png", "BackButtonHovered.png", 650, 600, 300, 80, 0, 0);
    btn -> SetOnClickCallback(std::bind(&Settings::BackOnClick, this, 1));
    AddNewControlObject(btn);
}
void Settings::Terminate() {
    IScene::Terminate();
    AudioHelper::StopSample(sfxInstance);
}
void Settings::BackOnClick(int Stage){
    Engine::GameEngine::GetInstance().ChangeScene("StartScene");
}
void Settings::BGMSliderOnValueChanged(float value){
    AudioHelper::BGMVolume = value;
}
void Settings::SFXSliderOnValueChanged(float value){
    AudioHelper::SFXVolume = value;
    sfxInstance = AudioHelper::PlaySample("laser.wav", false, AudioHelper::SFXVolume);
}
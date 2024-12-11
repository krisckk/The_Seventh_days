#ifndef PORT_HPP
#define PORT_HPP
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"
#include "Character/Adrian.hpp"
extern MainCharacter* MC;
extern Adrian* _Adrian;
class Port final : public Engine::IScene {
    private:
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox1;
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox2;
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox3;
        std::shared_ptr <ALLEGRO_BITMAP> Emerald;
        std::shared_ptr <ALLEGRO_FONT> WangHanZunFont;
        bool showTextBox;
        float textBoxTimer = 0.0f;
        bool Epressed = false;
    public:
        Port() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void UpdateTextBox(float deltaTime);
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "Port"; };
};

#endif
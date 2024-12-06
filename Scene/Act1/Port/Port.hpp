#ifndef PORT_HPP
#define PORT_HPP
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"
extern MainCharacter* MC;
class Port final : public Engine::IScene {
    private:
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox1;
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox2;
        std::shared_ptr <ALLEGRO_BITMAP> WoodenBox3;
        std::shared_ptr <ALLEGRO_FONT> WangHanZunFont;
    public:
        Port() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "Port"; };
};

#endif
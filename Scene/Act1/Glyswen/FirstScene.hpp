#ifndef FIRSTSCENE_HPP
#define FIRSTSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>
#include "Character/MainCharacter.hpp"
extern MainCharacter* MC;
class FirstScene final : public Engine::IScene {
    private:
        int showTextBox = 0;
        float textBoxTimer = 0.0f;
        std::shared_ptr <ALLEGRO_BITMAP> FirstSceneGIF;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene1narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene2narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene3narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene4narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene5narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene6narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene7narration;
    public:
        FirstScene() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "FirstScene"; }
};
#endif
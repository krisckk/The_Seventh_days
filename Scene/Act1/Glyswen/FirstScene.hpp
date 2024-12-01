#ifndef FIRSTSCENE_HPP
#define FIRSTSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_video.h>
#include <Engine/IScene.hpp>
namespace Engine{
    class Group;
    class Image;
    class Label;
    class Sprite;
}
class FirstScene final : public Engine::IScene {
    private:
        bool showTextBox1 = true;
        bool showTextBox2 = false;
        bool showTextBox3 = false;
        bool showTextBox4 = false;
        float textBoxTimer = 0.0f;
        std::shared_ptr <ALLEGRO_BITMAP> FirstSceneGIF;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene1narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene2narration;
        std::shared_ptr <ALLEGRO_BITMAP> FirstScene3narration;
    public:
        FirstScene() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void Update(float deltaTime) override;
        void UpdateTextBox(float deltaTime);
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "FirstScene"; }
};
#endif
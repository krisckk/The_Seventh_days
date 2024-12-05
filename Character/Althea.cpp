#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "MainCharacter.hpp"

#include <Engine/AudioHelper.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/Group.hpp>
#include <Engine/IScene.hpp>
#include <Engine/LOG.hpp>
#include "Althea.hpp"

Althea::Althea(std::string img, Engine::Point position, float speed) :
    Engine::Sprite(img, position.x, position.y), speed(speed),
    idleAnimation({al_load_bitmap("Resource/images/Character/Althea/AltheaIdle.png")}, 0.2f),
    LeftidleAnimation({al_load_bitmap("Resource/images/Character/Althea/AltheaLeftIdle.png")}, 0.2f),
    RightidleAnimation({al_load_bitmap("Resource/images/Character/Althea/AltheaRightIdle.png")}, 0.2f),
    currentAnimation(&idleAnimation) {
        ALLEGRO_BITMAP* idleFrame = al_load_bitmap("Resource/images/Character/Althea/AltheaIdle.png");
        ALLEGRO_BITMAP* LeftidleFrame = al_load_bitmap("Resource/images/Character/Althea/AltheaLeftIdle.png");
        ALLEGRO_BITMAP* RightidleFrame = al_load_bitmap("Resource/images/Character/Althea/AltheaRightIdle.png");
        if(!idleFrame || !LeftidleFrame || !RightidleFrame){
            Engine::LOG(Engine::ERROR) << "Failed to load idle animation frames";
            return;
        }

        idleAnimation = Animation({idleFrame}, 0.2f);
        LeftidleAnimation = Animation({LeftidleFrame}, 0.2f);
        RightidleAnimation = Animation({RightidleFrame}, 0.2f);
        currentAnimation = &idleAnimation;
        bmp = std::shared_ptr<ALLEGRO_BITMAP>(al_load_bitmap(img.c_str()), al_destroy_bitmap);
        al_draw_filled_rectangle(200, 800, 1400, 880, al_map_rgb(255, 255, 255));
}

void Althea::Update(float deltaTime) {
    if (Position.x < 0) Position.x = 0;
    if (Position.x > 1600) Position.x = 1600;
    float newX = Position.x + Velocity.x * deltaTime;
    float newY = Position.y + Velocity.y * deltaTime;
    // Update Position
    Position.x = newX;
    Position.y = newY;
    Sprite::Update(deltaTime);
    currentAnimation -> Update(deltaTime);
}
void Althea::Draw() const {
    currentAnimation -> Draw(Position.x, Position.y, 1.5f, Rotation);
}
void Althea::Stop() {
    Velocity.x = 0;
    Velocity.y = 0;
    Rotation = 0;
    currentAnimation = &idleAnimation;
}
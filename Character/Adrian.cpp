#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "MainCharacter.hpp"

#include <Engine/AudioHelper.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/Group.hpp>
#include <Engine/IScene.hpp>
#include <Engine/LOG.hpp>
#include "Adrian.hpp"

Adrian::Adrian(std::string img, Engine::Point position, float _speed) :
    Engine::Sprite(img, position.x, position.y), speed(_speed),
    idleAnimation({al_load_bitmap("Resource/images/Character/Adrian/Adrianidle.png")}, 0.2f),
    LeftwalkAnimation({al_load_bitmap("Resource/images/Character/Adrian/AdrianLeftwalkL.png"), al_load_bitmap("Resource/images/Character/Adrian/AdrianLeftwalkR.png")}, 0.2f),
    RightwalkAnimation({al_load_bitmap("Resource/images/Character/Adrian/AdrianRightwalkL.png"), al_load_bitmap("Resource/images/Character/Adrian/AdrianRightwalkR.png")}, 0.2f),
    currentAnimation(&idleAnimation) {
        ALLEGRO_BITMAP* idleFrame = al_load_bitmap("Resource/images/Character/Adrian/Adrianidle.png");
        ALLEGRO_BITMAP* LeftwalkFrameL = al_load_bitmap("Resource/images/Character/Adrian/AdrianLeftwalkL.png");
        ALLEGRO_BITMAP* LeftwalkFrameR = al_load_bitmap("Resource/images/Character/Adrian/AdrianLeftwalkR.png");
        ALLEGRO_BITMAP* RightwalkFrameL = al_load_bitmap("Resource/images/Character/Adrian/AdrianRightwalkL.png");
        ALLEGRO_BITMAP* RightwalkFrameR = al_load_bitmap("Resource/images/Character/Adrian/AdrianRightwalkR.png");
        if(!idleFrame || !LeftwalkFrameL || !LeftwalkFrameR || !RightwalkFrameL || !RightwalkFrameR){
            Engine::LOG(Engine::ERROR) << "Failed to load animation frames";
            return;
        }
        idleAnimation = Animation({idleFrame}, 0.2f);
        LeftwalkAnimation = Animation({LeftwalkFrameL, LeftwalkFrameR}, 0.2f);
        RightwalkAnimation = Animation({RightwalkFrameL, RightwalkFrameR}, 0.2f);
        currentAnimation = &idleAnimation;
        bmp = std::shared_ptr<ALLEGRO_BITMAP>(al_load_bitmap(img.c_str()), al_destroy_bitmap);
        al_draw_filled_rectangle(200, 800, 1400, 880, al_map_rgb(255, 255, 255));
    }
void Adrian::Update(float deltaTime) {
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
void Adrian::Draw() const {
    currentAnimation -> Draw(Position.x, Position.y, 1.5f, Rotation);
}
void Adrian::MoveLeft(float deltaTime){
    if(Position.x > 0){
        Velocity.x = -speed;
        Rotation = 0;
        currentAnimation = &LeftwalkAnimation;
    }
}
void Adrian::MoveRight(float deltaTime){
    if(Position.x < 1580){
        Velocity.x = speed;
        Rotation = 0;
        currentAnimation = &RightwalkAnimation;
    }
}
void Adrian::Stop(){
    Velocity.x = 0;
    Velocity.y = 0;
    Rotation = 0;
    currentAnimation = &idleAnimation;
}
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "MainCharacter.hpp"

#include <Engine/AudioHelper.hpp>
#include <Engine/GameEngine.hpp>
#include <Engine/Group.hpp>
#include <Engine/IScene.hpp>
#include <Engine/LOG.hpp>
#include "MainCharacter.hpp"

MainCharacter::MainCharacter(std::string img, Engine::Point position, float _speed) :
    Engine::Sprite(img, position.x, position.y), speed(_speed),
    idleAnimation({al_load_bitmap("Resource/images/Character/MainCharacter/MCidle.png")}, 0.2f),
    LeftwalkAnimation({al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkLeftL.png"), al_load_bitmap("Resource/images/Character/MCwalkLeftR.png")}, 0.2f),
    RightwalkAnimation({al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkRightL.png"), al_load_bitmap("Resource/images/Character/MCwalkRightR.png")}, 0.2f),
    UpwalkAnimation({al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkUpL.png"), al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkUpR.png")}, 0.2f),
    DownwalkAnimation({al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkDownL.png"), al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkDownR.png")}, 0.2f),
    currentAnimation(&idleAnimation) {
        ALLEGRO_BITMAP* idleFrame = al_load_bitmap("Resource/images/Character/MainCharacter/MCidle.png");
        if(!idleFrame){
            Engine::LOG(Engine::ERROR) << "Failed to load idle animation frames";
            return;
        }
        ALLEGRO_BITMAP* LeftwalkFrameL = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkLeftL.png");
        ALLEGRO_BITMAP* LeftwalkFrameR = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkLeftR.png");
        ALLEGRO_BITMAP* RightwalkFrameL = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkRightL.png");
        ALLEGRO_BITMAP* RightwalkFrameR = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkRightR.png");
        ALLEGRO_BITMAP* UpwalkFrameL = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkUpL.png");
        ALLEGRO_BITMAP* UpwalkFrameR = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkUpR.png");
        ALLEGRO_BITMAP* DownwalkFrameL = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkDownL.png");
        ALLEGRO_BITMAP* DownwalkFrameR = al_load_bitmap("Resource/images/Character/MainCharacter/MCwalkDownR.png");
        if(!LeftwalkFrameL || !LeftwalkFrameR || !RightwalkFrameL || !RightwalkFrameR || !UpwalkFrameL || !UpwalkFrameR || !DownwalkFrameL || !DownwalkFrameR){
            Engine::LOG(Engine::ERROR) << "Failed to load walk animation frames";
            return;
        }

        idleAnimation = Animation({idleFrame}, 0.2f);
        LeftwalkAnimation = Animation({LeftwalkFrameL, LeftwalkFrameR}, 0.2f);
        RightwalkAnimation = Animation({RightwalkFrameL, RightwalkFrameR}, 0.2f);
        UpwalkAnimation = Animation({UpwalkFrameL, UpwalkFrameR}, 0.2f);
        DownwalkAnimation = Animation({DownwalkFrameL, DownwalkFrameR}, 0.2f);
        currentAnimation = &idleAnimation;
        bmp = std::shared_ptr<ALLEGRO_BITMAP>(al_load_bitmap(img.c_str()), al_destroy_bitmap);
        al_draw_filled_rectangle(200, 800, 1400, 880, al_map_rgb(255, 255, 255));
}

void MainCharacter::Update(float deltaTime) {
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
void MainCharacter::Draw() const {
    currentAnimation -> Draw(Position.x, Position.y, 1.5f, Rotation);
}
void MainCharacter::MoveLeft(float deltaTime) {
    if(Position.x > 0){
        Velocity.x = -speed;
        Rotation = 0;
        currentAnimation = &LeftwalkAnimation;
    }
}
void MainCharacter::MoveRight(float deltaTime) {
    if(Position.x < 1580){
        Velocity.x = speed;
        Rotation = 0;
        currentAnimation = &RightwalkAnimation;
    }
}
void MainCharacter::MoveUp(float deltaTime) {
    if(Position.y > 0){
        Velocity.y = -speed;
        Rotation = 90;
        currentAnimation = &UpwalkAnimation;
    }
}
void MainCharacter::MoveDown(float deltaTime) {
    if(Position.y < 880){
        Velocity.y = speed;
        Rotation = 270;
        currentAnimation = &DownwalkAnimation;
    }
}
void MainCharacter::Stop() {
    Velocity.x = 0;
    Velocity.y = 0;
    Rotation = 0;
    currentAnimation = &idleAnimation;
}
#ifndef ADRIAN_HPP
#define ADRIAN_HPP
#include <allegro5/allegro.h>
#include <string>
#include <vector>

#include "Animation.hpp"
#include <Engine/Point.hpp>
#include <Engine/Sprite.hpp>

class Adrian : public Engine::Sprite {
    protected:
        float speed;
        Animation idleAnimation;
        Animation LeftwalkAnimation;
        Animation RightwalkAnimation;
        Animation* currentAnimation;
    public:
        Adrian(std::string img, Engine::Point position, float speed);
        void Update(float deltaTime) override;
        void Draw() const override;
        void MoveLeft(float deltaTime);
        void MoveRight(float deltaTime);
        void Stop();
};

#endif
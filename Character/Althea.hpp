#ifndef ALTHEA_HPP
#define ALTHEA_HPP

#include <allegro5/allegro.h>
#include <string>
#include <vector>

#include "Animation.hpp"
#include <Engine/Point.hpp>
#include <Engine/Sprite.hpp>

class Althea : public Engine::Sprite {
    protected:
        float speed;
        Animation idleAnimation;
        Animation LeftidleAnimation;
        Animation RightidleAnimation;
        Animation* currentAnimation;
    public:
    Althea(std::string img, Engine::Point position, float speed);
    void Update(float deltaTime) override;
    void Draw() const override;
    void Stop();
};

#endif
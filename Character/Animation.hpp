#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <allegro5/allegro.h>

class Animation {
    private:
        std::vector<ALLEGRO_BITMAP*> frames;
        float frameDuration;
        float currentFrameTime;
        int currentFrame;
    public:
        Animation(std::vector<ALLEGRO_BITMAP*> frames, float frameDuration);
        void Update(float deltaTime);
        void Draw(float x, float y, float scale = 1.0f, float rotation = 0.0f) const;
        ALLEGRO_BITMAP* getFrame();
};

#endif
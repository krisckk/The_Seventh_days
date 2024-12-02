#include "Animation.hpp"
#include <allegro5/allegro_image.h>

Animation::Animation(std::vector<ALLEGRO_BITMAP*> _frames, float _frameDuration) : frames(_frames), frameDuration(_frameDuration), currentFrameTime(0), currentFrame(0) {}

void Animation::Update(float deltaTime) {
    currentFrameTime += deltaTime;
    if (currentFrameTime >= frameDuration){
        currentFrameTime = 0.0f;
        currentFrame = (currentFrame + 1) % frames.size();
    }
}

void Animation::Draw(float x, float y, float scale, float rotation) const {
    al_draw_tinted_scaled_rotated_bitmap(frames[currentFrame], al_map_rgba_f(1.0f, 1.0f, 1.0f, 1.0f),
                                         0, 0, x, y, scale, scale, rotation, 0);
}

ALLEGRO_BITMAP* Animation::getFrame(){
    return frames[currentFrame];
}
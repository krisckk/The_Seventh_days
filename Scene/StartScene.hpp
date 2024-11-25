///
/// Created by Kris on 2024/11/25
///

#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class StartScene final : public Engine::IScene {
    private:
    public:
        explicit StartScene() = default;
        void Initialize() override;
        void Terminate() override;
        std::string GetName() const override { return "StartScene"; }
};


#endif

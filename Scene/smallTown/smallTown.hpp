///
/// Created by Kris on 2024/11/25
///

#ifndef SMALLTOWN_HPP
#define SMALLTOWN_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class smallTown final : public Engine::IScene {
    private:
    public:
        explicit smallTown() = default;
        void Initialize() override;
        void Terminate() override;
        std::string GetName() const override { return "smallTown"; }
};

#endif
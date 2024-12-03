#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <Engine/IScene.hpp>
#include <Engine/Point.hpp>

class Backpack final : public Engine::IScene {
    private:
    public:
        explicit Backpack() = default;
        void Draw() const override;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        std::string GetName() const override {return "Backpack";};
};


#endif
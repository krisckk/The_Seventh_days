// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/LOG.hpp"
#include "Character/Backpack.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/Settings.hpp"
#include "Scene/Act1/Glyswen/FirstScene.hpp"
#include "Scene/Act1/Glyswen/VillageToBackery.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("StartScene", new StartScene());
	game.AddNewScene("Settings", new Settings());
	game.AddNewScene("Backpack", new Backpack());
	// Glyswen
	game.AddNewScene("FirstScene", new FirstScene());
	game.AddNewScene("VillageToBackery", new VillageToBackery());

	game.Start("StartScene", 120, 1600, 900);
	game.Start("Settings", 120, 1600, 900);
	game.Start("Backpack", 120, 1600, 900);
	//Glyswen
	game.Start("FirstScene", 120, 1600, 900);
	game.Start("VillageToBackery", 120, 1600, 900);
	return 0;
}

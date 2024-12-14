// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/LOG.hpp"
#include "Character/Backpack.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/Settings.hpp"
#include "Scene/PauseScene.hpp"
#include "Scene/Map.hpp"
#include "Scene/Act1/Glyswen/FirstScene.hpp"
#include "Scene/Act1/Glyswen/VillageToBackery.hpp"
#include "Scene/Act1/Bakery/Bakery.hpp"
#include "Scene/Act1/Port/PortNarration.hpp"
#include "Scene/Act1/Port/EmeraldGetNarration.hpp"
#include "Scene/Act1/Port/Port.hpp"
#include "Scene/Act1/MushroomFarm/FirstNarration.hpp"
#include "Scene/Act1/MushroomFarm/SecondNarration.hpp"
#include "Scene/Act1/MushroomFarm/MushroomFarm.hpp"
#include "Scene/Act1/Saturday/BakeryNarration.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("StartScene", new StartScene());
	game.AddNewScene("PauseScene", new PauseScene());
	game.AddNewScene("Settings", new Settings());
	game.AddNewScene("Backpack", new Backpack());
	game.AddNewScene("Map", new Map());
	// Glyswen
	game.AddNewScene("FirstScene", new FirstScene());
	game.AddNewScene("VillageToBackery", new VillageToBackery());
	// Bakery
	game.AddNewScene("Bakery", new Bakery());
	// Port
	game.AddNewScene("PortNarration", new PortNarration());
	game.AddNewScene("EmeraldGetNarration", new EmeraldGetNarration());
	game.AddNewScene("Port", new Port());
	// MushroomFarm
	game.AddNewScene("MushroomFarmFirstNarration", new MushroomFarmFirstNarration());
	game.AddNewScene("MushroomFarmSecondNarration", new MushroomFarmSecondNarration());
	game.AddNewScene("MushroomFarm", new MushroomFarm());
	// Saturday
	game.AddNewScene("BakeryNarration", new BakeryNarration());

	game.Start("StartScene", 120, 1600, 900);
	game.Start("PauseScene", 120, 1600, 900);
	game.Start("Settings", 120, 1600, 900);
	game.Start("Backpack", 120, 1600, 900);
	game.Start("Map", 120, 1600, 900);
	// Glyswen
	game.Start("FirstScene", 120, 1600, 900);
	game.Start("VillageToBackery", 120, 1600, 900);
	// Bakery
	game.Start("Bakery", 120, 1600, 900);
	// Port
	game.Start("PortNarration", 120, 1600, 900);
	game.Start("EmeraldGetNarration", 120, 1600, 900);
	game.Start("Port", 120, 1600, 900);
	// MushroomFarm
	game.Start("MushroomFarmFirstNarration", 120, 1600, 900);
	game.Start("MushroomFarmSecondNarration", 120, 1600, 900);
	game.Start("MushroomFarm", 120, 1600, 900);
	// Saturday
	game.Start("BakeryNarration", 120, 1600, 900);
	return 0;
}

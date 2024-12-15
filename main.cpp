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
#include "Scene/Achievement.hpp"
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
#include "Scene/Act1/Saturday/HideawayNarration.hpp"
#include "Scene/Act1/Sunday/FirstSundayNarration.hpp"
#include "Scene/Act2/Monday/Act2MondayNarration.hpp"
#include "Scene/Act2/Tuesday/Act2TuesdayFirstNarration.hpp"
#include "Scene/Act2/Tuesday/TuesdayBakery.hpp"
#include "Scene/Act2/Tuesday/Act2TuesdaySecondNarration.hpp"
#include "Scene/Act2/Wednesday/Act2WednesdayNarration.hpp"
#include "Scene/Act2/Thursday/Act2ThursdayNarration.hpp"
#include "Scene/Act2/Friday/Act2FridayNarration.hpp"
#include "Scene/Act2/Saturday/Act2SaturdayNarration.hpp"
#include "Scene/Ending/Ending.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("StartScene", new StartScene());
	game.AddNewScene("PauseScene", new PauseScene());
	game.AddNewScene("Achievement", new Achievement());
	game.AddNewScene("Settings", new Settings());
	game.AddNewScene("Backpack", new Backpack());
	game.AddNewScene("Map", new Map());
	// Act 1
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
	game.AddNewScene("HideawayNarration", new HideawayNarration());
	// Sunday
	game.AddNewScene("FirstSundayNarration", new FirstSundayNarration());
	// Act 2
	// Monday
	game.AddNewScene("Act2MondayNarration", new Act2MondayNarration());
	// Tuesday
	game.AddNewScene("Act2TuesdayFirstNarration", new Act2TuesdayFirstNarration());
	game.AddNewScene("TuesdayBakery", new TuesdayBakery());
	game.AddNewScene("Act2TuesdaySecondNarration", new Act2TuesdaySecondNarration());
	// Wednesday
	game.AddNewScene("Act2WednesdayNarration", new Act2WednesdayNarration());
	// Thursday
	game.AddNewScene("Act2ThursdayNarration", new Act2ThursdayNarration());
	// Friday
	game.AddNewScene("Act2FridayNarration", new Act2FridayNarration());
	// Saturday
	game.AddNewScene("Act2SaturdayNarration", new Act2SaturdayNarration());
	// Ending
	game.AddNewScene("Ending", new Ending());

	game.Start("StartScene", 120, 1600, 900);
	game.Start("PauseScene", 120, 1600, 900);
	game.Start("Achievement", 120, 1600, 900);
	game.Start("Settings", 120, 1600, 900);
	game.Start("Backpack", 120, 1600, 900);
	game.Start("Map", 120, 1600, 900);
	// Act 1
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
	game.Start("HideawayNarration", 120, 1600, 900);
	// Sunday
	game.Start("FirstSundayNarration", 120, 1600, 900);
	// Act 2
	// Monday
	game.Start("Act2MondayNarration", 120, 1600, 900);
	// Tuesday
	game.Start("Act2TuesdayFirstNarration", 120, 1600, 900);
	game.Start("TuesdayBakery", 120, 1600, 900);
	game.Start("Act2TuesdaySecondNarration", 120, 1600, 900);
	// Wednesday
	game.Start("Act2WednesdayNarration", 120, 1600, 900);
	// Thursday
	game.Start("Act2ThursdayNarration", 120, 1600, 900);
	// Friday
	game.Start("Act2FridayNarration", 120, 1600, 900);
	// Saturday
	game.Start("Act2SaturdayNarration", 120, 1600, 900);
	// Ending
	game.Start("Ending", 120, 1600, 900);
	return 0;
}

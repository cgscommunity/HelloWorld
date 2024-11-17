// DEFINITIONS
///////////////////////////////
#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER

// INCLUDES
///////////////////////////////
#include "Play.h"
#include "Config.h"
#include "GameManager.h"

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	GameManager* gameManager = GameManager::GetGameManager();
	gameManager->Initialise();
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	GameManager* gameManager = GameManager::GetGameManager();
	return gameManager->Update(elapsedTime);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	GameManager* gameManager = GameManager::GetGameManager();
	gameManager->Deinitialise();

	return PLAY_OK;
}
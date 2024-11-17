// This file's header
#include "GameManager.h"

// Other includes
#include "Config.h"
#include "Play.h"
#include "SplashState.h"

// Statics
GameState* GameManager::currentGameState = nullptr;

void GameManager::Initialise()
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Play::LoadBackground("Data\\Backgrounds\\background.png");

	currentGameState = new SplashState();
}

void GameManager::Deinitialise()
{
	Play::DestroyManager();
}

bool GameManager::Update(float elapsedTime)
{
	GameState* newGameState = currentGameState->CheckTransitions();
	if(newGameState)
	{
		delete currentGameState;
		currentGameState = newGameState;
	}

	currentGameState->Update(elapsedTime);
	currentGameState->Draw();

	return false;
}

GameManager* GameManager::GetGameManager()
{
	return nullptr;
}

GameManager::GameManager()
{
	currentGameState = nullptr;
}

GameManager::~GameManager()
{
}

#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

// ENUMERATIONS
///////////////////////////////
enum GameState
{
	SPLASH,
	MAIN_MENU,
	PLAY,
	GAME_OVER
};

enum MainMenuOptions
{
	START,
	OPTIONS,
	QUIT
};

// CONSTANTS
///////////////////////////////
const int DISPLAY_WIDTH = 1280;
const int DISPLAY_HEIGHT = 720;
const int DISPLAY_SCALE = 1;
const float SPLASH_DISPLAY_TIMELIMIT = 2.0f;
const float PLAY_TIMELIMIT = 5.0f;

// VARIABLES
///////////////////////////////
GameState currentGameState = SPLASH;
float stateTimer = 0;
MainMenuOptions currentlySelectedMainMenuOption = START;

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Play::LoadBackground("Data\\Backgrounds\\background.png");
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	switch(currentGameState)
	{
		case SPLASH:
		{
			if(stateTimer < SPLASH_DISPLAY_TIMELIMIT)
			{
				Play::ClearDrawingBuffer(Play::cOrange);
				Play::DrawFontText("72px", "SPLASH", { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2}, Play::CENTRE);
				
				Play::PresentDrawingBuffer();

				stateTimer += elapsedTime;
			}
			else
			{ 
				currentGameState = MAIN_MENU;
				stateTimer = 0.0f;
			}
			
			break;
		}
		case MAIN_MENU:
		{
			Play::ClearDrawingBuffer(Play::cBlack);
			Play::DrawFontText("32px", "START", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) + 50.0f }, Play::LEFT);
			Play::DrawFontText("32px", "OPTIONS", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2)}, Play::LEFT);
			Play::DrawFontText("32px", "QUIT", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) - 50.0f }, Play::LEFT);

			switch(currentlySelectedMainMenuOption)
			{
				case START:
				{
					// Draw arrow next to "Start"
					Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) + 50.0f }, Play::CENTRE);

					// Check for transitions
					if (Play::KeyPressed(Play::KEY_S))
					{
						currentlySelectedMainMenuOption = OPTIONS;
					}
					else if (Play::KeyPressed(Play::KEY_SPACE))
					{
						currentGameState = PLAY;
					}

					break;
				}
				case OPTIONS:
				{
					// Draw arrow next to "Options"
					Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) }, Play::CENTRE);

					if (Play::KeyPressed(Play::KEY_W))
					{
						currentlySelectedMainMenuOption = START;
					}
					else if (Play::KeyPressed(Play::KEY_S))
					{
						currentlySelectedMainMenuOption = QUIT;
					}
					else if (Play::KeyPressed(Play::KEY_SPACE))
					{
						// TODO - We don't have an options screen right now
					}
					break;
				}
				case QUIT:
				{
					// Draw arrow next to "Quit"
					Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) - 50.0f }, Play::CENTRE);

					// Check for transitions
					if (Play::KeyPressed(Play::KEY_W))
					{
						currentlySelectedMainMenuOption = OPTIONS;
					}
					else if (Play::KeyPressed(Play::KEY_SPACE))
					{
						// Quit the game
						return true;
					}
					break;
				}
			}

			Play::PresentDrawingBuffer();

			break;
		}
		case PLAY:
		{
			if (stateTimer < PLAY_TIMELIMIT)
			{
				Play::DrawBackground();
				Play::DrawFontText("72px", "PLAY", { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, Play::CENTRE);

				Play::PresentDrawingBuffer();

				stateTimer += elapsedTime;
			}
			else
			{
				currentGameState = MAIN_MENU;
				stateTimer = 0.0f;
			}

			break;
		}
		default:
		{
			// Invalid state, exit game.
			return true;
		}
	}

	return Play::KeyDown(KEY_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	Play::DestroyManager();
	return PLAY_OK;
}
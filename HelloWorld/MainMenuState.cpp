// This file's header
#include "MainMenuState.h"

// Other includes
#include "Config.h"
#include "Play.h"
#include "PlayState.h"

MainMenuState::MainMenuState()
{
	currentlySelectedOption = START;
}

void MainMenuState::Update(float elapsedTime)
{
	switch (currentlySelectedOption)
	{
		case START:
		{
			// Check for transitions
			if (Play::KeyPressed(Play::KEY_S))
			{
				currentlySelectedOption = OPTIONS;
			}

			break;
		}
		case OPTIONS:
		{
			if (Play::KeyPressed(Play::KEY_W))
			{
				currentlySelectedOption = START;
			}
			else if (Play::KeyPressed(Play::KEY_S))
			{
				currentlySelectedOption = QUIT;
			}

			break;
		}
		case QUIT:
		{
			// Check for transitions
			if (Play::KeyPressed(Play::KEY_W))
			{
				currentlySelectedOption = OPTIONS;
			}

			break;
		}
	}
}

void MainMenuState::Draw()
{
	Play::ClearDrawingBuffer(Play::cBlack);
	Play::DrawFontText("32px", "START", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) + 50.0f }, Play::LEFT);
	Play::DrawFontText("32px", "OPTIONS", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) }, Play::LEFT);
	Play::DrawFontText("32px", "QUIT", { DISPLAY_WIDTH / 2, (DISPLAY_HEIGHT / 2) - 50.0f }, Play::LEFT);

	switch (currentlySelectedOption)
	{
		case START:
		{
			// Draw arrow next to "Start"
			Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) + 50.0f }, Play::CENTRE);
			break;
		}
		case OPTIONS:
		{
			// Draw arrow next to "Options"
			Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) }, Play::CENTRE);
			break;
		}
		case QUIT:
		{
			// Draw arrow next to "Quit"
			Play::DrawFontText("32px", "---->", { (DISPLAY_WIDTH / 2) - 50.0f, (DISPLAY_HEIGHT / 2) - 50.0f }, Play::CENTRE);
			break;
		}
	}

	Play::PresentDrawingBuffer();
}

GameState* MainMenuState::CheckTransitions()
{
	if (Play::KeyPressed(Play::KEY_SPACE))
	{
		if(currentlySelectedOption == START)
		{
			return new PlayState();
		}
		else if(currentlySelectedOption == QUIT)
		{
			//return new QuitState();
		}
	}

	return nullptr;
}

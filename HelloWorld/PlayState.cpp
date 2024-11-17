// This file's header
#include "PlayState.h"

// Other includes
#include "Config.h"
#include "MainMenuState.h"
#include "Play.h"

void PlayState::Update(float elapsedTime)
{
	stateTimer += elapsedTime;
}

void PlayState::Draw()
{
	Play::DrawBackground();
	Play::DrawFontText("72px", "PLAY", { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, Play::CENTRE);

	Play::PresentDrawingBuffer();
}

GameState* PlayState::CheckTransitions()
{
	if (stateTimer > PLAY_TIMELIMIT)
	{
		return new MainMenuState();
	}

	return nullptr;
}

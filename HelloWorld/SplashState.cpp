// This file's header
#include "SplashState.h"

// Other includes
#include "Config.h"
#include "MainMenuState.h"
#include "Play.h"

void SplashState::Update(float elapsedTime)
{
	stateTimer += elapsedTime;
}

void SplashState::Draw()
{
	Play::ClearDrawingBuffer(Play::cOrange);
	Play::DrawFontText("72px", "SPLASH", { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, Play::CENTRE);

	Play::PresentDrawingBuffer();
}

GameState* SplashState::CheckTransitions()
{
	if(stateTimer >= SPLASH_DISPLAY_TIMELIMIT)
	{
		return new MainMenuState();
	}

	return nullptr;
}

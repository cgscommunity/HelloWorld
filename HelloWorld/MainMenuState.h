#pragma once
#include "GameState.h"

class MainMenuState : public GameState
{
	enum MainMenuOption
	{
		START,
		OPTIONS,
		QUIT
	};

public:
	MainMenuState();

	virtual void Update(float elapsedTime) override;
	virtual void Draw() override;
	virtual GameState* CheckTransitions() override;

private:
	MainMenuOption currentlySelectedOption;
};


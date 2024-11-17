#pragma once
#include "GameState.h"
class PlayState : public GameState
{
public:
	virtual void Update(float elapsedTime) override;
	virtual void Draw() override;
	virtual GameState* CheckTransitions() override;
};


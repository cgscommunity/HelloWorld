#pragma once
class GameState
{
public:
	GameState() : stateTimer(0.0f) {}
	virtual ~GameState() {};

	virtual void Update(float elapsedTime) = 0;
	virtual void Draw() = 0;
	virtual GameState* CheckTransitions() = 0;

protected:
	float stateTimer;
};


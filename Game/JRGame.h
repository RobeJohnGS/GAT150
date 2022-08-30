#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class JRGame : public JREngine::Game {
public:
	enum class gameState {
		title,
		start,
		game,
		dead,
		gameOver
	};

	//functions
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(JREngine::Renderer& renderer) override;

	void OnAddPoints(const JREngine::Event& event);
	void OnPlayerDead(const JREngine::Event& event);

private:
	gameState m_gameState = gameState::title;
	float m_stateTimer = 0;
	int m_lives = 3;
};
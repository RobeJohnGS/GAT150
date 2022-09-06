#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class JRGame : public JREngine::Game, public JREngine::INotify {
public:
	enum class gameState {
		title,
		start,
		game,
		battle,
		dead,
		gameOver
	};

	//functions
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(JREngine::Renderer& renderer) override;

	void OnNotify(const JREngine::Event& event) override;
	void OnAddPoints(const JREngine::Event& event);
	void OnPlayerDead(const JREngine::Event& event);

	void OnBattleStart();

private:
	gameState m_gameState = gameState::title;
	bool battleOn = false;
	float m_stateTimer = 0;
	int m_lives = 3;
};
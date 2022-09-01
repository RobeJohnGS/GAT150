#include "JRGame.h"
#include "Engine.h"

void JRGame::Initialize(){
	m_scene = std::make_unique<JREngine::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Scenes/Prefabs.txt", "Scenes/Tilemap.txt", "Scenes/Level.txt" };

	for (auto sceneName : sceneNames) {
		bool success = JREngine::json::Load(sceneName, document);

		if (!success) {
			LOG("Error could not load scene %s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);
	}
	m_scene->Initialize();

	JREngine::eventManager_g.Subscribe("EVENT_ADD_POINTS", std::bind(&JRGame::OnAddPoints, this, std::placeholders::_1));
}

void JRGame::Shutdown(){
	m_scene->RemoveAll();
}

void JRGame::Update(){
	switch (m_gameState) {
	case gameState::title:
	{
		m_scene->GetActorFromName("Title")->SetActive(true);
		m_lives = 3;

		if (JREngine::inputSystem_g.GetKeyState(JREngine::key_space) == JREngine::InputSystem::KeyState::Pressed) {
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::start;
		}
	}
		break;
	case gameState::start:
		for (int i = 0; i < 10; i++) {
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Coin");
			actor->m_transform.position = { JREngine::Randomf(0, 800), 100.0f };

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;
	case gameState::game:
		break;
	case gameState::dead:
		m_stateTimer -= JREngine::time_g.deltaTime;
		if (m_stateTimer <= 0) {
			m_gameState = (m_lives > 0) ? gameState::start : gameState::gameOver;
		}
		break;
	case gameState::gameOver:
		break;
	default:
		break;
	}
	m_scene->Update();
}

void JRGame::Draw(JREngine::Renderer& renderer){
	m_scene->Draw(renderer);
}

void JRGame::OnAddPoints(const JREngine::Event& event){
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void JRGame::OnPlayerDead(const JREngine::Event& event){
	m_gameState = gameState::dead;
	m_lives -= 1;
	m_stateTimer = 3;
}

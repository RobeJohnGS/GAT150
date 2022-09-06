#include "JRGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"
#include <iostream>

void JRGame::Initialize(){
	//REGISTER_CLASS(EnemyComponent);
	JREngine::Factory::Instance().Register<EnemyComponent>("EnemyComponent");

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

void JRGame::Update()
{
	switch (m_gameState)
	{
	case gameState::title:
		m_scene->GetActorFromName("Title")->SetActive(true);
		m_lives = 3;

		if (JREngine::inputSystem_g.GetKeyState(JREngine::key_space) == JREngine::InputSystem::KeyState::Pressed)
		{
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::start;
		}

		break;

	case gameState::start:
		m_scene->GetActorFromName("Score")->SetActive(true);
		m_scene->GetActorFromName("Health")->SetActive(true);

		for (int i = 0; i < 10; i++)
		{
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Coin");
			actor->m_transform.position = { JREngine::Randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		for (int i = 0; i < 1; i++)
		{
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Demon");
			actor->m_transform.position = { JREngine::Randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		{
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Player");
			actor->m_transform.position = { 400.0f, 250.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;

	case gameState::game:
	{
		auto score = m_scene->GetActorFromName("Score");
		auto component = score->GetComponent<JREngine::TextComponent>();
		if (component)
		{
			component->SetText(std::to_string(m_score));
		}
	}
	{
		auto health = m_scene->GetActorFromName("Health");
		auto component = health->GetComponent<JREngine::TextComponent>();
		auto player = m_scene->GetActorFromName("Player");
		if (player)
		{
			auto pcomponent = player->GetComponent<JREngine::PlayerComponent>();
			if (component)
			{
				component->SetText(std::to_string((int)pcomponent->health));
			}

			if (pcomponent->inBattle) {
				m_gameState = gameState::battle;
			}
		}

	}
	break;
	case gameState::battle:
		std::cout << "battle\n";
		if (JREngine::inputSystem_g.GetKeyState(JREngine::key_space) == JREngine::InputSystem::KeyState::Pressed)
		{
			m_gameState = gameState::game;
		}
	break;
	case gameState::dead:

		m_scene->GetActorFromName("Death")->SetActive(true);

		m_stateTimer -= JREngine::time_g.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_scene->GetActorFromName("Death")->SetActive(false);
			m_gameState = (m_lives > 0) ? gameState::start : gameState::gameOver;
		}
		break;

	case gameState::gameOver:
		break;

	default:
		break;
	}

	if (m_gameState != gameState::battle) {
		m_scene->Update();
	}
}

void JRGame::Draw(JREngine::Renderer& renderer){
	m_scene->Draw(renderer);
}

void JRGame::OnNotify(const JREngine::Event& event){
	if (event.name == "EVENT_ADD_POINTS") {
		OnAddPoints(event);
	}

	if (event.name == "EVENT_DAMAGE") {
		OnBattleStart();
	}

	if (event.name == "EVENT_PLAYER_DEAD") {
		OnPlayerDead(event);
	}
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

void JRGame::OnBattleStart(){
	{
		auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Demon");
		actor->m_transform.position = { 600.0f, 250.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
	{
		auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Player");
		actor->m_transform.position = { 400.0f, 250.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}

	m_gameState = gameState::battle;
}

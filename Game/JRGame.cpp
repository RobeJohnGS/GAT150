#include "JRGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"
#include <iostream>

void JRGame::Initialize(){
	//REGISTER_CLASS(EnemyComponent);
	JREngine::Factory::Instance().Register<EnemyComponent>("EnemyComponent");

	srand(time(0));

	m_scene = std::make_unique<JREngine::Scene>();

	JREngine::audioSystem_g.AddAudio("start", "Audio/start.wav");
	JREngine::audioSystem_g.AddAudio("main-music", "Audio/main-music.wav");
	JREngine::audioSystem_g.AddAudio("jump", "Audio/jump.wav");
	JREngine::audioSystem_g.AddAudio("death", "Audio/death.wav");

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Scenes/Level.txt", "Scenes/Prefabs.txt",  "Scenes/Tilemap.txt" };

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
			JREngine::audioSystem_g.PlayAudio("start");
			JREngine::audioSystem_g.PlayAudio("main-music", 0.3f, 1.0f, true);
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::start;
		}

		break;

	case gameState::start:
		m_scene->GetActorFromName("Score")->SetActive(true);
		m_scene->GetActorFromName("Lives")->SetActive(true);
		

		for (int i = 0; i < 11; i++)
		{
			float enemySpawnX[11] = { 64, 320, 420, 64, 500, 64, 700, 44, 440, 240, 150 };
			float enemySpawnY[11] = { 600, 600, 470, 410, 280, 190, 120, 90, 60, 0, 0};
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Demon");
			actor->m_transform.position = { (float)enemySpawnX[i], (float)enemySpawnY[i] };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		{
			auto actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Player");
			actor->m_transform.position = { 100.0f, 500.0f };
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
			component->SetText("Score: " + std::to_string(m_score));
		}
	}
	{
		auto lives = m_scene->GetActorFromName("Lives");
		auto component = lives->GetComponent<JREngine::TextComponent>();
		auto player = m_scene->GetActorFromName("Player");
		if (player)
		{
			auto pcomponent = player->GetComponent<JREngine::PlayerComponent>();
			if (component)
			{
				component->SetText("Lives: " + std::to_string((int)m_lives));
			}

			if (pcomponent->inBattle) {
				OnBattleStart();
				m_gameState = gameState::battle;
			}
		}

		if (m_lives == 0) {
			m_gameState = gameState::gameOver;
		}

	}
	break;
	case gameState::battle:
		if (JREngine::inputSystem_g.GetKeyState(JREngine::key_space) == JREngine::InputSystem::KeyState::Pressed) {
			auto rollStart = m_scene->GetActorFromName("Roll-Start");
			rollStart->SetActive(false);
			int playerRoll = JREngine::Random(1, 20);
			auto playerRollActor = m_scene->GetActorFromName("Player-Roll");
			playerRollActor->SetActive(true);
			auto playerRollComp = playerRollActor->GetComponent<JREngine::TextComponent>();
			playerRollComp->SetText("Player: " + std::to_string(playerRoll));
			
			int enemyRoll = JREngine::Random(1, 20);
			auto enemyRollActor = m_scene->GetActorFromName("Enemy-Roll");
			enemyRollActor->SetActive(true);
			auto enemyRollComp = enemyRollActor->GetComponent<JREngine::TextComponent>();
			enemyRollComp->SetText("Enemy: " + std::to_string(enemyRoll));

			auto resultRoll = m_scene->GetActorFromName("Result-Roll");
			resultRoll->SetActive(true);
			auto resultRollT = resultRoll->GetComponent<JREngine::TextComponent>();

			if (enemyRoll > playerRoll) {
				m_lives -= 1;
				resultRollT->SetText("Enemy Win!");
				if (m_lives <= 0) {
					JREngine::audioSystem_g.PlayAudio("death");
					m_gameState = gameState::gameOver;
				}
			}
			else if (playerRoll > enemyRoll) {
				AddPoints(100);
				resultRollT->SetText("Player Win!");
			}
			else {
				resultRollT->SetText("TIE?!");
			}
		}

		if (JREngine::inputSystem_g.GetKeyState(JREngine::key_E) == JREngine::InputSystem::KeyState::Pressed)
		{
			auto playerRollActor = m_scene->GetActorFromName("Player-Roll");
			playerRollActor->SetActive(false);
			auto enemyRollActor = m_scene->GetActorFromName("Enemy-Roll");
			enemyRollActor->SetActive(false);
			auto resultRoll = m_scene->GetActorFromName("Result-Roll");
			resultRoll->SetActive(false);

			auto player = m_scene->GetActorFromName("Player");
			auto pcomponent = player->GetComponent<JREngine::PlayerComponent>();
			pcomponent->inBattle = false;
			pcomponent->canMove = true;

			

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
		m_scene->GetActorFromName("Death")->SetActive(true);
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

	if (event.name == "EVENT_DAMAGE")
	{
		std::cout << "hit\n";
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
		auto rollStart = m_scene->GetActorFromName("Roll-Start");
		rollStart->SetActive(true);
	}
}

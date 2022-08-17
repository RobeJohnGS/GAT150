#include "Engine.h"
#include "Math/MathUtils.h"
#include <iostream>

int main()
{
	JREngine::InitializeMemory();

	JREngine::SetFilePath("../Assets");

	JREngine::renderer_g.Initialize();
	JREngine::inputSystem_g.Initialize();
	JREngine::audioSystem_g.Initialize();
	JREngine::resourceManager_g.Initialize();

	JREngine::Engine::Instance().Register();
	
	JREngine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	JREngine::renderer_g.SetClearColor(JREngine::Color{ 0, 0, 0, 255 });

	//Scene creation
	JREngine::Scene scene;

	//rapidjson::Document document;
	//bool success = JREngine::json::Load(

	//Scene.Read(document);
	
	//load assets
	//Texture
	/*std::shared_ptr<JREngine::Texture> texture = std::make_shared<JREngine::Texture>();
	texture->Create(JREngine::renderer_g, "Sprites/spaceShips_004.png");*/
	std::shared_ptr<JREngine::Texture> texture = JREngine::resourceManager_g.Get<JREngine::Texture>("Sprites/spaceShips_004.png", &JREngine::renderer_g);
	//Model
	/*std::shared_ptr<JREngine::Model> model = std::make_shared<JREngine::Model>();
	model->Create("Text-Models/Player.txt");*/
	//Audio
	JREngine::audioSystem_g.AddAudio("lazer", "Audio/temp-lazer.wav");

	//actor component
	JREngine::Transform transform{ JREngine::Vector2{400, 300}, 90, {3, 3} };
	//std::unique_ptr<JREngine::Actor> actor = std::make_unique<JREngine::Actor>(transform);
	std::unique_ptr <JREngine::Actor> actor = JREngine::Factory::Instance().Create<JREngine::Actor>("Actor");
	actor->transform_ = transform;
	//Player component
	std::unique_ptr<JREngine::Component> playerComponent = JREngine::Factory::Instance().Create<JREngine::Component>("Player");
	actor->AddComponent(std::move(playerComponent));
	//Sprite component
	/*std::unique_ptr<JREngine::SpriteComponent> sprComponent = std::make_unique<JREngine::SpriteComponent>();
	sprComponent->texture_ = texture;
	actor->AddComponent(std::move(sprComponent));*/
	//Model Component
	std::unique_ptr<JREngine::ModelComponent> modelComponent = std::make_unique<JREngine::ModelComponent>();
	modelComponent->m_model = JREngine::resourceManager_g.Get<JREngine::Model>("Text-Models/Player.txt");
	actor->AddComponent(std::move(modelComponent));
	//Audio component
	std::unique_ptr<JREngine::AudioComponent> acomponent = std::make_unique<JREngine::AudioComponent>();
	actor->AddComponent(std::move(acomponent));
	//Physics component
	std::unique_ptr<JREngine::PhysicsComponent> phcomponent = std::make_unique<JREngine::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));
	//Child component broken
	//JREngine::Transform transformC{ JREngine::Vector2{40, 30}, 0, {1, 1} };
	//std::unique_ptr<JREngine::Actor> child = std::make_unique<JREngine::Actor>(transformC);
	////Child Model
	//std::unique_ptr<JREngine::ModelComponent> modelComponentC = std::make_unique<JREngine::ModelComponent>();
	//modelComponentC->m_model = JREngine::resourceManager_g.Get<JREngine::Model>("Text-Models/Player.txt");
	//child->AddComponent(std::move(modelComponentC));
	//actor->AddChild(std::move(child));

	scene.Add(move(actor));



	bool quit = false;
	while (!quit)
	{
		// Update
		JREngine::time_g.Tick();
		JREngine::inputSystem_g.Update();
		JREngine::audioSystem_g.Update();

		if (JREngine::inputSystem_g.onKeyEsc(JREngine::InputSystem::KeyState::Pressed)) {
			quit = true;
		}

		//angle += 360.0f * time_g;

		scene.Update();

		// Render
		JREngine::renderer_g.BeginFrame();

		//JREngine::renderer_g.Draw(texture, { 400, 300 }, angle, { 2.0f, 2.0f }, { 0.5f, 0.5f });
		scene.Draw(JREngine::renderer_g);

		JREngine::renderer_g.EndFrame();
	}

	JREngine::inputSystem_g.Shutdown();
	JREngine::audioSystem_g.Shutdown();
	JREngine::renderer_g.Shutdown();
}
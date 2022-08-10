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
	
	JREngine::audioSystem_g.AddAudio("lazer", "Audio/temp-lazer.wav");

	JREngine::renderer_g.CreateWindow("Engine", 800, 600); // Creates the window with parameters
	JREngine::renderer_g.SetClearColor(JREngine::Color{ 0, 0, 0, 255 });
	
	std::shared_ptr<JREngine::Texture> texture = std::make_shared<JREngine::Texture>();
	texture->Create(JREngine::renderer_g, "Sprites/spaceShips_004.png");
	float angle = 0;

	JREngine::Scene scene;
	std::unique_ptr<JREngine::Actor> actor = std::make_unique<JREngine::Actor>();
	//Player component
	std::unique_ptr<JREngine::PlayerComponent> playerComponent = std::make_unique<JREngine::PlayerComponent>();
	actor->AddComponent(std::move(playerComponent));
	//Sprite component
	std::unique_ptr<JREngine::SpriteComponent> sprComponent = std::make_unique<JREngine::SpriteComponent>();
	sprComponent->texture_ = texture;
	actor->AddComponent(std::move(sprComponent));
	//Audio component
	std::unique_ptr<JREngine::AudioComponent> acomponent = std::make_unique<JREngine::AudioComponent>();
	actor->AddComponent(std::move(acomponent));
	//Physics component
	std::unique_ptr<JREngine::PhysicsComponent> phcomponent = std::make_unique<JREngine::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));

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

		//angle += 1;

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
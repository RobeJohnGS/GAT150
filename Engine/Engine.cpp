#include "Engine.h"

namespace JREngine
{
	Renderer renderer_g;
	InputSystem inputSystem_g;
	
	AudioSystem audioSystem_g;
	
	Time time_g;
	
	ResourceManager resourceManager_g;

	PhysicsSystem physicsSystem_g;

	EventManager eventManager_g;

	void Engine::Register(){
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TilemapComponent);
	}
}
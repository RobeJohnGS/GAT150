#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Initialize(){
		auto comp = m_owner->GetComponent<CollisionComponent>();
		if (comp) {
			comp->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			comp->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update() {
		Vector2 direction = Vector2::zero;
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held) {
			direction = Vector2::left;
		}

		if (JREngine::inputSystem_g.GetKeyState(key_D) == JREngine::InputSystem::Held) {
			direction = Vector2::right;
		}

		auto pComponent = m_owner->GetComponent<PhysicsComponent>();
		if (pComponent) {
			pComponent->ApplyForce(direction * speed);
		}


		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed) {
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component) {
				component->ApplyForce(Vector2::up * 500);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, speed);

		return true;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other){
		if (other->GetName() == "Coin") {
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;
			eventManager_g.Notify(event);

			other->SetDestroy();
		}

		std::cout << "Player enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other){
		std::cout << "Player exit\n";
	}
}

#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Update() {
		Vector2 direction = Vector2::zero;
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {-10, 0};
			direction = Vector2::left;
			m_owner->transform_.rotation += 100 * time_g.deltaTime;
		}

		if (JREngine::inputSystem_g.GetKeyState(key_D) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {10, 0};
			m_owner->transform_.rotation -= 100 * time_g.deltaTime;
		}

		float thrust = 0;
		if (JREngine::inputSystem_g.GetKeyState(key_W) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {0, -10};
			thrust = 100;
		}


		if (JREngine::inputSystem_g.GetKeyState(key_S) == JREngine::InputSystem::Held) {
			//m_owner->transform_.position += {0, 10};
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->transform_.rotation)) * thrust;
			component->ApplyForce(force);

			force = (Vector2{ 400, 300 } - m_owner->transform_.position).Normalized() * 60.0f;
			component->ApplyForce(force);
		}

		m_owner->transform_.position += direction * 300 * time_g.deltaTime;

		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed) {
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component) {
				component->Play();
			}
		}
	}
}

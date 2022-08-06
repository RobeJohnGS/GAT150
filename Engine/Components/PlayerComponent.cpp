#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace JREngine {
	void PlayerComponent::Update() {
		if (JREngine::inputSystem_g.GetKeyState(key_A) == JREngine::InputSystem::Held) {
			m_owner->transform_.position += {-10, 0};
		}

		if (JREngine::inputSystem_g.GetKeyState(key_D) == JREngine::InputSystem::Held) {
			m_owner->transform_.position += {10, 0};
		}

		if (JREngine::inputSystem_g.GetKeyState(key_W) == JREngine::InputSystem::Held) {
			m_owner->transform_.position += {0, -10};
		}

		if (JREngine::inputSystem_g.GetKeyState(key_S) == JREngine::InputSystem::Held) {
			m_owner->transform_.position += {0, 10};
		}
	}
}

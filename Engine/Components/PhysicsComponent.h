#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace JREngine {
	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;
		~PhysicsComponent() = default;

		void Update() override;

		void ApplyForce(const Vector2& force) {
			acceleration += force;
		}

		//Variables
		Vector2 velocity;
		Vector2 acceleration;

		float m_damping = 1;
	};
}
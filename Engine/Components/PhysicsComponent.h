#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace JREngine {
	class Actor;

	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;
		~PhysicsComponent() = default;

		CLASS_DECLARATION(PhysicsComponent)

		void Update() override;
		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);

		void ApplyForce(const Vector2& force) {
			acceleration += force;
		}

		//Variables
		Vector2 velocity;
		Vector2 acceleration;

		float m_damping = 1;
	};
}
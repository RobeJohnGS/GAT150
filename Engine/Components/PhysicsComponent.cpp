#include "PhysicsComponent.h"
#include "Engine.h"

namespace JREngine {
	void PhysicsComponent::Update(){
		velocity += acceleration * time_g.deltaTime;
		m_owner->transform_.position += velocity * time_g.deltaTime;
		velocity *= m_damping;

		acceleration = Vector2::zero;
	}
}
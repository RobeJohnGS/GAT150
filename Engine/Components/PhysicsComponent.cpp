#include "PhysicsComponent.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include "Math/Vector2.h"

namespace JREngine {
	void PhysicsComponent::Update(){
		velocity += acceleration * time_g.deltaTime;
		m_owner->m_transform.position += velocity * time_g.deltaTime;
		velocity *= m_damping;

		acceleration = Vector2::zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const{
		return false;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, m_damping);
		READ_DATA(value, velocity);
		READ_DATA(value, acceleration);

		return true;
	}
}
#include "PhysicsComponent.h"
#include "Engine.h"

namespace JREngine {
	void PhysicsComponent::Update(){
		velocity += acceleration * time_g.deltaTime;
		m_owner->m_transform.position += velocity * time_g.deltaTime;
		velocity *= damping;

		acceleration = Vector2::zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const{
		return false;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, damping);
		READ_DATA(value, velocity);
		READ_DATA(value, acceleration);

		return true;
	}
}
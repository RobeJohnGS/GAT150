#include "RBPhysicsComponent.h"
#include "Engine.h"

namespace JREngine {
	RBPhysicsComponent::~RBPhysicsComponent(){
		if (m_body) {
			physicsSystem_g.DestroyBody(m_body);
		}
	}

	void JREngine::RBPhysicsComponent::Initialize(){
		m_body = physicsSystem_g.CreateBody(m_owner->m_transform.position, m_owner->m_transform.rotation, data);
		m_body->SetGravityScale(data.gravity_scale);
		m_body->SetLinearDamping(m_damping);
	}

	void JREngine::RBPhysicsComponent::Update(){
		Vector2 pos = B2VEC2_TO_VECTOR2(m_body->GetPosition());
		m_owner->m_transform.position = PhysicsSystem::worldToScreen(pos);
		m_owner->m_transform.rotation = Math::RadToDeg(m_body->GetAngle());
	}

	bool JREngine::RBPhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool JREngine::RBPhysicsComponent::Read(const rapidjson::Value& value)
	{
		PhysicsComponent::Read(value);

		READ_DATA(value, data.gravity_scale);
		READ_DATA(value, data.constrain_angle);
		READ_DATA(value, data.is_dynamic);

		return true;
	}
}
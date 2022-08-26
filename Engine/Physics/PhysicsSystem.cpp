#include "PhysicsSystem.h"
#include "Math/MathUtils.h"

namespace JREngine {
	const float PhysicsSystem::pixelsPerUnit = 48;

	void PhysicsSystem::Initialize(){
		b2Vec2 gravity{ 0, 10 };
		m_world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown(){

	}

	void PhysicsSystem::Update(){

	}

	b2Body* PhysicsSystem::CreateBody(const Vector2& pos, float angle, const RigidBodyData& data)
	{
		Vector2 worldPos = screenToWorld(pos);

		b2BodyDef bodyDef;
		bodyDef.type = (data.is_dynamic) ? b2_dynamicBody : b2_staticBody;
		bodyDef.position = *((b2Vec2*)(&worldPos));

	}

	void PhysicsSystem::SetCollisionBox(b2Body* body, const CollisionData& data, Actor* actor){

	}

	void PhysicsSystem::DestroyBody(b2Body* body){

	}
}
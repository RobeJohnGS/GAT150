#include "SpriteComponent.h"
#include "Framework/Actor.h"
#include "Renderer/Renderer.h"
#include "Engine.h"

namespace JREngine {
	void SpriteComponent::Update() {
		//nothing here
	}

	void SpriteComponent::Draw(Renderer& renderer){
		renderer.Draw(m_texture, GetSource(), m_owner->m_transform);
	}

	bool SpriteComponent::Write(const rapidjson::Value& value) const{
		return true;
	}

	bool SpriteComponent::Read(const rapidjson::Value& value){
		std::string texture_name;
		READ_DATA(value, texture_name);

		m_texture = resourceManager_g.Get<Texture>(texture_name, renderer_g);

		if (!READ_DATA(value, source)) {
			source.x = 0;
			source.y = 0;
			source.w = (int)m_texture->GetSize().x;
			source.h = (int)m_texture->GetSize().y;
		}

		return true;
	}
}
#include "SpriteComponent.h"
#include "Framework/Actor.h"
#include "Renderer/Renderer.h"

namespace JREngine {
	void SpriteComponent::Update() {
		//nothing here
	}

	void SpriteComponent::Draw(Renderer& renderer){
		renderer.Draw(texture_, m_owner->transform_);
	}
}
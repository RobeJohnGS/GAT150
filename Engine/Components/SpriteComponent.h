#pragma once
#include "RendererComponent.h"

namespace JREngine {
	class Texture;

	class SpriteComponent : public RendererComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> texture_;
	};
}
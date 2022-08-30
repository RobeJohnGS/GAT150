#pragma once
#include "RendererComponent.h"
#include "Math/Rect.h"

namespace JREngine {
	class Texture;

	class SpriteComponent : public RendererComponent {
	public:
		CLASS_DECLARATION(SpriteComponent)
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);

		std::shared_ptr<Texture> m_texture;
	};
}
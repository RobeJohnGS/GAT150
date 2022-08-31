#pragma once
#include "RendererComponent.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include <memory>

namespace JREngine {
	class Font;
	class Texture;

	class TextComponent : public RendererComponent {
	public:
		CLASS_DECLARATION(TextComponent)

		// Inherited via RendererComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		void SetText(const std::string& text);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		//variables
		std::string text;
		std::string fontName;
		int fontSize;
		Vector2 registration;
		Color color;

		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture> m_texture;
	};
}
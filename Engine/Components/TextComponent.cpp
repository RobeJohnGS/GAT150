#include "TextComponent.h"
#include "Engine.h"

namespace JREngine {
	void TextComponent::Update() {
		//nothing
	}

	void TextComponent::Draw(Renderer& renderer) {
		renderer_g.Draw(m_texture, m_owner->m_transform, registration);
	}

	void TextComponent::SetText(const std::string& text){
		m_texture->CreateFromSurface(m_font->CreateSurface(text, color), renderer_g);
	}

	bool TextComponent::Write(const rapidjson::Value& value) const{
		return true;
	}

	bool TextComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, text);
		READ_DATA(value, font_name);
		READ_DATA(value, font_size);
		READ_DATA(value, registration);
		READ_DATA(value, color);

		m_font = resourceManager_g.Get<Font>(font_name, font_size);

		m_texture = std::make_unique<Texture>();

		SetText(text);

		return true;
	}
}
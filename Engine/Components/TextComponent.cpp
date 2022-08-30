#include "TextComponent.h"
#include "Engine.h"

namespace JREngine {
	void TextComponent::Update() {
		//nothing
	}

	void TextComponent::Draw(Renderer& renderer) {
		renderer_g.Draw(m_texture, m_owner->m_transform, registration);
	}

	bool TextComponent::Write(const rapidjson::Value& value) const{
		return true;
	}

	bool TextComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, text);
		READ_DATA(value, fontName);
		READ_DATA(value, fontSize);
		READ_DATA(value, registration);
		READ_DATA(value, color);

		m_font = resourceManager_g.Get<Font>(fontName, fontSize);

		m_texture = std::make_unique<Texture>();

		//titties
		//SetText(text);

		return true;
	}
}
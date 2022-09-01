#pragma once
#include "RendererComponent.h"
#include "Math/Rect.h"
#include <map>

namespace JREngine {
	class Texture;

	class SpriteAnimComponent : public RendererComponent {
	public:
		CLASS_DECLARATION(SpriteAnimComponent)

		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		//bit assignemtn
		Rect& GetSource() override;

		virtual void Draw(Renderer& renderer) override;

	public:
		std::string name;

		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;

		int frame = 0;
		float frameTimer = 0;

		bool loop = true;

		std::shared_ptr<Texture> texture;
	};
}
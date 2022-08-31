#include "SpriteAnimComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace JREngine {
	void SpriteAnimComponent::Update(){
		frameTimer += time_g.deltaTime;
		if (frameTimer >= 1.0f / fps) {
			frameTimer = 0;
			frame++;
			if (frame > end_frame) {
				frame = start_frame;
			}
		}
	}

	bool SpriteAnimComponent::Write(const rapidjson::Value& value) const{
		return false;
	}

	bool SpriteAnimComponent::Read(const rapidjson::Value& value){
		std::string textureName;
		READ_DATA(value, textureName);

		m_texture = resourceManager_g.Get<Texture>(textureName, renderer_g);

		READ_DATA(value, fps);
		READ_DATA(value, num_columns);
		READ_DATA(value, num_rows);
		READ_DATA(value, start_frame);
		READ_DATA(value, end_frame);
		
		return true;
	}

	//bit assignment
	Rect& SpriteAnimComponent::GetSource(){
		Vector2 cellSize = m_texture->GetSize() / Vector2{ num_columns, num_rows };

		int column = (frame - 1) % num_columns;
		int row = (frame - 1) / num_columns;

		source.x = (int)(column * cellSize.x);
		source.y = (int)(row * cellSize.y);
		source.w = (int)(cellSize.x);
		source.h = (int)(cellSize.y);

		return source;
	}

	void SpriteAnimComponent::Draw(Renderer& renderer){
		renderer.Draw(m_texture, GetSource(), m_owner->m_transform);
	}
}
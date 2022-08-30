#include "TilemapComponent.h"
#include "Engine.h"

namespace JREngine {

	void TilemapComponent::Initialize(){
		for (int i = 0; i < tiles.size(); i++) {
			int index = tiles[i];
			if (index == 0) {
				continue;
			}

			auto actor = Factory::Instance().Create<Actor>(tileNames[index]);
			if (actor) {
				int x = i % num_columns;
				int y = i / num_columns;

				actor->m_transform.position = m_owner->m_transform.position + (Vector2{ x, y } * size);
				//titties
				//m_owner->GetScene()->AddActor(std::move(actor));
			}
		}
	}

	void TilemapComponent::Update(){

	}

	bool TilemapComponent::Write(const rapidjson::Value& value) const{
		return false;
	}

	bool TilemapComponent::Read(const rapidjson::Value& value){
		READ_DATA(value, num_columns);
		READ_DATA(value, num_rows);
		READ_DATA(value, size);
		READ_DATA(value, tileNames);
		READ_DATA(value, tiles);

		return true;
	}
}

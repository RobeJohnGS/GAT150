#pragma once
#include "Framework/Component.h"
#include "Math/Rect.h"
#include "Math/Vector2.h"

namespace JREngine {
	class Renderer;

	class RendererComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() {
			return source;
		}

		void SetFlipH(bool flip = true) {
			flipHorizontal = flip;
		}

		bool GetFlipH() {
			return flipHorizontal;
		}

	protected:
		//bit assignment
		Rect source;
		Vector2 registration = Vector2{ 0.5f, 0.5f };
		bool flipHorizontal = false;
	};
}
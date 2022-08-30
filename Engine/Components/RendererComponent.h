#pragma once
#include "Framework/Component.h"
#include "Math/Rect.h"

namespace JREngine {
	class Renderer;

	class RendererComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() {
			return source;
		}

		void SetFlipH(bool flip = true) {
			flipH = flip;
		}

	protected:
		Rect source;
		//8/30/22
		bool flipH = false;
	};
}
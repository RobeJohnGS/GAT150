#pragma once
#include "Math/Vector2.h"
#include <string>
//Not supposed to be here
#include "Renderer/Renderer.h"

//Forward Declaration
struct SDL_Texture;
//class Renderer;

namespace JREngine {
	class Texture {
	public:
		Texture() = default;
		~Texture();

		bool Create(Renderer& renderer, const std::string& filename);

		Vector2 GetSize() const;

		friend class Renderer;
	private:
		SDL_Texture* m_texture = nullptr;
	};
}
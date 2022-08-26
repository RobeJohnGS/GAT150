#pragma once
#include "Math/Vector2.h"
#include "Resource/Resource.h"
#include <string>

//Forward Declaration
struct SDL_Texture;

namespace JREngine {
	class Renderer;
	class Texture : public Resource {
	public:
		Texture() = default;
		~Texture();

		bool Create(const std::string& filename, ...) override;
		bool Create(Renderer& renderer, const std::string& filename);

		Vector2 GetSize() const;

		//friend class Renderer;
		SDL_Texture* m_texture = nullptr;
	private:
	};
}
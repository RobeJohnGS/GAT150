#pragma once
#include "Math/Vector2.h"
#include "Resource/Resource.h"
#include <string>

//Forward Declaration
struct SDL_Texture;
struct SDL_Surface;

namespace JREngine {
	class Renderer;
	class Texture : public Resource {
	public:
		Texture() = default;
		~Texture();

		bool Create(const std::string filename, ...) override;
		bool CreateFromSurface(SDL_Surface* surface, Renderer& renderer);
		bool Create(Renderer& renderer, const std::string& filename);

		Vector2 GetSize() const;

		//friend class Renderer;
		SDL_Texture* m_texture = nullptr;
	private:
	};
}
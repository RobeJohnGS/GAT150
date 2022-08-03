#include "Texture.h"
#include "Renderer/Renderer.h"
#include <SDL.h>
#include <SDL_image.h>

namespace JREngine {
	Texture::~Texture(){
		if (m_texture != NULL) {
			SDL_DestroyTexture(m_texture);
		}
	}

	bool Texture::Create(Renderer& renderer, const std::string& filename)
	{
		SDL_Surface* surface = IMG_Load();
		return false;
	}


	Vector2 Texture::GetSize() const{
		return Vector2();
	}
}
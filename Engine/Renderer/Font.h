#pragma once
#include "Renderer.h"
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;
struct SDL_Surface;

//Make font a resource
namespace JREngine {
	struct Color;

	class Font : public Resource {
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		//bool Create(const std::string& filename, int& fontSize);
		bool Create(const std::string& filename, ...) override;

		SDL_Surface* CreateSurface(const std::string& str, const Color& color);

		bool Load(const std::string& filename, int fontSize);

		friend class Text;
	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}
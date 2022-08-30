#include "Font.h"
#include "Core/Logger.h"
#include <SDL_ttf.h>

namespace JREngine {
	Font::Font(const std::string& filename, int fontSize) {
		Load(filename, fontSize);
	}

	Font::~Font() {
		if (m_ttfFont != NULL) {
			TTF_CloseFont(m_ttfFont);
		}
	}

	/*bool Font::Create(const std::string& filename, int& fontSize){
		if (!Load(filename, fontSize)) {
			return false;
		}
		return true;
	}*/

	bool Font::Create(const std::string& filename, ...)
	{
		//va_start broken
		/*va_list args;
		va_start(args, filename);
		int& fontSize = va_arg(args, int);
		va_end(args);
		Load(filename, fontSize);*/
		return true;
	}

	SDL_Surface* Font::CreateSurface(const std::string& str, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, str.c_str(), c);

		if (!surface) {
			LOG(SDL_GetError());
		}

		return surface;
	}

	bool Font::Load(const std::string& filename, int fontSize){
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
		if (m_ttfFont == nullptr) {
			return false;
		}
		return true;
	}
}
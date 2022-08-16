#include "Font.h"
#include <SDL_ttf.h>

namespace JREngine {
	bool Font::Create(const std::string& filename, void* data) {
		/*(Renderer*)(data);
		Renderer* renderer = static_cast<Renderer*>(data);
		return Create(*renderer, filename);*/
		va_list args;
		va_start(args, filename);
		Renderer& renderer = va_arg(args, Renderer);
		va_end(args);
		return Create(renderer, filename);
	}

	Font::Font(const std::string& filename, int fontSize){
		Load(filename, fontSize);
	}

	Font::~Font(){
		if (m_ttfFont != NULL) {
			TTF_CloseFont(m_ttfFont);
		}
	}

	void Font::Load(const std::string& filename, int fontSize){
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}
}
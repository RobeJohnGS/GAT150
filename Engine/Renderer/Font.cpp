#include "Font.h"
#include "Renderer.h"
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

	bool Font::Create(const std::string& filename, ...) {
		va_list args;
		va_start(args, filename);
		int fontSize = va_arg(args, int);
		va_end(args);
		return Load(filename, fontSize);
	}

	bool Font::Load(const std::string& filename, int fontSize){
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

		return m_ttfFont;
	}
}
#include "Font.h"
#include "Core/Logger.h"
//#include "Renderer.h"
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

	bool Font::Create(const std::string& filename, int& fontSize){
		if (!Load(filename, fontSize)) {
			return false;
		}
		return true;
	}

	bool Font::Create(const std::string& filename, ...)
	{
		//va_start broken
		/*va_list args;
		va_start(args, filename);
		int& fontSize = va_arg(args, int);
		va_end(args);
		return Create(filename, fontSize);*/
		return false;
	}

	bool Font::Load(const std::string& filename, int fontSize){
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
		if (m_ttfFont == nullptr) {
			return false;
		}
		return true;
	}
}
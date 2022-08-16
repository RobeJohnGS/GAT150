#pragma once
#include <string>
//#include <SDL_ttf.h>

struct _TTF_Font;

//Make font a resource
namespace JREngine {
	class Font : public Resource {
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename, void* data = nullptr) override;
		bool Create(const std::string& filename) {
			return false;
		}
		void Load(const std::string& filename, int fontSize);

		friend class Text;
	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}
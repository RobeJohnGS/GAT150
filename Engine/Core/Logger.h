#pragma once
#ifdef _DEBUG
	#define LOG(format, ...) JREngine::logger_g.Log(format, __VA_ARGS__)
#else
	#define LOG(format, ...) ((void)0)
#endif //_DEBUG

namespace JREngine {
	class Logger {
	public:
		Logger() = default;
		~Logger() = default;

		void Log(const char* format, ...);
	private:

	};

	extern Logger logger_g;
}
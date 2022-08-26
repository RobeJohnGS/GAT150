#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"
#include <string>

namespace JREngine {
	class AudioComponent : public Component {
	public:
		AudioComponent() = default;
		~AudioComponent();

		void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

		//Variables
		AudioChannel m_channel;

		std::string m_soundName;
		bool m_playOnAwake = false;
		bool m_loop = false;
		float m_volume = 1;
		float m_pitch = 1;
	};
}
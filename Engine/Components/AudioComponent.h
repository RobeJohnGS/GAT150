#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"

namespace JREngine {
	class Actor;

	class AudioComponent : public Component {
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

		//Variables
		AudioChannel m_channel;

		std::string sound_name;
		bool play_on_start = false;
		bool loop = false;
		float volume = 1;
		float pitch = 1;
	};
}
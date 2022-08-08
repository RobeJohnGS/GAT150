#include "AudioComponent.h"
#include "Engine.h"

namespace JREngine {
	void AudioComponent::Update(){

	}

	void AudioComponent::Play(){
		audioSystem_g.PlayAudio(m_soundName, m_loop);
	}

	void AudioComponent::Stop(){

	}
}